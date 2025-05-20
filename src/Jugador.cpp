/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Jugador.cpp
 * Author: carlos
 * 
 * Created on 9 de mayo de 2025, 17:10
 */

#include "Jugador.h"

// Constructor por defecto
Jugador::Jugador() : id(0), nick(""), numpartidasganadas(0), numpartidasperdidas(0) {}

// Constructor por copia
Jugador::Jugador(const Jugador& orig) {
    id = orig.id;
    nick = orig.nick;
    numpartidasganadas = orig.numpartidasganadas;
    numpartidasperdidas = orig.numpartidasperdidas;
}

// Destructor
Jugador::~Jugador() {
    // No se usa memoria dinámica
}

// Constructor con id y nick
Jugador::Jugador(int ide, string nuevoNick) {
    id = ide;
    nick = nuevoNick;
    numpartidasganadas = 0;
    numpartidasperdidas = 0;
}

string Jugador::getNick() {
    return nick;
}

int& Jugador::numPartidasGanadas() {
    return numpartidasganadas;
}

int& Jugador::numPartidasPerdidas() {
    return numpartidasperdidas;
}

int Jugador::numPartidasJugadas() const {
    return numpartidasganadas + numpartidasperdidas;
}

int Jugador::getId() const {
    return id;
}

int& Jugador::setId() {
    return id;
}

int Jugador::getnumPartidasGanadas() const {
    return numpartidasganadas;
}

Jugador& Jugador::operator=(const Jugador& orig) {
    if (this != &orig) {
        id = orig.id;
        nick = orig.nick;
        numpartidasganadas = orig.numpartidasganadas;
        numpartidasperdidas = orig.numpartidasperdidas;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& flujo, const Jugador& jug) {
    flujo << jug.id << " " << jug.nick << " " << jug.numpartidasganadas << " " << jug.numPartidasJugadas();
    return flujo;
}

// Operadores de comparación basados en proporción ganadas/jugadas

bool operator==(const Jugador& izq, const Jugador& dch) {
    int totalIzq = izq.numPartidasJugadas();
    int totalDch = dch.numPartidasJugadas();
    if (totalIzq == 0 && totalDch == 0) return true;
    if (totalIzq == 0 || totalDch == 0) return false;
    return (double)izq.getnumPartidasGanadas() / totalIzq == (double)dch.getnumPartidasGanadas() / totalDch;
}


bool operator!=(const Jugador& izq, const Jugador& dch) {
    return !(izq == dch);
}

bool operator<(const Jugador& izq, const Jugador& dch) {
    int totalIzq = izq.numPartidasJugadas();
    int totalDch = dch.numPartidasJugadas();
    if (totalIzq == 0 && totalDch == 0) return false;
    if (totalIzq == 0) return true;
    if (totalDch == 0) return false;
    return (double)izq.getnumPartidasGanadas() / totalIzq < (double)dch.getnumPartidasGanadas() / totalDch;
}

bool operator>(const Jugador& izq, const Jugador& dch) {
    return dch < izq;
}

bool operator<=(const Jugador& izq, const Jugador& dch) {
    return !(dch < izq);
}

bool operator>=(const Jugador& izq, const Jugador& dch) {
    return !(izq < dch);
}

double Jugador::getRatio() const {
    int jugadas = numpartidasganadas+numpartidasperdidas;
    if (jugadas == 0)
        return 0.0;
    else
        return static_cast<double>(numpartidasganadas) / jugadas;
}
