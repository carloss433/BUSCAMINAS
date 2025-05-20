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
        cout << "\n\n\n\n\n\n\n\n\n\n"<< "EL BUSCAMINAS" <<"\n\n\n" << tab.mostrarTableroJugador() << "\n";

        while (!tab.en_rango(0, tab.getNumfilas(), fil) || !tab.en_rango(0, tab.getNumcolumnas(), col)){
            cout << "Indica la posición de la matriz sobre la que quieres actuar" << "\n" << "fila columna" << "\n";
            cin >> fil >> col;
        }
        
        while (accion !=0 && accion!=1 && accion!=2){
            cout << "Indica la accion a realizar:(0: abrir posición, 1: marcar posición, 2: desmarcar posición)" << "\n";
            cin >> accion ;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
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
        
        bool haperdido;
        haperdido=false;
        
        while (!tab.haganado() && !haperdido){

           haperdido=turno();
        }
        
        if (jugs.buscaJugador(nickjugador)==-1) {
            Jugador newjug(jugs.numJugadores()+1, nickjugador);
            jugs+=newjug;
        }

        
        if (tab.haganado()==true){
            cout << "¡¡¡HAS GANADO!!!" << "\n";
            jugs[jugs.buscaJugador(nickjugador)].numPartidasGanadas()+=1;
            cout << tab.mostrarTableroJugador() << "\n";
        }else if (haperdido==true){
            cout << "HAS PERDIDO:\(" << "\n";
            jugs[jugs.buscaJugador(nickjugador)].numPartidasPerdidas()+=1;
            cout << tab.mostrarTableroEntero() << "\n";
        }
        
        cout << jugs.mostrarRanking();
        
        saveJugadores();
        
    }