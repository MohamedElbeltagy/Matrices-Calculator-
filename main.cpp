//
// By Elbeltagy.Mohamed
//

#include "MatCal.h"
#include "MatCal.cpp"
#include <iostream>


using namespace std;



int main () {

    // multiplicaiton code     
    int rowsA = 0; 
    int colsA = 0;
    int rowsB = 0; 
    int colsB = 0;
    int scalA = 0;
    int scalB = 0;
    float arrA[100];
    float arrB[100];

    cout << "Enter number of rows of matrix A" << endl;
    cin >> rowsA;
    cout << "Enter number of columns matrix A" << endl;
    cin >> colsA;
    cout << "Enter multiplication factor of matrix A" << endl;
    cin >> scalA;   
    cout << "Enter elements of the matrix A" << endl;
    for(int i = 0; i < rowsA*colsA; i++){
        cout << "MatA" << "[" << i+1 << "] = ";  
        cin >> arrA[i];
    }

    cout << endl;
    
    cout << "Enter number of rows of matrix B" << endl;
    cin >> rowsB;
    cout << "Enter number of columns matrix B" << endl;
    cin >> colsB;
    cout << "Enter multiplication factor of matrix B" << endl;
    cin >> scalB;  
    cout << "Enter elements of the matrix B" << endl;
    for(int i = 0; i < rowsB*colsB; i++){
        cout << "MatA" << "[" << i+1 << "] = ";  
        cin >> arrB[i];
    }
    
    cout << endl;
    MatMulTrans::MatCal<float> matA(rowsA,colsA);
    matA.populateMatrix(arrA);
    cout << "Matrix A is" << endl;
    matA.print(scalA);
    
    cout << endl;
    MatMulTrans::MatCal<float> matB(rowsB,colsB);
    matB.populateMatrix(arrB);
    cout << "Matrix B is" << endl;
    matB.print(scalB);

    cout << endl;
    cout << "A and B matrices multiplication is" << endl;
    matA.mul(matB);
    matA.print(1);
    return 0; 
}  



    /*
    // Matrix print code

    int rowsA = 0; 
    int colsA = 0;
    int scal = 1;
    int arrA[100];

    cout << "Enter number of rows of matrix A" << endl;
    cin >> rowsA;
    cout << "Enter number of columns matrix A" << endl;
    cin >> colsA; 
    cout << "Enter multiplication factor" << endl;
    cin >> scal; 
    cout << "Enter elements of the matrix A" << endl;
    for(int i = 0; i < rowsA*colsA; i++){
        cout << "MatA" << "[" << i << "] = ";  
        cin >> arrA[i];
    }
    cout << endl;

    MatMulTrans::MatCal<int> matA(rowsA,colsA);
    matA.populateMatrix(arrA);
    cout << "The result matrix" << endl;
    */


    /*
    // Matrix transpose code

    int rowsA = 0; 
    int colsA = 0;
    int scal = 1;
    int arrA[100];

    cout << "Enter number of rows of matrix A" << endl;
    cin >> rowsA;
    cout << "Enter number of columns matrix A" << endl;
    cin >> colsA; 
    cout << "Enter multiplication factor" << endl;
    cin >> scal; 
    cout << "Enter elements of the matrix A" << endl;
    for(int i = 0; i < rowsA*colsA; i++){
        cout << "MatA" << "[" << i << "] = ";  
        cin >> arrA[i];
    }
    cout << endl;

    MatMulTrans::MatCal<int> matA(rowsA,colsA);
    matA.populateMatrix(arrA);
    cout << "The result matrix" << endl;
    matA.print(scal);
    cout << "The matrix transposition result" << endl;
    matA.trans();
    matA.print(scal);*/