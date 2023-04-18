#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

#include "camera.hpp"
#include "renderers/rayTracer.hpp"

int main() {
    int nx = 2000;
    int ny = 2000;

    Scene scene;

    Plane plane;
    groundGrid planeMat;
    plane.setMaterial(planeMat);
    scene.items.push_back(&plane);

    Sphere sphere;
    base sphereMat;
    sphereMat.c = red;
    sphere.setMaterial(sphereMat);
    
    vec4 translate_vec(0,0,0.5,0);
    sphere.translate(translate_vec);

    vec4 scale_vec(.5,.5,.5,0);
    sphere.scale(scale_vec);

    scene.items.push_back(&sphere);

    Camera cam(vec4(-2, 0, 1, 1), 0, 0, nx, ny, .01, 90, 1);
    scene.cameras.push_back(&cam);

    RayTracer rayTracer;
    Image image;

    image = rayTracer.takePicture(scene, 0);

    std::string path = "../data/image.ppm";
    std::ofstream output(path);
    output << image.dump_ppm();
}