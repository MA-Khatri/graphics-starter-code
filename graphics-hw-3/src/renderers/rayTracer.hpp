#include "../image.hpp"
#include "../scene.hpp"
#include "../hit.hpp"

class RayTracer {
public:
    Image takePicture(Scene & scene, int camIndex);
    Hit traceRay(Scene & scene, ray & eyeRay, Hit & hit, int depth);

    void findShade(Scene & scene, Hit & hit, int depth);
};