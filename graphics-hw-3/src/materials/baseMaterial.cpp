#include "baseMaterial.hpp"

Color base::getColor(vec4 &pos)
{
    return this->c;
}

ray base::scatter(ray &inRay, vec4 &pos, vec4 &normal)
{
    float theta = 2 * PI * static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float phi = 2 * PI * static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    vec4 randomDirection;
    randomDirection += normal.normalize();
    randomDirection.x += cos(phi) * sin(theta);
    randomDirection.y += sin(phi) * sin(theta);
    randomDirection.z += cos(theta);
    randomDirection.w = 0;

    ray outRay(pos + normal * EPSILON, randomDirection);
    return outRay;
}