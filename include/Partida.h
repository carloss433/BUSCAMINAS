/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Partida.h
 * Author: carlos
 *
 * Created on 16 de mayo de 2025, 16:54
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <fstream>
#include "ConjuntoJugadores.h"
#include "Tablero.h"

using namespace std;

class Partida {
public:
    Partida(Tablero & newtab, ConjuntoJugadores & newjug);
    Partida(string fich, int fils, int cols, int numbombas, string nickjugador);
    Partida(const Partida& orig);
    virtual ~Partida();
    
    bool turno();
    void inicializaPartida(string fich, int fils, int cols, int numbombas, string nick);
    void saveJugadores();
    void loadJugadores();
    void realizaPartida();
    
    
private:
    Tablero tab;
    ConjuntoJugadores jugs;
    string nickjugador;
    string fichero;
    

};

#endif /* PARTIDA_H */

