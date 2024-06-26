#pragma once

struct RGB {
    int red = 0;
    int green = 0;
    int blue = 0;

    RGB() {}
    RGB(int r, int g, int b) : red(r), green(g), blue(b) {}

    RGB& operator=(const RGB& other) {
        red = other.red;
        green = other.green;
        blue = other.blue;
        return *this;
    }

    RGB& operator+=(const RGB& other) {
        red += other.red;
        green += other.green;
        blue += other.blue;
        return *this;
    }

    RGB getLuminosity() {
        int grey = red * 0.3f + green * 0.59 + blue * 0.11;
        return RGB(grey, grey, grey);
    }
};