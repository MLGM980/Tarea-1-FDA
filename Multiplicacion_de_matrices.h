#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono>
//#include "CrearMatriz_Archivos.h"
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Algoritmo Iterativo Cubico Tradicional


int** Mul_cubicT(int** A, int** B, int n){

    int **C = new int*[n];
    for(int i =0; i<n;i++){
        C[i] = new int[n]; 
    }


    // Medicion del tiempo
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			C[i][j] = 0;
			for(int k=0; k<n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

    return C;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Algoritmo Iterativo Cubico Mejorado

int** Mult_cubicT_opt(int** A, int** B,int n){


    // Se obtiene la Traspuesta de la Matriz B

    int **trasp = new int*[n];
    for(int i =0; i<n;i++){
        trasp[i] = new int[n]; 
    }

	for(int c=0;c<n;c++){
		for(int d=0;d<n;d++){
			trasp[d][c] = B[c][d];
		}
	}

    int **C = new int*[n];
    for(int i =0; i<n;i++){
        C[i] = new int[n]; 
    }

    // Se obtiene los valores de C con la matriz traspuesta de B y cambiando los indices en la traspuesta de diferencia del metodo cubico tradicional

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }



    return C;

}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Algorimo de Strassen


void matrix_add(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_subtract(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrix_multiply(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int** strassen(int n, int** A, int** B, int** C){




    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

	// Se define la variable n/2
    int half_n = n/2;

	// Definicion de las partes de la matriz

    // Definicion de la Matriz A

    int **A11 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        A11[i] = new int[half_n]; 
    }

    int **A12 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        A12[i] = new int[half_n]; 
    }

    int **A21 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        A21[i] = new int[half_n]; 
    }

    int **A22 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        A22[i] = new int[half_n]; 
    } 

    // Definicion de la Matriz B

    int **B11 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        B11[i] = new int[half_n]; 
    }

    int **B12 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        B12[i] = new int[half_n]; 
    }

    int **B21 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        B21[i] = new int[half_n]; 
    }

    int **B22 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        B22[i] = new int[half_n]; 
    } 

    // Definicion de la Matriz C

    int **C11 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        C11[i] = new int[half_n]; 
    }

    int **C12 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        C12[i] = new int[half_n]; 
    }

    int **C21 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        C21[i] = new int[half_n]; 
    }

    int **C22 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        C22[i] = new int[half_n]; 
    } 
               
	// 7 problemas

    int **M1 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M1[i] = new int[half_n]; 
    } 

    int **M2 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M2[i] = new int[half_n]; 
    } 

    int **M3 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M3[i] = new int[half_n]; 
    }

    int **M4 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M4[i] = new int[half_n]; 
    }

    int **M5 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M5[i] = new int[half_n]; 
    }

    int **M6 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M6[i] = new int[half_n]; 
    }

    int **M7 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        M7[i] = new int[half_n]; 
    }  

    // Variable de temp  
    int **temp1 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        temp1[i] = new int[half_n]; 
    }
         
    int **temp2 = new int*[half_n];
    for(int i =0; i<half_n;i++){
        temp2[i] = new int[half_n]; 
    }   

    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half_n];
            A21[i][j] = A[i + half_n][j];
            A22[i][j] = A[i + half_n][j + half_n];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half_n];
            B21[i][j] = B[i + half_n][j];
            B22[i][j] = B[i + half_n][j + half_n];
        }
    }

	// M5 = (A11+A22)*(B11+B22)
	//         temp1 * temp2
    matrix_add(half_n, A11, A22, temp1);
    matrix_add(half_n, B11, B22, temp2);
    strassen(half_n, temp1, temp2, M5);

	// M3 = (A21 + A22)*B11
    matrix_add(half_n, A21, A22, temp1);
    strassen(half_n, temp1, B11, M3);

	// M1 = A11*(B12-B22)
    matrix_subtract(half_n, B12, B22, temp2);
    strassen(half_n, A11, temp2, M1);

	// M4 = A22*(B21-B11)
    matrix_subtract(half_n, B21, B11, temp2);
    strassen(half_n, A22, temp2, M4);

	// M2 = (A11+A12)*B22
    matrix_add(half_n, A11, A12, temp1);
    strassen(half_n, temp1, B22, M2);

	// M7 = (A11-A21*(B11+B12)
    matrix_subtract(half_n, A11, A21, temp1);
    matrix_add(half_n, B11, B12, temp2);	
    strassen(half_n, temp1, temp2, M7);	

	// M6 = (A12-A22)*(B21+B22)
    matrix_subtract(half_n, A12, A22, temp1);
    matrix_add(half_n, B21, B22, temp2);	
    strassen(half_n, temp1, temp2, M6);		



    // C11 = M5 + M4 - M2 + M6
    matrix_add(half_n, M5, M4, C11);
    matrix_subtract(half_n, C11, M2, C11);
    matrix_add(half_n, C11, M6, C11);

    // C12 = M1 + M2
    matrix_add(half_n, M1, M2, C12);

    // C21 = M3 + M4
    matrix_add(half_n, M3, M4, C21);

    // C22 = M1 + M5 - M3 - M7
    matrix_add(half_n, M1, M5, C22);
    matrix_subtract(half_n, C22, M3, C22);
    matrix_subtract(half_n, C22, M7, C22);

    // Combining 4 submatrices (C11, C12, C21, C22) into a larger matrix C
    for (int i = 0; i < half_n; i++)
    {
        for (int j = 0; j < half_n; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + half_n] = C12[i][j];
            C[i + half_n][j] = C21[i][j];
            C[i + half_n][j + half_n] = C22[i][j];
        }
    }

    /*

    cout << "Matrix C = A * B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    */


    return C;



}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////