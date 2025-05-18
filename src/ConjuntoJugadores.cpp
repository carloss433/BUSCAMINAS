/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ConjuntoJugadores.cpp
 * Author: carlos
 * 
 * Created on 9 de mayo de 2025, 17:10
 */

#include "ConjuntoJugadores.h"

// Constructor con tamaño reservado
ConjuntoJugadores::ConjuntoJugadores(int k) {
    tamreservado = k;
    vectorJugadores = new Jugador[tamreservado];
    numjugadores = 0;
}

// Constructor por copia
ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig) {
    tamreservado = orig.tamreservado;
    numjugadores = orig.numjugadores;
    vectorJugadores = new Jugador[tamreservado];
    for (int i = 0; i < numjugadores; ++i) {
        vectorJugadores[i] = orig.vectorJugadores[i];
    }
}

// Destructor
ConjuntoJugadores::~ConjuntoJugadores() {
    delete[] vectorJugadores;
}

// Constructor con vector de nicks
ConjuntoJugadores::ConjuntoJugadores(int n, string * vnicks) {
    tamreservado = n;
    numjugadores = n;
    vectorJugadores = new Jugador[tamreservado];
    for (int i=0; i<n; ++i) {
        vectorJugadores[i] = Jugador(i + 1, vnicks[i]);
    }
}

ConjuntoJugadores & ConjuntoJugadores::operator=(const ConjuntoJugadores & orig) {
    if (this != &orig) {
        delete[] vectorJugadores;
        tamreservado = orig.tamreservado;
        numjugadores = orig.numjugadores;
        vectorJugadores = new Jugador[tamreservado];
        for (int i=0; i<numjugadores; ++i) {
            vectorJugadores[i] = orig.vectorJugadores[i];
        }
    }
    return *this;
}

void ConjuntoJugadores::resize(int newtam) {
    if (newtam > tamreservado) {
        Jugador* nuevo = new Jugador[newtam];
        for (int i=0; i<numjugadores; ++i) {
            nuevo[i] = vectorJugadores[i];
        }
        delete[] vectorJugadores;
        vectorJugadores = nuevo;
        tamreservado = newtam;
    }
}

void ConjuntoJugadores::ordenaporId() {
    Jugador tmp;
    for (int i=0; i<numjugadores - 1; ++i) {
        for (int j=i+1; j<numjugadores; ++j) {
            if (vectorJugadores[i].getId() > vectorJugadores[j].getId()) {
                tmp = vectorJugadores[i];
                vectorJugadores[i] = vectorJugadores[j];
                vectorJugadores[j] = tmp;
            }
        }
    }
}

ConjuntoJugadores & ConjuntoJugadores::operator+=(const Jugador& newjug) {
    if (numjugadores == tamreservado) {
        resize(tamreservado + 5);
    }
    vectorJugadores[numjugadores] = newjug;
    vectorJugadores[numjugadores].setId()=numjugadores+1;
    numjugadores++;
    ordenaporId();
    return *this;
}

void ConjuntoJugadores::eliminaJugador(int jugid) {
    int pos = buscaJugador(jugid);
    if (pos != -1) {
        for (int i = pos; i < numjugadores - 1; ++i) {
            vectorJugadores[i] = vectorJugadores[i + 1];
            vectorJugadores[i].setId()=i+1;
        }
        numjugadores--;
    }
}

int ConjuntoJugadores::buscaJugador(int jugid) {
    for (int i=0; i<numjugadores; ++i) {
        if (vectorJugadores[i].getId() == jugid) 
            return i;
    }
    return -1;
}

int ConjuntoJugadores::buscaJugador(string nickbuscado) {
    for (int i=0; i<numjugadores; ++i) {
        if (vectorJugadores[i].getNick() == nickbuscado) 
            return i;
    }
    return -1;
}

Jugador & ConjuntoJugadores::operator[](int i) const {
    return vectorJugadores[i];
}

void ConjuntoJugadores::optimizar() {
    Jugador* nuevo = new Jugador[numjugadores];
    for (int i=0; i<numjugadores; ++i) {
        nuevo[i] = vectorJugadores[i];
    }
    delete[] vectorJugadores;
    vectorJugadores = nuevo;
    tamreservado = numjugadores;
}

int ConjuntoJugadores::numJugadores() const {
    return numjugadores;
}

string ConjuntoJugadores::mostrarRanking() {
    // Ordenar copia del array manualmente por rendimiento
    string resultado;
    ConjuntoJugadores ranking(numjugadores);
    Jugador tmp;
    for(int i=0; i<numjugadores; i++){
        ranking.vectorJugadores[i] = vectorJugadores[i];
        }

    for (int i=0; i<numjugadores - 1; ++i) {
        for (int j=i+1; j<numjugadores; ++j) {


            if (ranking.vectorJugadores[i].getRatio() < ranking.vectorJugadores[j].getRatio()) {
                tmp = ranking.vectorJugadores[i];
                ranking.vectorJugadores[i] = ranking.vectorJugadores[j];
                ranking.vectorJugadores[j] = tmp;
            }
        }
    }
    
    resultado+= to_string(numjugadores)+"\n";
    for (int i=0; i<numjugadores; ++i) {
        resultado += to_string(ranking.vectorJugadores[i].getId()) + " " + ranking.vectorJugadores[i].getNick() + " ";
        resultado += to_string(ranking.vectorJugadores[i].numPartidasGanadas()) + "/" + to_string(ranking.vectorJugadores[i].numPartidasJugadas());
        resultado += "\n";
    }

    return resultado;
}

ofstream & operator<<(ofstream & flujo, const ConjuntoJugadores & m) {
    flujo << m.numjugadores << "\n";
    for (int i=0; i<m.numjugadores; ++i) {
        flujo << m.vectorJugadores[i] << "\n";
    }
    return flujo;
}

ifstream & operator>>(ifstream & flujo, ConjuntoJugadores & m) {
    int n;
    flujo >> n;
    m.resize(n);
    for (int i=0; i<n; ++i) {
        int id, ganadas, perdidas;
        string nick;
        flujo >> id >> nick >> ganadas >> perdidas;
        Jugador j(id, nick);
        j.numPartidasGanadas() = ganadas;
        j.numPartidasPerdidas() = perdidas;
        m.vectorJugadores[i] = j;
    }
    return flujo;
}

ConjuntoJugadores operator+(const ConjuntoJugadores & left, const ConjuntoJugadores & right) {
    ConjuntoJugadores nuevo(left.numjugadores + right.numjugadores);
    for (int i=0; i<left.numjugadores; ++i){
        nuevo += left.vectorJugadores[i];
        nuevo[i].setId()=i+1;
    }
    for (int i=0; i<right.numjugadores; ++i){
        nuevo += right.vectorJugadores[i];
        nuevo[i+left.numjugadores].setId()=i+left.numjugadores+1;
    }
    return nuevo;
}
