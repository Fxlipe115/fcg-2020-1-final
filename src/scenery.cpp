#include "scenery.h"

Scenery::Scenery(glm::vec3 size, VirtualScene* virtualScene) {
    floorModel = new ObjectModel("./data/plane.obj");
    floorModel->buildTrianglesAndAddToVirtualScene(virtualScene);
    floor = new ObjectInstance(floorModel);
    floor->setTranslation({0.0f, 0.0f, 0.0f});
    floor->setScale({2.0f, 1.0f, 2.0f});

    walls.push_back(Plane(glm::vec3( 1.0, 0.0,  0.0), size.x/2));
    walls.push_back(Plane(glm::vec3(-1.0, 0.0,  0.0), size.x/2));
    walls.push_back(Plane(glm::vec3( 0.0, 0.0,  1.0), size.z/2));
    walls.push_back(Plane(glm::vec3( 0.0, 0.0, -1.0), size.z/2));
}

Scenery::~Scenery() {
    delete floor;
    delete floorModel;
}

std::vector<Plane>& Scenery::getWalls() {
    return walls;
}

void Scenery::draw(GpuProgram* gpuProgram) {
    floor->draw(gpuProgram, ShaderFlags::PLANE);
}