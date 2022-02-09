// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.

TEST(test_image_init) {
    
    Image *img = new Image;
    string input = "P3\n2 2\n255\n75 35 21 32 69 10 \n50 40 6 11 2 98 \n";
    std::istringstream ss_input(input);
    Image_init(img, ss_input);
    
    delete img;
}

TEST(test_image_init2) {
    
    Image *img = new Image;
    string input = "P5\n4 3\n255\n75 25 241 232 269 1 \n0 0 0 0 0 0 \n";
    std::istringstream ss_input(input);
    Image_init(img, ss_input);
    
    delete img;
}


TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_Image_get_pixel) {
    Image *img = new Image;
    
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);
    
    assert(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    assert(Pixel_equal(Image_get_pixel(img, 0, 1), green));
    assert(Pixel_equal(Image_get_pixel(img, 1, 0), blue));
    assert(Pixel_equal(Image_get_pixel(img, 1, 1), white));
    
    delete img;
}

TEST(test_Image_get_pixel_more) {
    Image *img = new Image;
    
    const Pixel d = {55, 60, 60};
    const Pixel g = {30, 25, 90};
    const Pixel b = {60, 10, 139};
    const Pixel w = {34, 100, 67};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, d);
    Image_set_pixel(img, 0, 1, g);
    Image_set_pixel(img, 1, 0, b);
    Image_set_pixel(img, 1, 1, w);
    
    assert(Pixel_equal(Image_get_pixel(img, 0, 0), d));
    assert(Pixel_equal(Image_get_pixel(img, 0, 1), g));
    assert(Pixel_equal(Image_get_pixel(img, 1, 0), b));
    assert(Pixel_equal(Image_get_pixel(img, 1, 1), w));
    
    delete img;
}

TEST(test_image_fill) {
    
    Image *img = new Image;
    
    const Pixel red = {255, 0, 0};
    
    Image_init(img, 2, 2);
    Image_fill(img, red);
    
    assert(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    assert(Pixel_equal(Image_get_pixel(img, 0, 1), red));
    assert(Pixel_equal(Image_get_pixel(img, 1, 0), red));
    assert(Pixel_equal(Image_get_pixel(img, 1, 1), red));
    
    delete img;
    
}

TEST(test_image_fill_more) {
    
    Image *img = new Image;
    
    const Pixel red = {255, 0, 0};
    
    Image_init(img, 10, 5);
    Image_fill(img, red);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            assert(Pixel_equal(Image_get_pixel(img, i, j), red));
        }
    }
    
    delete img;
    
}

TEST(test_image_fill_more2) {
    
    Image *img = new Image;
    
    const Pixel bl = {35, 37, 60};
    
    Image_init(img, 10, 15);
    Image_fill(img, bl);
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            assert(Pixel_equal(Image_get_pixel(img, i, j), bl));
        }
    }
    
    delete img;
    
}


TEST(test_print_not_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  Image_init(img, 5, 5);
  Image_fill(img, red);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n5 5\n255\n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}






// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
