#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "Matrices_y_Archivos.h"
#include "Multiplicacion_de_matrices.h"
#include "algoritmos_de_ordenamiento.cpp"
using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;


int Experimentos(int Rango_de_Valores_A, int Rango_de_Valores_B, int filas, int columnas);

int main(){

    int Rangos_A = 100, Rangos_B = 200, filas = 256, columnas = 256;


    Experimentos(Rangos_A,Rangos_B, filas, columnas);

    cout<<"Hola mundo";



    return 0;
}







int Experimentos(int Rango_de_Valores_A, int Rango_de_Valores_B, int filas, int columnas){

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Crear la Base de Datos

    int size = filas;

    int *tiempo = new int[10];

    string MatrizA = "MatrizA_convencional.txt";
    string MatrizB = "MatrizB_convencional.txt";
    
    //CrearMatriz_Archivo(MatrizA,filas,columnas,Rango_de_Valores_A);
    //CrearMatriz_Archivo(MatrizB,filas,columnas,Rango_de_Valores_B);

    int **Matriz1 = new int*[filas];
    for(int i =0; i<filas;i++){
        Matriz1[i] = new int[columnas]; 
    }
    int **Matriz2 = new int*[filas];
    for(int i =0; i<filas;i++){
        Matriz2[i] = new int[columnas]; 
    }

    //**Matriz1 = lectura(MatrizA,filas,columnas);

    Matriz1 = lecturaMatriz_Archivo(MatrizA,filas,columnas); // Leer el puntero y ponerlo en la variable int* que es puntero tambien 
    Matriz2 = lecturaMatriz_Archivo(MatrizB,filas,columnas);

    //leerMatriz(Matriz1,filas,columnas);
    //leerMatriz(Matriz2,filas,columnas);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Multiplicacion de Matrices

    int **C_strassen = new int*[filas];
    for(int i =0; i<filas;i++){
        C_strassen[i] = new int[columnas]; 
    }

    int **strasenMul = new int*[filas];
    for(int i =0; i<filas;i++){
        strasenMul[i] = new int[columnas]; 
    }   
    
    int **cubicTMul = new int*[filas];
    for(int i =0; i<filas;i++){
        cubicTMul[i] = new int[columnas]; 
    }

    int **cubicTMulopt = new int*[filas];
    for(int i =0; i<filas;i++){
        cubicTMulopt[i] = new int[columnas]; 
    } 


    time_t instanteInicial, instanteFinal;
    instanteInicial = time(0);
    cubicTMulopt = Mult_cubicT_opt(Matriz1,Matriz2,size);
    //leerMatriz(cubicTMulopt,filas,columnas);




    cubicTMul  = Mul_cubicT(Matriz1,Matriz2,size);
    //leerMatriz(cubicTMul,filas,columnas);


    time_t instanteInicial, instanteFinal;
    instanteInicial = time(0);


    strasenMul = strassen(size,Matriz1,Matriz2,C_strassen);
    //leerMatriz(strasenMul,filas,columnas);
    instanteFinal = time(0);

    //tiempo[0] = instanteFinal - instanteInicial; 
    cout<<instanteFinal - instanteInicial;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Algoritmos de ordenamiento



    ////////////////////////////////////////
    // Conversion de Vectores que tienen los valores de los metodos de multiplicacion de matrices

    int *Vect_cubicOpt = new int[filas*columnas];
    int *Vect_cubicT = new int[filas*columnas];
    int *Vect_strassen = new int[filas*columnas];

    Vect_cubicOpt = Convertir_Matriz_a_Vector(cubicTMulopt,filas,columnas);
    //leerVector(Vect_cubicOpt, filas*columnas);
    Vect_cubicT = Convertir_Matriz_a_Vector(cubicTMulopt,filas,columnas);
    //leerVector(Vect_cubicT, filas*columnas);
    Vect_strassen = Convertir_Matriz_a_Vector(strasenMul,filas,columnas);
    //leerVector(Vect_strassen, filas*columnas);

    /////////////////////////////////////////////////
    // Utilizacion de algoritmos de ordenamiento


    // Variables de Selesction Sort
    int *Selesction_sort_cubicOpt = new int[filas*columnas];
    int *Selesction_sort_cubicT = new int[filas*columnas];
    int *Selesction_sort_strassen = new int[filas*columnas];


    // Variables de Merge Sort
    int *Merge_sort_cubicOpt = new int[filas*columnas];
    int *Merge_sort_cubicT = new int[filas*columnas];
    int *Merge_sort_strassen = new int[filas*columnas];

    // Variables de QuickSort
    int *QuickSort_sort_cubicOpt = new int[filas*columnas];
    int *QuickSort_sort_cubicT = new int[filas*columnas];
    int *QuickSort_sort_strassen = new int[filas*columnas];



    // Selection Sort para la multiplicacion de Matrices


    Selesction_sort_cubicOpt = SelectionSort(Vect_cubicOpt,filas*columnas);
    //leerVector(Selesction_sort_cubicOpt, filas*columnas);
    Selesction_sort_cubicT = SelectionSort(Vect_cubicT,filas*columnas);
    //leerVector(Selesction_sort_cubicT, filas*columnas);
    Selesction_sort_strassen = SelectionSort(Vect_strassen,filas*columnas);
    //leerVector(Selesction_sort_strassen, filas*columnas);


    // Merge Sort para los diferentes algoritmos de multiplicacion de matrices

    Merge_sort_cubicOpt = SelectionSort(Vect_cubicOpt,filas*columnas);
    //leerVector(Merge_sort_cubicOpt, filas*columnas);
    Merge_sort_cubicT = SelectionSort(Vect_cubicT,filas*columnas);
    //leerVector(Merge_sort_cubicT, filas*columnas);
    Merge_sort_strassen = SelectionSort(Vect_strassen,filas*columnas);
    //leerVector(Merge_sort_strassen, filas*columnas);


    // Quick Sort para los diferentes algoritmos de multiplicacion de matrices

    QuickSort_sort_cubicOpt = quickSort(Vect_cubicOpt,filas*columnas);
    //leerVector(QuickSort_sort_cubicOpt, filas*columnas);
    QuickSort_sort_cubicT = quickSort(Vect_cubicT,filas*columnas);
    //leerVector(Merge_sort_cubicT, filas*columnas);
    QuickSort_sort_strassen = quickSort(Vect_strassen,filas*columnas);
    //leerVector(Merge_sort_strassen, filas*columnas);


    // Función de sorting implementada en la biblioteca estándar del lenguaje de programación

    vector<int> vector_opt(Vect_cubicOpt,Vect_cubicOpt+filas*columnas);
    sort(vector_opt.begin(),vector_opt.end());


    vector<int> vector_T(Vect_cubicT,Vect_cubicT+filas*columnas);
    sort(vector_T.begin(),vector_T.end());


    vector<int> vector_Strassen(Vect_strassen,Vect_strassen+filas*columnas);
    sort(vector_Strassen.begin(),vector_Strassen.end());

/*
    for (auto& elem : vector_T){
        std::cout << elem << "-" << std::endl;
    }
*/












    // Delete de todos los vectores y matrices creados
/*

    delete[] tiempo;

   for(int i = 0; i<filas; i++){
    delete[] Matriz1[i];
   }

   delete[] Matriz1;

   for(int i = 0; i<filas; i++){
    delete[] Matriz2[i];
   }

   delete[] Matriz2;


   for(int i = 0; i<filas; i++){
    delete[] C_strassen[i];
   }

   delete[] C_strassen;

   for(int i = 0; i<filas; i++){
    delete[] strasenMul[i];
   }

   delete[] strasenMul;

   for(int i = 0; i<filas; i++){
    delete[] cubicTMul[i];
   }

   delete[] cubicTMul;

   for(int i = 0; i<filas; i++){
    delete[] cubicTMulopt[i];
   }

   delete[] cubicTMulopt;


   delete[] Vect_cubicOpt;
   delete[] Vect_cubicT;
   delete[] Vect_strassen;

   delete[] Selesction_sort_cubicOpt;
   delete[] Selesction_sort_cubicT;
   delete[] Selesction_sort_strassen;
   delete[] Merge_sort_cubicOpt;
   delete[] Merge_sort_cubicT;
   delete[] Merge_sort_strassen;
   delete[] QuickSort_sort_cubicOpt;
   delete[] QuickSort_sort_cubicT;
   delete[] QuickSort_sort_strassen;
*/


    return 0;
}