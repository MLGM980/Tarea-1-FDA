#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//#include "CrearMatriz_Archivos.h"
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Algoritmo de Selection sort 

int Valor_Menor (int[],int,int);  
int* SelectionSort(int* Vector, int n)  
{  

    int pos,temp,pass=0;  
    for(int i=0;i<n;i++)  
    {  
        pos = Valor_Menor (Vector,i,n);  
        temp = Vector[i];  
        Vector[i]=Vector[pos];  
        Vector[pos] = temp; 
        pass++;
    }  
    //cout<<"\nNúmero de pases necesarios para ordenar la matriz: "<<pass;
    return Vector;  
}  

int Valor_Menor(int* Vector,int i, int n)  
{  
    int Menor,Posicion,j;  
    Menor = Vector[i];  
    Posicion = i;  
    for(j=i+1;j<n;j++)  
    {  
        if(Vector[j]<Menor)  
        {  
            Menor = Vector[j];  
            Posicion=j;  
        }  
    }  
    return Posicion;  
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Algoritmo de MergeSort 


int* mergeSort(int* arr, int len) {
    if (len <= 1) {
        return arr;
    }

    int m = len / 2;
    int* left = new int[m];
    int* right = new int[len - m];
    
    // Copiar la primera mitad del array en left
    for (int i = 0; i < m; i++) {
        left[i] = arr[i];
    }
    
    // Copiar la segunda mitad del array en right
    for (int i = m; i < len; i++) {
        right[i - m] = arr[i];
    }

    // Ordenar recursivamente las dos mitades del array
    left = mergeSort(left, m);
    right = mergeSort(right, len - m);

    // Mezclar las dos mitades ordenadas
    int* result = new int[len];
    int i = 0, j = 0, k = 0;
    while (i < m && j < len - m) {
        if (left[i] <= right[j]) {
            result[k] = left[i];
            i++;
        }
        else {
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < m) {
        result[k] = left[i];
        i++;
        k++;
    }

    while (j < len - m) {
        result[k] = right[j];
        j++;
        k++;
    }

    // Liberar memoria
    delete[] left;
    delete[] right;

    // Devolver el array ordenado
    return result;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Algoritmo de QuickSort



int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSortHelper(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

int* quickSort(int* arr, int len) {
    quickSortHelper(arr, 0, len - 1);
    return arr;
}