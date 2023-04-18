#include "camera.hpp"
#include "geometry/geometry.hpp"
#include "geometry/plane.hpp"
#include "geometry/sphere.hpp"

class Scene {
public:
    Color backgroundColor = white;
    float ambientLight = 0.5;

    std::vector<Geometry*> items;
    std::vector<Camera*> cameras;
};