#include "rayTracer.hpp"

Image RayTracer::takePicture(Scene &scene, int camIndex)
{
    Image output;
    Camera cam = (*scene.cameras[camIndex]);
    output.width = cam.width;
    output.height = cam.height;
    for (int i = 0; i < output.width; i++)
    {
        for (int j = 0; j < output.height; j++)
        {
            Color c;
            output.pixels.push_back(c);
        }
    }

    // Start at the top right corner. Go left to right, top to bottom
    for (int j = (cam.height - 1); j >= 0; j--)
    {
        for (int i = 0; i < (cam.width); i++)
        {
            // TODO: rewrite this to get a gradient
            // Color c = Color(float(i) / output.height, float(j) / output.width, float(i) * float(j) / (output.height * output.width));
            Color c = Color(float(i) / output.height, float(j) / output.width, 0);
            output.setPixel(i, j, c);
        }
    }

    return output;
}