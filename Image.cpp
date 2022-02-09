// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
#include <iostream>
using namespace std;



void Image_init(Image* img, int width, int height) {
    img->width = width;
    img->height = height;
    Matrix_init(&img->red_channel, width, height);
    Matrix_init(&img->green_channel, width, height);
    Matrix_init(&img->blue_channel, width, height);
    
}

void Image_init(Image* img, std::istream& is) {
    int rgb;
    string filename;
    int width;
    int height;

    is >> filename >> width >> height >> rgb;
    img->width = width;
    img->height = height;
    Matrix_init(&img->red_channel, width, height);
    Matrix_init(&img->green_channel, width, height);
    Matrix_init(&img->blue_channel, width, height);
    
    int rVal;
    int gVal;
    int bVal;
    
    for (int j = 0; j < height; j++) {
        for (int k = 0; k < width; k++) {
            is >> rVal >> gVal >> bVal;
            *Matrix_at(&img->red_channel, j, k) = rVal;
            *Matrix_at(&img->green_channel, j, k) = gVal;
            *Matrix_at(&img->blue_channel, j, k) = bVal;
        }
    }
}

void Image_print(const Image* img, std::ostream& os) {
    os << "P3" << endl;
    os << img->width << " " << img->height << endl;
    os << "255" << endl;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            os << *Matrix_at(&img->red_channel, i, j) << " " <<
            *Matrix_at(&img->green_channel, i, j) << " " <<
            *Matrix_at(&img->blue_channel, i, j) << " ";
        }
        os << endl;
    }
}

int Image_width(const Image* img) {
    return img->width;
}

int Image_height(const Image* img) {
    return img->height;
}

Pixel Image_get_pixel(const Image* img, int row, int column) {
    
    Pixel result;
    result.r = *Matrix_at(&img->red_channel, row, column);
    result.g = *Matrix_at(&img->green_channel, row, column);
    result.b = *Matrix_at(&img->blue_channel, row, column);
    
    return result;
    
}

void Image_set_pixel(Image* img, int row, int column, Pixel color) {
    *Matrix_at(&img->red_channel, row, column) = color.r;
    *Matrix_at(&img->green_channel, row, column) = color.g;
    *Matrix_at(&img->blue_channel, row, column) = color.b;
    
}

void Image_fill(Image* img, Pixel color) {

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            *Matrix_at(&img->red_channel, i, j) = color.r;
            *Matrix_at(&img->green_channel, i, j) = color.g;
            *Matrix_at(&img->blue_channel, i, j) = color.b;
        }
    }

}
