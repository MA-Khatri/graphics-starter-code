#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

#include "camera.hpp"
#include "renderers/rayTracer.hpp"

int main() {
    int nx = 400;
    int ny = 400;

    Scene scene;
    Camera cam;
    scene.cameras.push_back(&cam);

    RayTracer rayTracer;
    Image image;

    image = rayTracer.takePicture(scene, 0);

    std::string path = "../data/image.ppm";
    std::ofstream output(path);
    output << image.dump_ppm();
}