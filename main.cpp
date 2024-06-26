#include "src/Image.hpp"

#include <fstream>

#include <iostream>

int main() {
    Image img;
    
    img.openFile("cat.ppm");
    img.makeGreyScale();
    img.createFile("grey-cat.ppm");

    img.openFile("cat.ppm");
    img.makeNegative();
    img.createFile("negative-cat.ppm");

    img.openFile("cat.ppm");
    img.applyFilter(RGB(255, 255, 0));
    img.createFile("filter-cat.ppm");


    return 0;
}