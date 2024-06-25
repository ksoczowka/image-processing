#include <fstream>

int main() {
    int red = 0;
    int green = 0;
    int blue = 0;

    std::ofstream image("./Image.ppm");

    if(image.is_open()) {
        image << "P3\n";
        image << "250 250\n";
        image << "255\n";

        for(int y = 0; y < 250; y++) {
            for(int x = 0; x < 250; x++) {
                image << red << ' ' << green << ' ' << blue << '\n';
            }
        }

        image.close();
    }

    return 0;
}