/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Plateau.h
 * Author: pcruchet
 *
 * Created on 14 février 2024, 10:30
 */

#ifndef PLATEAU_H
#define PLATEAU_H

#include "Flotte.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Plateau {
public:
    Plateau(const string &_nomDuFichier);
    void AfficherGrille();
    void Tirer(const char _vertical, const int _horizontal, const bool _cible);
    void Jouer();
private:
    char grille[10][10];
    Flotte laFlotte;

};

#endif /* PLATEAU_H */

