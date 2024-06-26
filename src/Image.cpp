#include "Image.hpp"

#include <fstream>
#include <iostream>

bool Image::openFile(const std::string& fileName) {
    fileName_ = fileName;
    std::ifstream file;
    
    file.open(fileName_);

    if (!file.is_open()) {
        return false;
    }
    file >> type_;
    file >> width_;
    file >> height_;
    file >> maxRGBValue_;

    int i = 0;
    while(!file.eof()) {
        RGB rgb;
        file >> rgb.red;
        file >> rgb.green;
        file >> rgb.blue;

        image_.push_back(rgb);
    }
    image_.erase(image_.end()); // mandatory! do not remove! without it there is data for one more pixel for some reason
    
    file.close();
    return true;
}
void Image::createFile(const std::string& fileName) {
    std::ofstream file(fileName);

    file << type_ <<'\n';
    file << width_ << ' ' << height_ << '\n';
    file << maxRGBValue_ << '\n';

    for(auto line : image_) {
        file << line.red << ' ' << line.green << ' ' << line.blue << '\n';
    }
}

void Image::applyFilter(const RGB& filter) {
    for (auto& color : image_) {
        color += filter;
        if(color.red > maxRGBValue_) {
            color.red = maxRGBValue_;
        }
        if (color.green > maxRGBValue_) {
            color.green = maxRGBValue_;
        }
        if (color.blue > maxRGBValue_) {
            color.blue = maxRGBValue_;
        }
    }
}

void Image::fill(const RGB& color) {
    while (!image_.empty()) {
        image_.erase(image_.end());
    }
    std::clog << std::boolalpha;
    std::clog << image_.empty() << '\n';
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            image_.push_back(color);
        }
    }
}
void Image::makeGreyScale() {
    for (auto& pixel : image_) {
        pixel = pixel.getLuminosity();
    }
}