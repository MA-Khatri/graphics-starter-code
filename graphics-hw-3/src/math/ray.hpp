#ifndef __RAY_H__
#define __RAY_H__
#include "vec4.hpp"

class ray {
public:
    vec4 origin;
    vec4 direction;
    float n_i = 1.0;

    ray(): origin(vec4()), direction(vec4()) {

    }
    ray(vec4 o, vec4 dir): origin(o){
        direction = dir.normalize();
    }
};

inline std::ostream& operator << (std::ostream &os, const ray &r) {
    os << "origin: " << r.origin << "\n";
    os << "direction: " << r.direction <<"\n";
    return os;
}

#endif