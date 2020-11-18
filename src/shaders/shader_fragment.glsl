#version 330 core

// Atributos de fragmentos recebidos como entrada ("in") pelo Fragment Shader.
// Neste exemplo, este atributo foi gerado pelo rasterizador como a
// interpolação da posição global e a normal de cada vértice, definidas em
// "shader_vertex.glsl" e "main.cpp".
in vec4 position_world;
in vec4 normal;

// Posição do vértice atual no sistema de coordenadas local do modelo.
in vec4 position_model;

// Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
in vec2 texcoords;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Identificador que define qual objeto está sendo desenhado no momento
#define SPHERE 1
#define BUNNY  2
#define PLANE  4
uniform int shader_flags;

// Parâmetros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;

// Variáveis para acesso das imagens de textura
uniform sampler2D TextureImage0;
uniform sampler2D TextureImage1;
uniform sampler2D TextureImage2;

// O valor de saída ("out") de um Fragment Shader é a cor final do fragmento.
out vec3 color;

#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    // Obtemos a posição da câmera utilizando a inversa da matriz que define o
    // sistema de coordenadas da câmera.
    vec4 origin = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 camera_position = inverse(view) * origin;

    // O fragmento atual é coberto por um ponto que percente à superfície de um
    // dos objetos virtuais da cena. Este ponto, p, possui uma posição no
    // sistema de coordenadas global (World coordinates). Esta posição é obtida
    // através da interpolação, feita pelo rasterizador, da posição de cada
    // vértice.
    vec4 p = position_world;

    // Normal do fragmento atual, interpolada pelo rasterizador a partir das
    // normais de cada vértice.
    vec4 n = normalize(normal);

    vec4 spotlight = vec4(0.0f,2.0f,1.0f,1.0f);

    // Vetor que define o sentido da fonte de luz em relação ao ponto atual.
    vec4 l = normalize(spotlight - p);

    // Vetor que define o sentido da câmera em relação ao ponto atual.
    vec4 v = normalize(camera_position - p);

    vec4 spotlight_v = normalize(vec4(0.0f,-1.0f,0.0f,0.0f));

    // Vetor que define o sentido da reflexão especular ideal.
    vec4 r = -l + 2*n*dot(n, l);

    // Parâmetros que definem as propriedades espectrais da superfície
    vec3 Kd; // Refletância difusa
    vec3 Ks; // Refletância especular
    vec3 Ka; // Refletância ambiente
    float q; // Expoente especular para o modelo de iluminação de Phong
    vec3 Kd0 = vec3(0.0, 0.0, 0.0);

    // Coordenadas de textura U e V
    float U = 0.0;
    float V = 0.0;
    if((shader_flags & SPHERE) != 0) {
        // PREENCHA AQUI
        // Propriedades espectrais da esfera
        Kd = vec3(1.0,1.0,1.0);
        Ks = vec3(0.8,0.4,0.08);
        Ka = vec3(0.4,0.2,0.04);
        q = 1.0;


        float U = -0.02 + texcoords.x*1.05;
        float V = -2.03 + texcoords.y*4.1;
        float mid = 0.5;
        float rotation = M_PI;
        vec2 coord = vec2(
            cos(rotation) * (U - mid) + sin(rotation) * (V - mid) + mid,
            cos(rotation) * (V - mid) - sin(rotation) * (U - mid) + mid
        );
        //coord = vec2(U,V);
        coord.y = 1 - coord.y;
        Kd0 = texture(TextureImage0, coord).rgb;
    }

    if((shader_flags & BUNNY) != 0) {
        // PREENCHA AQUI
        // Propriedades espectrais do coelho
        Kd = vec3(0.08,0.8,0.4);
        Ks = vec3(0.8,0.8,0.8);
        Ka = vec3(0.4,0.4,0.4);
        q = 32.0;
    }

    if((shader_flags & PLANE) != 0) {
        // PREENCHA AQUI
        // Propriedades espectrais do plano
        Kd = vec3(0.2,0.2,0.2);
        Ks = vec3(0.3,0.3,0.3);
        Ka = vec3(0.0,0.0,0.0);
        q = 20.0;
    }

    if(shader_flags == 0) {
        // Objeto desconhecido = preto
        Kd = vec3(0.0,0.0,0.0);
        Ks = vec3(0.0,0.0,0.0);
        Ka = vec3(0.0,0.0,0.0);
        q = 1.0;
    }

    // Espectro da fonte de iluminação
    vec3 I = vec3(1.0,1.0,1.0); // PREENCH AQUI o espectro da fonte de luz

    // Espectro da luz ambiente
    vec3 Ia = vec3(0.2,0.2,0.2); // PREENCHA AQUI o espectro da luz ambiente

    // Termo difuso utilizando a lei dos cossenos de Lambert
    vec3 lambert_diffuse_term = Kd * I * max(0, dot(n, l)); // PREENCHA AQUI o termo difuso de Lambert

    // Termo ambiente
    vec3 ambient_term = Ka*Ia; // PREENCHA AQUI o termo ambiente

    // Termo especular utilizando o modelo de iluminação de Phong
    vec3 phong_specular_term = Ks * I * pow(max(0, dot(r, v)), q); // PREENCH AQUI o termo especular de Phong

    // Cor final do fragmento calculada com uma combinação dos termos difuso,
    // especular, e ambiente. Veja slide 129 do documento Aula_17_e_18_Modelos_de_Iluminacao.pdf.
    // color = (dot(normalize(p-spotlight), normalize(spotlight_v)) < cos(0.523599f)) ?
    //         ambient_term :
    //         lambert_diffuse_term + ambient_term + phong_specular_term;
    color = Kd0 + lambert_diffuse_term + ambient_term + phong_specular_term;

    // Cor final com correção gamma, considerando monitor sRGB.
    // Veja https://en.wikipedia.org/w/index.php?title=Gamma_correction&oldid=751281772#Windows.2C_Mac.2C_sRGB_and_TV.2Fvideo_standard_gammas
    color = pow(color, vec3(1.0,1.0,1.0)/2.2);
}
