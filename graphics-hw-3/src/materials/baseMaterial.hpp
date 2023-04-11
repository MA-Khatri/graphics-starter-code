#ifndef __DIFFUSE_H__
#define __DIFFUSE_H__

#include "material.hpp"

class base: public Material {
public:
    Color c;
    Color getColor(vec4 & pos);
    ray scatter(ray & inRay, vec4 & pos, vec4 & normal);
};

#endif