/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: carlos
 * 
 * Created on 16 de mayo de 2025, 13:26
 */

#include "MatrizEnteros.h"
#include <iostream>
using namespace std;


int MatrizEnteros::numfilas(){
    return filas;
}


int MatrizEnteros::numcolumnas(){
    return columnas;
}


int & MatrizEnteros:: putValue(int fil, int col){
    if((fil>=0 && fil<filas)&&(col>=0 && col<columnas)){     // Controla que no se accedan a valores fuera de la memoria
        return m[fil][col];
    }else{
        cerr << "Error de acceso" << endl;     
        exit;
    }
}


int MatrizEnteros::getValue(int fil, int col) const{
    if((fil>=0 && fil<filas)&&(col>=0 && col<columnas)){    // Controla que no se accedan a valores fuera de la memoria
        return m[fil][col];
    }else{
        cerr << "Error de acceso" << endl;     
        exit;
    }
}



MatrizEnteros::MatrizEnteros(int fil, int col, int def) {
    filas = fil;
    columnas = col;
    m = new int * [fil];
    for(int i=0; i<fil; i++){
        m[i] = new int[col];        // Inicializa la matriz
        
        for(int j=0; j<col; j++){
            m[i][j] = def;          // Asigna el valor def a cada elemento de la matriz
        }
    }
}


void MatrizEnteros::inicializarMatriz(int def){
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas; j++){
            m[i][j] = def;
        }
    }  
}


MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {
    filas = orig.filas;
    columnas = orig.columnas;
    m = new int*[filas];  // Reservar memoria
    
    for (int i = 0; i < filas; i++) {
        m[i] = new int[columnas];                // Inicializa la matriz copia
        
        for (int j = 0; j < columnas; j++) {     // Copia los valores de la matriz original
            m[i][j] = orig.m[i][j];
        }
    }
}


MatrizEnteros::~MatrizEnteros() {
    if (m != nullptr) {
        for (int i = 0; i < filas; i++) {
            delete[] m[i];                  // Libera cada fila
        }
        delete[] m;                         // Libera el puntero de punteros a filas
    }
}



string MatrizEnteros::matriztostring(){
    string cadmatriz ="";
    
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas; j++){
            cadmatriz= cadmatriz + to_string(m[i][j]) + " ";
        }
        cadmatriz = cadmatriz + "\n";
    }
    return cadmatriz;
}


void MatrizEnteros::resize(int newf, int newc, int value){
    int ** nuevaMatriz;
    nuevaMatriz = new int * [newf];
    
    for (int i=0; i<newf; i++){
        nuevaMatriz[i] = new int[newc];  // Inicializamos una nueva matriz con el tamaño especificado
                
            for (int j=0; j<newc; j++){
                if (i<filas && j<columnas){
                    nuevaMatriz[i][j]=m[i][j];  // Asignamos los valores de la matriz original m a la redimensionada nuevaMatriz
                }else{
                    nuevaMatriz[i][j]=value;    // En caso de que nuevaMatriz sea mas grande que m a las nuevas casillas se le asignara el el valor value
                }
            }        
    }
    
    for (int i = 0; i < filas; i++) {
        delete[] m[i];
    }
    delete[] m;
    
    m = nuevaMatriz;
    filas = newf;
    columnas = newc;
}

