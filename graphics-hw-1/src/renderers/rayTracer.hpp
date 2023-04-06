#include "../image.hpp"
#include "../scene.hpp"

class RayTracer {
public:
    Image takePicture(Scene & scene, int camIndex);
};