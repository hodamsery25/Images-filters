/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/


#include "Image_Class.h"


using namespace std;

void modify_grayscale_filter(Image& img) {
    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            unsigned char r = img.getPixel(x, y, 0);
            unsigned char g = img.getPixel(x, y, 1);
            unsigned char b = img.getPixel(x, y, 2);

            unsigned char gray = static_cast<unsigned char>(0.21 * r + 0.72 * g + 0.07 * b);

            img.setPixel(x, y, 0, gray);
            img.setPixel(x, y, 1, gray);
            img.setPixel(x, y, 2, gray);
        }
    }
}
void modify_flip_filter(Image& img) {
    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width / 2; ++x) {
            unsigned char r1 = img.getPixel(x, y, 0);
            unsigned char g1 = img.getPixel(x, y, 1);
            unsigned char b1 = img.getPixel(x, y, 2);

            unsigned char r2 = img.getPixel(img.width - x - 1, y, 0);
            unsigned char g2 = img.getPixel(img.width - x - 1, y, 1);
            unsigned char b2 = img.getPixel(img.width - x - 1, y, 2);

            img.setPixel(x, y, 0, r2);
            img.setPixel(x, y, 1, g2);
            img.setPixel(x, y, 2, b2);

            img.setPixel(img.width - x - 1, y, 0, r1);
            img.setPixel(img.width - x - 1, y, 1, g1);
            img.setPixel(img.width - x - 1, y, 2, b1);
        }
    }
}

void modify_vertical_flip_filter(Image& img)
{
    for (int y = 0; y < img.height / 2; ++y) {
        for (int x = 0; x < img.width; ++x) {
            unsigned char r1 = img.getPixel(x, y, 0);
            unsigned char g1 = img.getPixel(x, y, 1);
            unsigned char b1 = img.getPixel(x, y, 2);

            unsigned char r2 = img.getPixel(x, img.height - y - 1, 0);
            unsigned char g2 = img.getPixel(x, img.height - y - 1, 1);
            unsigned char b2 = img.getPixel(x, img.height - y - 1, 2);

            img.setPixel(x, y, 0, r2);
            img.setPixel(x, y, 1, g2);
            img.setPixel(x, y, 2, b2);

            img.setPixel(x, img.height - y - 1, 0, r1);
            img.setPixel(x, img.height - y - 1, 1, g1);
            img.setPixel(x, img.height - y - 1, 2, b1);
        }
    }
}
int main() {
    string photo;
    cout << "Enter image name: ";
    cin >> photo;
    Image image(photo);

    int choice;
    cout << "Choose a filter:\n";
    cout << "1. Grayscale Filter\n";
    cout << "2. flip Filter\n";
    cout << "3. Vertical Flip Filter\n";
    cin >> choice;

    switch (choice) {
        case 1:
            modify_grayscale_filter(image);
            break;
            case 2:
            modify_flip_filter(image);
            break;
        case 3:
            modify_vertical_flip_filter(image);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    image.saveImage(photo);
    system(photo.c_str());
    return 0;
}