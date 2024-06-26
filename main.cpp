#include "src/Image.hpp"

#include <fstream>

#include <iostream>

int main() {
    Image img;
    
    img.openFile("cat.ppm");
    img.makeGreyScale();
    img.createFile("grey-cat.ppm");
    img.closeFile();

    img.openFile("cat.ppm");
    img.makeNegative();
    img.createFile("negative-cat.ppm");
    img.closeFile();

    img.openFile("cat.ppm");
    img.applyFilter(RGB(128, 128, 0));
    img.createFile("filter-cat.ppm");
    img.closeFile();


    return 0;
}