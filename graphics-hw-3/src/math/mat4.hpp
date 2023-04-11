#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cmath>
#include <ostream>
#include "vec4.hpp"
#include "../defines.hpp"

//adapted from https://glmatrix.net/
class mat4 {
public:
    //column major
    float entries [16];
    mat4() {
        setIdentity();
    }

    mat4 transpose();
    mat4 invert();

    float det();

    //return this*b
    mat4 multiply(mat4 & b);

    mat4 translate(const vec4 & v);
    mat4 scale(const vec4 & v);
    //rotate about axis by angle (degrees). Positive means counterclockwise
    mat4 rotate(float angle, const vec4 & axis);

    float &operator[] (int index) {
        return entries[index];
    }

    void setIdentity() {
        for(int i = 0; i < 16; i++) {
            entries[i] = 0;
        }
        entries[0] = 1;
        entries[5] = 1;
        entries[10] = 1;
        entries[15] = 1;
    }

    //return this*v
    vec4 transform(vec4 & v);
};

inline std::ostream& operator << (std::ostream &os, const mat4 &a) {
    //print in row major order
    os << "[" << a.entries[0] << ", " << a.entries[4] << ", " << a.entries[8] << ", " << a.entries[12] << "\n";
    os << a.entries[1] << ", " << a.entries[5] << ", " << a.entries[9] << ", " << a.entries[13] << "\n";
    os << a.entries[2] << ", " << a.entries[6] << ", " << a.entries[10] << ", " << a.entries[14] << "\n";
    os << a.entries[3] << ", " << a.entries[7] << ", " << a.entries[11] << ", " << a.entries[15] << "]";
    
    return os;
}

#endif