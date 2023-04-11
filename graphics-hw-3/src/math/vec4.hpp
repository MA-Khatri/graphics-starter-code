#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <ostream>

class mat4;

class vec4 {
public:
    float x, y, z, w;
    vec4(): x(0), y(0), z(0), w(0) {}
    vec4(float a, float b, float c): x(a), y(b), z(c), w(0) {}
    vec4(float a, float b, float c, float d): x(a), y(b), z(c), w(d) {}

    vec4 normalize();
    vec4 cross(vec4 &v);
    float dot(vec4 &v);
    float length_squared();

    vec4 operator + (const vec4 & v);
    vec4 & operator += (const vec4 & v);
    vec4 operator - (const vec4 & v);
    vec4 & operator -= (const vec4 & v);
    vec4 operator * (float c);
    vec4 & operator *= (float c);
    vec4 operator / (float c);
    vec4 & operator /= (float c);
};

inline std::ostream& operator << (std::ostream &os, const vec4 &t) {
    os << "(" << t.x << ", " << t.y << ", " << t.z << ", " << t.w << ")";
    return os;
}

#endif