#include "filter.h"
void modify_grayscale_filter(Image& img)
{
    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            unsigned char r = img.getPixel(x, y, 0);
            unsigned char g = img.getPixel(x, y, 1);
            unsigned char b = img.getPixel(x, y, 2);

            // Calculate the grayscale value using the luminosity method
            unsigned char gray = static_cast<unsigned char>(0.21 * r + 0.72 * g + 0.07 * b);

            // Set the pixel to the new grayscale value
            img.setPixel(x, y, 0, gray);
            img.setPixel(x, y, 1, gray);
            img.setPixel(x, y, 2, gray);
        }
    }
   
}




