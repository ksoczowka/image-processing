#include "src/Image.hpp"

#include <fstream>

#include <iostream>

int main(int argc, char** argv) {
    Image img;
    
    img.openFile("cat.ppm");

    img.createFile();

    img.makeGreyScale();

    img.createFile("newImage2.ppm");


    return 0;
}