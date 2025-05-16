/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: carlos
 * 
 * Created on 16 de mayo de 2025, 13:27
 */

#include "Tablero.h"

using namespace std;

Tablero::Tablero(int f, int c, int numbombas){
    inicializarTablero(f, c, numbombas);

}
//se inicializan las matrices a 2 matrices vacías con todo a 0
void Tablero::inicializarVariables(int f, int c){
    
    tab.resize(f, c, 0);
    tab.inicializarMatriz(0);
    
    descubierto.resize(f, c, 0);
    descubierto.inicializarMatriz(0);
   
}

void Tablero::inicializarTablero(int f, int c, int numbombas){

    inicializarVariables(f, c);
    colocarBombas(numbombas);
    calculardistancias();
    
}

Tablero::Tablero(const Tablero & orig)
    : tab(orig.tab), descubierto(orig.descubierto) {
}
   
//muestra toda la información del tablero
string Tablero::mostrarTableroEntero(){
    string cad_tab;
    cad_tab=tab.matriztostring();
    return cad_tab;
}

Tablero::Tablero(){
inicializarTablero(7,7,10);
}

//muestra toda la información de lo que se ha abierto, lo que está cerrado
//y lo que está marcado
string Tablero::mostrarDescubierto(){
    string cad_tab;
    cad_tab=descubierto.matriztostring();
    return cad_tab;
 
}
//Muestra el tablero tal y como lo debe de ver el jugador en el juego.
string Tablero::mostrarTableroaJugador(){
    string cad="";
    
    for(int i=0; i<tab.numfilas(); i++){
        for(int j=0; j<tab.numcolumnas(); j++){
        
            if(descubierto.getValue(i, j)==0){
                cad+='?';
            }
            
            if(descubierto.getValue(i, j)==1){
                cad+=tab.getValue(i, j);
            }
            
            if(descubierto.getValue(i, j)==2){
                cad+='B';
                
            }
            cad+=" ";
        }
        cad+="\n";
    }
    
    return cad;
}

//este método coloca aleatoriamente las bombas por el tablero
void Tablero::colocarBombas(int numbombas){
    int i=0;
    int numeroaleatorio_fil, numeroaleatorio_col;

    while (i < numbombas){
        
        numeroaleatorio_fil=generarNumeroAleatorio(0,tab.numfilas()-1);
        numeroaleatorio_col=generarNumeroAleatorio(0,tab.numcolumnas()-1);

        if(tab.getValue(numeroaleatorio_fil, numeroaleatorio_col) != 9){    // Se pondrá la bomba solo si en la casilla no hay bomba
            tab.putValue(numeroaleatorio_fil, numeroaleatorio_col)=NUMBOMBA;
            i++;
        }
    }
}
//este metodo calcula el numero de bombas que hay alrededor de cada casilla
void Tablero::calculardistancias(){
    
    for(int i=0; i<tab.numfilas(); i++){
        for(int j=0; j<tab.numcolumnas(); j++){         // Recorre todas las casillas de la matriz
        
            if(tab.getValue(i, j)==NUMBOMBA){
                for (int k=i-1; k<=i+1; k++){
                    for (int h=j-1; h<=j+1; h++){       // Recorre las casillas que rodean a la casilla donde se encuentra la bomba
                       
                        if(en_rango(0, tab.numfilas(), k) && en_rango(0, tab.numcolumnas(), h)){    // Controla que no se accedan a valores fuera de la memoria
                            if(tab.getValue(k, h)!=NUMBOMBA){                                       // En caso de que haya una boma en la casilla no se sumará nada
                                tab.putValue(k, h)+=1;
                            }
                        }
                    }
                }
            }
        }
    }
   
}

 void Tablero::saveFichero(string fich){
     ofstream fich_entrada;
     string ruta = ruta_datos+fich;
     fich_entrada.open(ruta);
     if(fich_entrada.is_open()){
         fich_entrada << tab.numfilas() << " " << tab.numcolumnas() << "\n" << tab.matriztostring() << "\n" << descubierto.matriztostring();
     }
     fich_entrada.close();
 }
 
 void Tablero::loadFichero(string fich){
    ifstream fichero;
    int fil, col;
    string ruta = ruta_datos+fich;
    fichero.open(ruta);
    if(fichero.is_open()){
        fichero >> fil >> col;  // Lee el número de filas y columnas
        
        tab.resize(fil, col, 0);
        descubierto.resize(fil, col, 0);
        
        for (int i = 0; i < tab.numfilas(); i++){
            for (int j = 0; j < tab.numcolumnas(); j++){
                fichero >> tab.putValue(i, j);  // Lee cada valor de la matriz tab
            }
        }
        
        for (int i = 0; i < descubierto.numfilas(); i++){
            for (int j = 0; j < descubierto.numcolumnas(); j++){
                fichero >> descubierto.putValue(i, j);  // Lee cada valor de la matriz descubierto
            }
        }
    }else{
                cerr << "No se pudo abrir el archivo " << fich << endl;
    }
    fichero.close();
}
 
 int Tablero::generarNumeroAleatorio(int min, int max) {
     random_device generador;
     uniform_int_distribution<int> distributionnum(min, max);
     return distributionnum(generador);
}
 
 bool Tablero::en_rango(int min, int max, int valor){
     bool rango;
     rango=(min<=valor && valor<max);
     return rango;
 }
 
 bool Tablero::haganado() {
     bool hagando;
     int i=0;
     int j=0;
     haganado=true;
     
     while(haganado==true && i<tab.numfilas()){
         while(haganado==true && j<tab.numcolumnas()){
             if(descubierto[i][j]==0 || (tab[i][j]==9 && descubierto[i][j]!=2) || (tab[i][j]!=9 && descubierto[i][j]==2))
                 haganado=false    
             i++; 
         }
         j++;
     }
     
     return haganado;
 }
 