#ifndef __GROUND_GRID_H__
#define __GROUND_GRID_H__

#include "material.hpp"

class groundGrid: public Material {
public:
    Color getColor(vec4 & pos);
    ray scatter(ray & inRay, vec4 & pos, vec4 & normal);
};

#endif