#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <cmath>
#include "math/vec4.hpp"
#include "math/ray.hpp"

class Camera {
public:
    vec4 eyePoint;
    vec4 aimPoint;
    vec4 up;

    float panAngle;
    float tiltAngle;

    vec4 uAxis;
    vec4 vAxis;
    vec4 nAxis;

    float left;
    float right;
    float top;
    float bottom;
    float near;

    int width;
    int height;

    float pixelWidth;
    float pixelHeight;

    Camera() {
        eyePoint = vec4(-10, 0, 1, 1);
        aimPoint = vec4(0, 0, 1, 1);
        up = vec4(0, 0, 1, 0);

        left = -1;
        right = 1;
        top = 1;
        bottom = -1;
        near = 1;

        width = 512;
        height = 512;
        pixelWidth = (float)(right - left)/(float)(width);
        pixelHeight = (float)(top - bottom)/(float)(height);
    }
};

#endif