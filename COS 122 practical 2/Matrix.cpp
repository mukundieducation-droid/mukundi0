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
int row_number;
int column_number;
    std::ifstream infile;
    infile.open(filename);
    if(!infile){
    std::cout<<"There was an error while opening the file"<<std::endl;
    return false;
    }
    infile>>row_number;
    infile>>column_number;
    if(row_number!=column_number){
        std::cout<<"Error: The matrix is not a square matrix"<<std::endl;
    }

    data = new int*[row_number];
    for(int i=0;i<row_number;i++){
data[i]=new int[column_number];
    }
for(int x=0;x<row_number;x++)
{for(int y=0; y<column_number;y++){
infile>>data[x][y];


}
}
infile.close();
return true;
    }


// Get element at position (row, col)
int Matrix::getElement(int row, int col) const {

if (data==NULL || row<0 || col<0 || row>size || col>size){
std::cout<<"Error: Cannot work with the matrix"<<std::endl;
return 0;
}
return data[row][col];
}

// Set element at position (row, col)
void Matrix::setElement(int row, int col, int value) {
    if (data==NULL || row<0 || col<0 || row>size || col>size)
    {return;}

    data[row][col]=value;
}



// Main matrix multiplication function
void Matrix::matrixCalculator(const Matrix& matrix1, const Matrix& matrix2, int rowIndex) {
    Matrix result;
    for(int j=0;j<size;j++){
        double sum=0;
        for(int k=0;k<size;k++){
sum+=matrix1.getElement(rowIndex,k)*matrix2.getElement(k,j);

result.setElement(rowIndex,j,sum);

}}}

// Thread worker function for thread function
void threadWorker(const Matrix& matrix1, const Matrix& matrix2, 
                  Matrix& result, int rowIndex, std::mutex* printMutex) {

}

    


