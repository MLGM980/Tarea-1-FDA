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

// Implementacion




void CrearMatriz_Archivo(string nombre,int filas,int columnas,int N_max){
    // Inicializa la semilla para el rand
    srand (time(NULL)); 
    // Inicializacacion de Archivos TxT
    ofstream MatrizA(nombre);

    int **Matriz = new int*[filas];
    for(int i =0; i<filas;i++){
        Matriz[i] = new int[columnas]; 
    }    


    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            Matriz[i][j] = rand() % N_max;
            //cout <<"\n"<<i<<j<<"="<<Matriz[i][j];
            MatrizA<<Matriz[i][j]<<"\n";
            

        }
    }
    // Cerrar los archivos creados
    MatrizA.close();   

    

}

int** lecturaMatriz_Archivo(string nombre, int filas, int columnas){

    ifstream archivo;
    archivo.open(nombre,ios::in); // Se abre el archivo en modo lectura ios::in
    if(archivo.fail()){
        cout<<"El archivo que contiene: "<<nombre<<", no se ha podido leer";
        exit(1);
    }
    int **Matriz = new int*[filas];
    for(int i =0; i<filas;i++){
        Matriz[i] = new int[columnas]; 
    }
    int vect[filas*columnas];
    for(int i = 0; i < filas; i++){
        for(int j = 0; j<columnas;j++){
            archivo >> Matriz[i][j];
        }

    }
    return Matriz;
}



    int* Convertir_Matriz_a_Vector(int **Matriz, int filas, int Columnas){
        int *Vector = new int[filas * Columnas];
        int index = 0;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < Columnas; j++) {
                Vector[index] = Matriz[i][j];
                index++;
        }
    }
    return Vector;


    }











    /*
    string tp;
    while(getline(archivo, tp)){ //read data from file object and put it into string.
        cout<<tp<<endl;
    }
    */
/*
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 5; ++j){
            archivo >> Matriz[i][j];
            archivo.ignore(256,' ');

        }
    }
*/



void leerMatriz(int **Matriz, int filas, int columnas){
    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            cout <<"\nM["<<i<<j<<"] = "<<Matriz[i][j];

            

        }
    }    

}

void leerVector(int *Vector, int tamano){
    for(int i = 0; i<tamano; i++){
        cout <<"\n"<<"V["<<i<<"]"<<"="<<Vector[i];     
    }    

}