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
    size_t getMaxRGBValue() const { return maxRGBValue_; }
    std::string getType() const { return type_; }

    void setWidth(const size_t& width) { width_ = width; }
    void setHeight(const size_t& height) { height_ = height; }
    void setMaxRGBValue(const size_t& maxRGBValue) { maxRGBValue_ = maxRGBValue; }
    void setType(const std::string& type) { type_ = type; }
    
    // opens ppm file
    bool openFile(const std::string& fileName);

    // creates file from data in object
    void createFile(const std::string& fileName = "newImage.ppm");

    // closes file
    void closeFile();

    // applies filter
    void applyFilter(const RGB& filter);

    // makes blank but specified color image
    void fill(const RGB& color);

    // turns image into gray scale
    void makeGreyScale();

    // turns image into negative
    void makeNegative();

    void flip180deg();

 private:
    size_t width_;
    size_t height_;
    size_t maxRGBValue_;
    std::string type_;
    std::vector<RGB> image_;
};
