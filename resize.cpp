// Project UID af1f95f547e44c8ea88730dfb185559d
// resize.cpp
#include <iostream>
#include "processing.h"
#include "Image.h"
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
    Image img;
    ifstream is;
    ofstream os;
    string filename = argv[1];
    string output = argv[2];
    int width, height;
    is.open(filename);
    os.open(output);
    if (!is.is_open() || !os.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }
    Image_init(&img, is);
    if (argc == 4) {
        width = *argv[3];
        if (width < 0 || width > Image_width(img)) {
                cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                    << "WIDTH and HEIGHT must be less than or equal to original" << endl;
                return 1;
        }
            seam_carve_width(&img, width);
            Image_print(&img, os);
        }
        else if (argc == 5) {
            width = atoi(argv[3]);
            height = atoi(argv[4]);
            if (width < 0 || width > Image_width(img) || height < 0 || height > Image_height(img)) {
                cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                    << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            }
            seam_carve(&img, width, height);
            Image_print(&img, os);
        }
        else {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return 1;
        }
    delete img;
}
