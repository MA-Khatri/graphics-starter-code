#include <cmath>
#include "vec4.hpp"

vec4 vec4::normalize() {
    return (*this) /= sqrt(this->length_squared());
}
vec4 vec4::cross(vec4 &v) {
    return vec4(y*v.z - v.y*z, v.x*z - x*v.z, x*v.y - v.x*y, 0);
}
float vec4::dot(vec4 &v){
    return x*v.x + y*v.y + z*v.z + w*v.w;
}
float vec4::length_squared() {
    return this->dot(*this);
}

vec4 vec4::operator + (const vec4 & v){
    return vec4(x+v.x, y+v.y, z+v.z, w+v.w);
}
vec4 & vec4::operator += (const vec4 & v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return (*this);
}
vec4 vec4::operator - (const vec4 & v) {
    return vec4(x-v.x, y-v.y, z-v.z, w-v.w);
}
vec4 & vec4::operator -= (const vec4 & v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return (*this);
}
vec4 vec4::operator * (float c){
    return vec4(c*x, c*y, c*z, c*w);
}
vec4 & vec4::operator *= (float c){
    x *= c;
    y *= c;
    z *= c;
    w *= c;
    return (*this);
}
vec4 vec4::operator / (float c) {
    return vec4(x/c, y/c, z/c, w/c);
}
vec4 & vec4::operator /= (float c){
    x /= c;
    y /= c;
    z /= c;
    w /= c;
    return (*this);
}