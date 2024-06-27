#include "Image.hpp"

#include <fstream>

bool Image::openFile(const std::string& fileName) {
    std::ifstream file;
    
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    file >> type_;
    file >> width_;
    file >> height_;
    file >> maxRGBValue_;

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

void Image::makeNegative() {
    for (auto& pixel : image_) {
        pixel = pixel.inverseColor(maxRGBValue_);
    }
}

void Image::closeFile() {
    while (!image_.empty()) {
        image_.erase(image_.end());
    }
    width_ = 0;
    height_ = 0;
    maxRGBValue_ = 0;
    type_ = "";
}

void Image::flip180deg() {
    std::vector<RGB> newImage;
    for (int i = image_.size() - 1; i >= 0; i--) {
        newImage.push_back(image_[i]);
    }
    image_ = newImage;
}

void Image::flip90Right() {
    std::vector<std::vector<RGB>> img = imageToDoubleVector_();
    std::vector<RGB> newImage;


    for (int x = 0; x < width_; x++) {
        for(int y = height_ - 1; y >= 0; y--) {
            newImage.push_back(img[y][x]);
        }
    }
    image_ = newImage;

    int buff = height_;
    height_ = width_;
    width_ = buff;
}

std::vector<std::vector<RGB>> Image::imageToDoubleVector_() {
    std::vector<std::vector<RGB>> ret;
    
    int imageIterator = 0;
    for(int y = 0; y < height_; y++) {
        std::vector<RGB> vec;
        for(int x = 0; x < width_; x++) {
            vec.push_back(image_.at(imageIterator));
            imageIterator++;
        }
        ret.push_back(vec);
    }

    return ret;
}
