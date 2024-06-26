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

    img.setHeight(500);
    img.setWidth(500);
    img.setType("P3"); // other types are not supported at the moment
    img.setMaxRGBValue(255);
    img.fill(RGB(120, 120, 120));
    img.createFile();
    img.closeFile();

    img.openFile("cat.ppm");
    img.flip180deg();
    img.createFile("flipped-cat.ppm");
    img.closeFile();


    return 0;
}