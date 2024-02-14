/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flotte.h
 * Author: pcruchet
 *
 * Created on 14 février 2024, 09:33
 */

#ifndef FLOTTE_H
#define FLOTTE_H

#include <fstream>
#include <sstream>
#include <iostream>

#include "Bateau.h"

using namespace std;

class Flotte {
public:
    Flotte(const string &_nomDuFichier);
    ~Flotte();
    Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal);
    Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte();
    int ObtenirNbBateaux() const;
private:
    static const int NB_BATEAUX_MAX = 5;
    int nbBateaux;
    Bateau *lesBateaux[NB_BATEAUX_MAX];
};

#endif /* FLOTTE_H */

