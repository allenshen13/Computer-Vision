// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_fill_border){
    Matrix *mat = new Matrix;
    
    const int width = 5;
    const int height = 3;
    const int value = 42;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 3);
    Matrix_fill_border(mat, value);
    ASSERT_EQUAL(*Matrix_at(mat, 0, 4), value);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 4), value);
    ASSERT_EQUAL(*Matrix_at(mat, 2, 4), value);
    
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), value);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 0), value);
    ASSERT_EQUAL(*Matrix_at(mat, 2, 0), value);
    
    ASSERT_EQUAL(*Matrix_at(mat, 0, 1), value);
    ASSERT_EQUAL(*Matrix_at(mat, 0, 2), value);
    ASSERT_EQUAL(*Matrix_at(mat, 0, 3), value);
    
    ASSERT_EQUAL(*Matrix_at(mat, 2, 1), value);
    ASSERT_EQUAL(*Matrix_at(mat, 2, 2), value);
    ASSERT_EQUAL(*Matrix_at(mat, 2, 3), value);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 3);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 2), 3);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 3), 3);
    delete mat;
}


TEST(fill_border_more) {
    
    Matrix* mat2 = new Matrix;
    Matrix_init(mat2, 1, 1);
    Matrix_fill_border(mat2, 3);
    ASSERT_EQUAL(*Matrix_at(mat2, 0, 0), 3);
    delete mat2;
    
    
    Matrix* mat3 = new Matrix;
    Matrix_init(mat3, 6, 5);
    Matrix_fill(mat3, 5);
    Matrix_fill_border(mat3, 3);
    ASSERT_EQUAL(*Matrix_at(mat3, 0, 0), 3);
    ASSERT_EQUAL(*Matrix_at(mat3, 0, 1), 3);
    ASSERT_EQUAL(*Matrix_at(mat3, 0, 4), 3);
    ASSERT_EQUAL(*Matrix_at(mat3, 0, 5), 3);
    ASSERT_EQUAL(*Matrix_at(mat3, 3, 5), 3);
    
    ASSERT_EQUAL(*Matrix_at(mat3, 1, 1), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 1, 2), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 1, 3), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 1, 4), 5);
    
    
    ASSERT_EQUAL(*Matrix_at(mat3, 2, 1), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 2, 2), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 2, 3), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 2, 4), 5);

    
    ASSERT_EQUAL(*Matrix_at(mat3, 3, 1), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 3, 2), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 3, 3), 5);
    ASSERT_EQUAL(*Matrix_at(mat3, 3, 4), 5);
    
    
    delete mat3;
    
}
TEST(test_height_width) {
    
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 5);
    ASSERT_EQUAL(Matrix_width(mat), 3);
    ASSERT_EQUAL(Matrix_height(mat), 5);
    delete mat;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 0, 0);
    ASSERT_EQUAL(Matrix_width(mat2), 0);
    ASSERT_EQUAL(Matrix_height(mat2), 0);
    delete mat2;
    
    Matrix *mat3 = new Matrix;
    Matrix_init(mat3, 4, 4);
    ASSERT_EQUAL(Matrix_width(mat3), 4);
    ASSERT_EQUAL(Matrix_height(mat3), 4);
    delete mat3;
    
   

    
}

TEST(test_max) {
    
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 5);
    Matrix_fill(mat, 3);
    *Matrix_at(mat, 2, 2) = 4;
    ASSERT_EQUAL(Matrix_max(mat), 4);
    delete mat;

    Matrix* mat1 = new Matrix;
    Matrix_init(mat1, 4, 4);
    Matrix_fill(mat1, -5);
    *Matrix_at(mat1, 2, 2) = -2;
    ASSERT_EQUAL(Matrix_max(mat1), -2);
    delete mat1;
    
    
    
}

    
TEST(test_row_col) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 5);
    int* ptr = &(*Matrix_at(mat, 1, 1));
    cout << Matrix_row(mat, ptr);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 1);
    delete mat;

    Matrix* mat1 = new Matrix;
    Matrix_init(mat1, 4, 4);
    int* ptr1 = &(*Matrix_at(mat1, 3, 3));
    cout << Matrix_row(mat1, ptr1);
    ASSERT_EQUAL(Matrix_row(mat1, ptr1), 3);
    delete mat1;

    
}


TEST(test_column_of_min_value_in_row) {

    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 3);
    Matrix_fill(mat, 0);
    *Matrix_at(mat, 2, 4) = -3;
    *Matrix_at(mat, 1, 3) = 1;
    *Matrix_at(mat, 0, 4) = -3;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 4), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 1, 4), 1);

    delete mat;

    Matrix* mat2 = new Matrix;
    Matrix_init(mat2, 4, 4);
    Matrix_fill(mat2, 4);
    *Matrix_at(mat2, 0, 0) = -3;
    *Matrix_at(mat2, 1, 3) = -3;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat2, 0, 1, 3), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat2, 0, 0, 3), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat2, 1, 0, 3), 0);
    
    delete mat2;
    
}

TEST(test_min_value_in_row) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 3);
    Matrix_fill(mat, -5);
    *Matrix_at(mat, 2, 4) = -3;
    *Matrix_at(mat, 1, 4) = -10;
    *Matrix_at(mat, 0, 4) = -3;
   
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 4), -5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 5), -10);
    
    delete mat;


}




// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
