#include "Matrix.h"


// If you wish to include any helper functions, please do so at the end of this file.

/*=================================================================================*/
// Default Constructor
Matrix::Matrix() : size(0), data(NULL) {
}

Matrix::Matrix(int matrixSize) : size(matrixSize), data(NULL) {
    if (size > 0) {
        data = new int*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new int[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = 0;
            }
        }
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix& other) : size(other.size), data(NULL) {
    if (size > 0) {
        data = new int*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new int[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Clean up existing data
        if (data != NULL) {
            for (int i = 0; i < size; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
        
        // Copy size and allocate new memory
        size = other.size;
        if (size > 0) {
            data = new int*[size];
            for (int i = 0; i < size; i++) {
                data[i] = new int[size];
                for (int j = 0; j < size; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
    }
    return *this;
}

// Destructor
Matrix::~Matrix() {
    if (data != NULL) {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

/*=================================================================================*/
/*======================= Implement the below functions ===========================*/
/*=================================================================================*/

// Get the size of the matrix
int Matrix::getSize() const {
    return size;
}

// Load matrix from file
bool Matrix::loadFromFile(const char* filename) {
Matrix Read_Matrix;
    std::ifstream infile;
    infile.open(filename);
    infile>>Read_Matrix;//friend//
}

// Get element at position (row, col)
int Matrix::getElement(int row, int col) const {

}

// Set element at position (row, col)
void Matrix::setElement(int row, int col, int value) {

}

// Main matrix multiplication function
void Matrix::matrixCalculator(const Matrix& matrix1, const Matrix& matrix2, int rowIndex) {

}

// Thread worker function for thread function
void threadWorker(const Matrix& matrix1, const Matrix& matrix2, 
                  Matrix& result, int rowIndex, std::mutex* printMutex) {

}

    


