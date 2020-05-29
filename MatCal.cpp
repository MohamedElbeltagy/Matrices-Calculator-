//
// By Elbeltagy.Mohamed
//

#include "MatCal.h" // Including the header file MatCal.h
#include <iostream>
#include <cstdlib>

using namespace std;
// The constructor is called automatically when creating 
// a new object of the class.
// Passing the number of rows and columns to the constructor.
template <typename T>
MatMulTrans::MatCal<T>::MatCal(int rows, int cols) {
    // Assigning the taken number of rows 
    // by the user to private memeber rows.
    this->rows = rows; 
    // Assigning the taken number of columns 
    // by the user to private memeber columns.
    this->cols = cols; 
    // Assigning the double pointer matrix variable
    // to generateMatrix function.
    matrix = generateMatrix(rows, cols);
}
// The destructor is called automatically when the object
// of the class is no longer in use.
// The destructor deletes the allocated space of the matrix 
// in memory.
template <typename T>
MatMulTrans::MatCal<T>::~MatCal() {
    // A for loop to delete the allocated space for the rows.
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    // Delete the whole matrix.
    delete [] matrix;
}

// Allocate a multidimensional array in the memory based on  
// the number of rows and columns.  
template <typename T>
T**  MatMulTrans::MatCal<T>::generateMatrix(int rows, int cols){
    // First assign double pointer tempMat varibale.
    // Allocate a space for rows in the heap.
    T** tempMat = new T *[rows]; 
    // Loop to build a space for columns in the heap. 
    for (int i = 0; i < rows; i++) {
        tempMat[i] = new T[cols];  
    }
    // Return the stored space for the new matrix.
    return tempMat;
}

// Populating the generated matrix function with rows and columns values.
// Passed argument must be a 1D array.
// The function can hold any datatype.
template <typename T>
void MatMulTrans::MatCal<T>::populateMatrix(T* arr) {
    int pos = 0; // A position holder variable
    // Nested for loop to fill in the matrix by the rows and columns values.
    for (int i = 0; i < rows; i++) {
        for(int j =0; j < cols; j++) {
            // increment the position of the array.
            matrix[i][j] = arr[pos++]; 
        }
    }
}
// Print the matrix after being populated with rows and columns values.
template <typename T>
void MatMulTrans::MatCal<T>::print(T scal) {
    // Nested for loop to scan the rows and columns values.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Print the values and a space between every number.
            cout << scal * (matrix[i][j]) << " ";
        }
        cout << endl;
    }
}
// Two matrices multiplication function
// This functions takes the object of the MatCal class.
// the object is passed by reference.
template <typename T>
void MatMulTrans::MatCal<T>::mul(MatCal &rhs) {

    // Error check function.
    // Numbers of columns of the LHS matrix should be the same as the 
    // number of rows in RHS matrix otherwise multiplication cannot take place.
    if (cols != rhs.getRows()){

        // Print error message and exit the program.
        cout << "Error!" << endl;
        cout << "Number columns' of LHS matrix is not equal the number of rows in RHS matrix " << endl;
        exit(1);
    }

    // Double pointer generic variable to store the multiplication result.
    // generate a new matrix's space based on number of rows of the LHS matrix
    // and number of columns of the RHS matrix.
    T** result = generateMatrix(rows, rhs.getCols());
    
    // Clear all rows and cols of the new matrix and set it to zero.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rhs.getCols(); j++) {
            result[i][j] = 0;
        }
    }

    // Multiply each element of LHS matrix row to each element of LHS matrix columns
    // and add the result in the new matrix. 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix[i][k] * rhs.getValue(k, j);
            }

        }
    }

    // deallocate the memory after the proces is done.
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    // Copy the result to variable matrix.
    matrix = result;
    // copy the RHS matrix columns to the LHS matrix.
    cols = rhs.getCols();
}

// Transpose a matrix
template <typename T>
void MatMulTrans::MatCal<T>::trans() {
    // Set a temp variable to store the transposed matrix.
    T** temp = generateMatrix(cols, rows);
    // Replace the rows by columns to get the transpose of a matrix.
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            temp[i][j] = matrix[j][i];
        }
    }
    // deallocate the memory after the proces is done.
    for (int i = 0; i < rows; i++){
        delete[] matrix[i];
    }

    // Copy the transposed matrix to matrix variable.
    matrix = temp;
    // Swap rows by colums.
    int tmp = rows;
    rows = cols;
    cols = tmp;
}

// Get a value of an object matrix at i and j location when needed
template <typename T>
T MatMulTrans::MatCal<T>::getValue(int i, int j) {
    return matrix[i][j];
}
// Get a value of rows an object matrix.
template <typename T>
int MatMulTrans::MatCal<T>::getRows() {
    return rows;
}
// Get a value of columns an object matrix.
template <typename T>
int MatMulTrans::MatCal<T>::getCols() {
    return cols;
}