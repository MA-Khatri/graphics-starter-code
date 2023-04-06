#include "color.hpp"
#include <vector>
#include <string>

class Image {
public:
    int width;
    int height;
    std::vector<Color> pixels;

    Color getPixel(int x,int y);
    void setPixel(int x, int y, Color c);

    std::string dump_ppm(); //write the image to a file (.ppm) https://en.wikipedia.org/wiki/Netpbm
};