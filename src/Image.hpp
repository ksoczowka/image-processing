#pragma once

#include "RGB.hpp"

#include <string>
#include <vector>

class Image {
 public:
    Image() : type_("P3"), maxRGBValue_(255) {}
    Image(const Image&);

    size_t getWidth() const { return width_; }
    size_t getHeight() const { return height_; }
    std::string getFileName() const { return fileName_; }

    void setWidth(const size_t& width) { width_ = width; }
    void setHeight(const size_t& height) { height_ = height; }
    
    // opens ppm file
    bool openFile(const std::string& fileName);

    // creates file from data in object
    void createFile(const std::string& fileName = "newImage.ppm");

    // applies filter
    void applyFilter(const RGB& filter);

    // makes blank but specified color image
    void fill(const RGB& color);

    // turns image into gray scale
    void makeGreyScale();

 private:
    size_t width_;
    size_t height_;
    size_t maxRGBValue_;
    std::string type_;
    std::string fileName_;
    std::vector<RGB> image_;
};