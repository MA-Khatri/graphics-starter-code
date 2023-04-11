#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <cmath>
#include "math/vec4.hpp"
#include "math/ray.hpp"
#include "defines.hpp"

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

        setUVN();
    }

    Camera(vec4 eye, float pan, float tilt, int w, int h, float near, float fovy, float aspect): eyePoint(eye), panAngle(pan), tiltAngle(tilt), width(w), height(h) {
        setLookDirection(pan, tilt);
        rayPerspective(fovy, aspect, near);

        pixelWidth = (float)(right - left)/(float)(width);
        pixelHeight = (float)(top - bottom)/(float)(height);
    }

    void setEyePosition(vec4 pos);
    void setLookDirection(float pan, float tilt);

    //define the absolute size of the image plane and its distance from the aperture
    void rayFrustum(float _left, float _right, float _top, float _bottom, float _near);
    void rayPerspective(float fovy, float aspect, float near);

    //return the ray from the camera's aperture to (xPos, yPos) on the near/image plane
    //NB: in the image plane's coordinate system, each pixel is one unit wide by one unit tall
    ray getEyeRay(float xPos, float yPos);

    void setUVN();
};

#endif