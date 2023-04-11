#include "image.hpp"

Color Image::getPixel(int x, int y) {
    return this->pixels[y*width+x];
}

void Image::setPixel(int x, int y, Color c) {
    this->pixels[y*width+x].r = c.r;
    this->pixels[y*width+x].g = c.g;
    this->pixels[y*width+x].b = c.b;
    this->pixels[y*width+x].a = c.a;
}

//write the image to a file (.ppm)
//https://en.wikipedia.org/wiki/Netpbm
std::string Image::dump_ppm() {
    std::string output = "P3\n" + std::to_string(this->width) + " " + std::to_string(this->height) + "\n255\n";
    for(int j = this->height-1; j >= 0; j--) {
        for(int i = 0; i < this->width; i++) {
            Color c = this->getPixel(i,j);
            c.r = 255*c.r;
            c.g = 255*c.g;
            c.b = 255*c.b;

            c.r = c.r > 255 ? 255 : c.r;
            c.g = c.g > 255 ? 255 : c.g;
            c.b = c.b > 255 ? 255 : c.b;

            output += std::to_string(int(c.r)) + " " + std::to_string(int(c.g)) + " " + std::to_string(int(c.b)) + "\n";
        }
    }
    return output;
}