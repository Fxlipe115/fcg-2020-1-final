#ifndef _TEXTURES_H
#define _TEXTURES_H

class Textures {
    private:
        int loadedTextures;
    public:
        Textures();
        void loadTextureImage(const char* filename);
};

#endif