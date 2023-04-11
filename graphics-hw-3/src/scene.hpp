#include "camera.hpp"
#include "geometry/geometry.hpp"
#include "geometry/plane.hpp"
#include "geometry/sphere.hpp"

class Scene {
public:
    Color backgroundColor;
    float ambientLight = 0;

    std::vector<Geometry*> items;
    std::vector<Camera*> cameras;
};