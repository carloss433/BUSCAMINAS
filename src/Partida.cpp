/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Partida.cpp
 * Author: carlos
 * 
 * Created on 16 de mayo de 2025, 16:54
 */

#include "Partida.h"

    Partida::Partida(Tablero & newtab, ConjuntoJugadores & newjug) {
        tab=newtab;
        jugs=newjug;
    }
    Partida::Partida(string fich, int fils, int cols, int numbombas, string nickjugador) {
        inicializaPartida(fich, fils, cols, numbombas, nickjugador);
    }
    Partida::Partida(const Partida& orig) {
        this->tab=orig.tab;
        this->jugs=orig.jugs;
        this->nickjugador=orig.nickjugador;
        this->fichero=orig.fichero;
    }
    Partida::~Partida() {
        
    }
    
    bool Partida::turno() {
        
        bool hasperdido;
        int fil, col, accion;
        accion = -1;
        fil = -1;
        col = -1;
        cout << tab.mostrarTableroJugador();

        while (!tab.en_rango(0, tab.getNumfilas(), fil) || !tab.en_rango(0, tab.getNumcolumnas(), col)){
            cout << " Indica la posición de la matriz sobre la que quieres actuar" << "\n" << "fila columna" << "\n";
            cin >> fil >> col;
        }
        
        while (accion !=0 && accion!=1 && accion!=2){
            cout << "Indica la accion a realizar:(0: abrir posición, 1: marcar posición, 2: desmarcar posición)" << "\n";
            cin >> accion;
        }
        
        if (accion==0){
            hasperdido=tab.abrirpos(fil, col);
        }else if (accion==1)
            tab.marcarpos(fil, col);
        else if (accion=2)
            tab.desmarcarpos(fil, col);
        
        return hasperdido;
    }
    
    void Partida::inicializaPartida(string fich, int fils, int cols, int numbombas, string nick) {
        Tablero newtab(fils, cols, numbombas);        
        fichero=fich;
        loadJugadores();
        tab=newtab;
        nickjugador=nick;
        
        cout << jugs.mostrarRanking();
        
    }
    void Partida::saveJugadores() {
        ofstream fich;
        fich.open(fichero);
        if (fich.is_open()){
            fich << jugs;
        }
        
        fich.close();
    }
    void Partida::loadJugadores() {
        ifstream fich;
        fich.open(fichero);
        if (fich.is_open()){
            fich >> jugs;
        }
        fich.close();
    }
    void Partida::realizaPartida() {
            
                    cout << tab.mostrarTableroEntero()  << "\n";
        
        bool sigue;
        
        sigue=turno();
        
        while (!tab.haganado() && !sigue){
            cout << tab.mostrarTableroEntero()  << "\n";
            turno();
        }
        
        if (jugs.buscaJugador(nickjugador)==-1) {
            Jugador newjug(jugs.numJugadores()+1, nickjugador);
            jugs+=newjug;
        }

        
        if (tab.haganado()==true){
            cout << "¡¡¡HAS GANADO!!!";
            jugs[jugs.buscaJugador(nickjugador)].numPartidasGanadas()+=1;
        }else if (sigue==false){
            cout << "HAS PERDIDO:\(";
            jugs[jugs.buscaJugador(nickjugador)].numPartidasPerdidas()+=1;
            tab.mostrarTableroEntero();
        }
        
        cout << jugs.mostrarRanking();
        
        saveJugadores();
        
    }