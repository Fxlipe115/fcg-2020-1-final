#ifndef _LINEARPROJECTILE_H
#define _LINEARPROJECTILE_H

#include "projectile.h"

#include <glm/vec3.hpp>

#include "objectinstance.h"


class LinearProjectile : public Projectile {
    protected:
        glm::vec3 direction;
    public:
        LinearProjectile(ObjectInstance* projectile, int damage, glm::vec3 initialPosition, glm::vec3 direction);
        void move(float speed) override;
};

#endif