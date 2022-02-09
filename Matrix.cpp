// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"


void Matrix_init(Matrix* mat, int width, int height) {
    mat->width = width;
    mat->height = height;
    
}

void Matrix_print(const Matrix* mat, std::ostream& os) {
    os << mat->width << " " << mat->height << "\n";
    for (int i = 0; i < mat->height; i++) {
        for (int j = 0; j < mat->width; j++) {
            os << *Matrix_at(mat, i, j) << " ";
        }
        os << "\n";
    }
    
}

int Matrix_width(const Matrix* mat) {
    return mat->width;
}


int Matrix_height(const Matrix* mat) {
    return mat->height;
}


int Matrix_row(const Matrix* mat, const int* ptr) {
    for (int i = 0; i < mat->height; i++) {
        for (int j = 0; j < mat->width; j++) {
            if (Matrix_at(mat, i, j) == ptr) {
                return i;
            }
        }
    }
    return 0;
}


int Matrix_column(const Matrix* mat, const int* ptr) {
    for (int i = 0; i < mat->height; i++) {
        for (int j = 0; j < mat->width; j++) {
            if (Matrix_at(mat, i, j) == ptr) {
                return j;
            }
        }
    }
    return 0;
}


int* Matrix_at(Matrix* mat, int row, int column) {
    
    return mat->data + ((row * mat->width) + column);

}


const int* Matrix_at(const Matrix* mat, int row, int column) {
   
    const int *ptr = mat->data + ((row * mat->width) + column);
    return ptr;
    
}


void Matrix_fill(Matrix* mat, int value) {
   for (int i = 0; i < mat->height; i++) {
        for (int j = 0; j < mat->width; j++) {
            *Matrix_at(mat, i, j) = value;
        }
    }
}


void Matrix_fill_border(Matrix* mat, int value) {
    
    for (int i = 0; i < Matrix_width(mat); i++) {
        *Matrix_at(mat, 0, i) = value;
        *Matrix_at(mat, Matrix_height(mat) - 1, i) = value;
    }
    
    for (int i = 0; i < Matrix_height(mat); i++) {
        *Matrix_at(mat, i, 0) = value;
        *Matrix_at(mat, i, Matrix_width(mat) - 1) = value;
    }

}

int Matrix_max(const Matrix* mat) {
    int max = *Matrix_at(mat, 0, 0);
    
    for (int row = 0; row < mat->height; row++) {
        for (int col = 0; col < mat->width; col++) {
            if (*Matrix_at(mat, row, col) > max) {
                max = *Matrix_at(mat, row, col);
            }
        }
    }
    
    return max;
}


int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    assert(0 <= row && row < Matrix_height(mat));
    int min = *Matrix_at(mat, row, column_start);
    int min_col = column_start;
    for (int i = column_start; i < column_end; i++) {
        if (*Matrix_at(mat, row, i) < min) {
           min = *Matrix_at(mat, row, i);
            min_col = i;
        }
    }
    if (column_end == Matrix_width(mat)) {
        if (*Matrix_at(mat, row, Matrix_width(mat) - 1) < min) {
            min_col = column_end - 1;
        }
    }
    return min_col;
    
}

int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    assert(0 <= row && row < Matrix_height(mat));
   
    int min = *Matrix_at(mat, row, column_start);
    
    for (int i = column_start; i < column_end; i++) {
        if (*Matrix_at(mat, row, i) < min) {
            min = *Matrix_at(mat, row, i);
        }
    }
    return min;

}
