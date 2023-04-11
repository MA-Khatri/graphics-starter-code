#ifndef __HIT_H__
#define __HIT_H__

#include "math/ray.hpp"
#include "geometry/geometry.hpp"
#include "materials/material.hpp"
class Geometry;
class Hit {
public:
    float t = 1e12;
    float brightness = 0;

    vec4 pos;
    vec4 modelSpacePos;
    vec4 normal;
    ray inRay;

    Geometry* geometry;

    Material* material;
    Color color = black;
};

inline std::ostream& operator << (std::ostream &os, const Hit &h) {
    os << "time: " << h.t << "\n";
    os << "world space position " << h.pos << "\n";
    os << "model space position " << h.modelSpacePos << "\n";
    os << "normal vector " << h.normal << "\n";
    os << "incident ray " << h.inRay << "\n";
    os << "color: " << h.color << "\n";

    return os;
}

#endif