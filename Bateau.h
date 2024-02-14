/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bateau.h
 * Author: pcruchet
 *
 * Created on 14 février 2024, 08:08
 */



#ifndef BATEAU_H
#define BATEAU_H

#include <string>
using namespace std;

class Bateau {
public:
    enum ETATS_BATEAU
    {
        MANQUE,
        TOUCHE,
        COULE
    };

    Bateau(const string &_nom, const char _vertical, const int _horizontal, const int _taille, const char _sens='H');
    ~Bateau();
    ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal);
    string ObtenirNom();
    ETATS_BATEAU ObtenirEtatBateau();
private:
    string nom;
    char vertical;
    int horizontal;
    int taille;
    char sens;
    int * coque;
    ETATS_BATEAU etatDuBateau;
};

#endif /* BATEAU_H */

