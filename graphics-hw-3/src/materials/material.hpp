#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../defines.hpp"
#include "../math/vec4.hpp"
#include "../color.hpp"
#include "../math/ray.hpp"
#include <cmath>

//not needed for this assignment
class Material
{
public:
    float brightness = 0;

    virtual Color getColor(vec4 &pos) = 0;
    virtual ray scatter(ray &inRay, vec4 &pos, vec4 &normal) = 0;

    virtual ~Material() {}
};

#endif