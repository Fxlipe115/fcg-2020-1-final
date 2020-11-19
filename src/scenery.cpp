#include "scenery.h"

Scenery::Scenery(glm::vec3 size, VirtualScene* virtualScene)
 : skyColor({0.52f, 0.75f, 0.91f})
{
    floorModel = new ObjectModel("./data/plane.obj");
    floorModel->buildTrianglesAndAddToVirtualScene(virtualScene);
    floor = new ObjectInstance(floorModel);
    floor->setTranslation({0.0f, 0.0f, 0.0f});
    floor->setScale({size.x, 1.0f, size.z});

    walls.push_back(Plane(glm::vec3( 1.0, 0.0,  0.0), size.x));
    walls.push_back(Plane(glm::vec3(-1.0, 0.0,  0.0), size.x));
    walls.push_back(Plane(glm::vec3( 0.0, 0.0,  1.0), size.z));
    walls.push_back(Plane(glm::vec3( 0.0, 0.0, -1.0), size.z));
}

Scenery::~Scenery() {
    delete floor;
    delete floorModel;
}

std::vector<Plane>& Scenery::getWalls() {
    return walls;
}

void Scenery::draw(GpuProgram* gpuProgram) {
    glClearColor(skyColor.r, skyColor.g, skyColor.b, 1.0f);
    floor->draw(gpuProgram, ShaderFlags::PLANE);
}