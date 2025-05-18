/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 9 de mayo de 2025, 16:36
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "ConjuntoJugadores.h"
#include "Jugador.h"
#include "MatrizEnteros.h"
#include "Partida.h"
#include "Tablero.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int filas, columnas, minas;
    string nickJugador, fichero;
    
    for (int i = 1; i < argc; i += 2) {
        string arg = argv[i];
        if (arg == "-f") {
            filas = stoi(argv[i + 1]);
        } else if (arg == "-c") {
            columnas = stoi(argv[i + 1]);
        } else if (arg == "-m") {
            minas = stoi(argv[i + 1]);
        } else if (arg == "-nick") {
            nickJugador = argv[i + 1];
        } else if (arg == "-fich") {
            fichero = argv[i + 1];
        } else {
            cerr << "Argumento no reconocido: " << arg << endl;
            exit;
        }
    }

    Partida partida(fichero, filas, columnas, minas, nickJugador);
    
    partida.realizaPartida();
    
    return 0;
}

