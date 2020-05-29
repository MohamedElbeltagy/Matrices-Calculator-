
//
// By Elbeltagy.Mohamed
//

#ifndef ELBELTAGY_MOHAMED_MATCAL_H
#define ELBELTAGY_MOHAMED_MATCAL_H

// Initializing the prototypes of the class in the MatCal.h header file.
// Encapsulating the "MatCal" class inside "MatMulTrans" namespace. 
namespace MatMulTrans {
    // Initializing generic class to work with different matrices datetype.    
    template <typename T> class MatCal{
    // The members inside the private access specifier are not required to be accesed by the client.
    private:
        int rows;   // Number of rows holder variable.
        int cols;   // Number of rows columns variable.
        T **matrix; // A pointer to pointer varible to hold the 2D array or the matrix.
                    // The matrix variable datatype is generic to hold different matrices datetype.
    
    // The members inside the protected access specifier are required to be accessed by the MatCal clas only.
    protected:
        // Generaic matrix generator function.
        T** generateMatrix(int rows, int cols);
        // Generaic matrix retrieve function for further operations.
        T getValue(int i, int j);
        // Returning number of rows of a matrix for further operations.
        int getRows();
        // Returning number of columns of a matrix for further operations.
        int getCols();
    // The members inside the public access specifier can be accessed by the user.
    public:
        // Constructor initializations to take the number of rows 
        // and of columns as arguments.
        MatCal(int rows, int cols);
        // Populating the generated matrix function with rows and columns values.
        // The function accepts generic array argument.
        void populateMatrix(T* arr);
        // Print the matrix.
        void print(T scal);
        // Transpose the matrix.
        void trans();
        // multiplying a matrix by another matrix by passing 
        // the object of the second matrix argument.
        void mul(MatCal &rhs);
        // Destructor is called once the MatCal class is no longer in use.
        ~MatCal();
    };

}       
#endif