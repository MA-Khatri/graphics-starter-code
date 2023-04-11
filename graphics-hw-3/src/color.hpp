#ifndef __COLOR_H__
#define __COLOR_H__

#include <ostream>

class Color {
public:
    float r, g, b, a;
    Color(): r(0), g(0), b(0), a(1) {}
    Color(float red, float green, float blue): r(red), g(green), b(blue), a(1) {}
    Color(float red, float green, float blue, float alpha): r(red), g(green), b(blue), a(alpha) {}
};

inline std::ostream& operator << (std::ostream &os, const Color &c) {
    os << "(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
    return os;
}

const Color black(0,0,0);
const Color white(1,1,1);

const Color red(1,0,0);
const Color green(0,1,0);
const Color blue(0,0,1);

#endif