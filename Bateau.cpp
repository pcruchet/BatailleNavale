/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bateau.cpp
 * Author: pcruchet
 * 
 * Created on 14 février 2024, 08:08
 */

#include <valarray>

#include "Bateau.h"

Bateau::Bateau(const string &_nom, const char _vertical, const int _horizontal, const int _taille, const char _sens) :
nom(_nom),
vertical(_vertical),
horizontal(_horizontal),
taille(_taille),
sens(_sens),
etatDuBateau(MANQUE)
{
    coque = new int [taille];
    for (int indice = 0; indice < taille; indice++)
        coque[indice] = 0;
}

Bateau::~Bateau()
{
    delete [] coque;
}

Bateau::ETATS_BATEAU Bateau::Torpiller(const char _vertical, const int _horizontal)
{
    ETATS_BATEAU retour = MANQUE;
    if (sens == 'V')
    {
        if (horizontal == _horizontal)
        {
            if (vertical <= _vertical && (_vertical <= vertical + taille - 1))
            {
                if (coque[_vertical - vertical] != 1)
                {
                    coque[_vertical - vertical] = 1;
                    retour = TOUCHE;
                    if (etatDuBateau != COULE)
                        etatDuBateau = TOUCHE;
                }

            }
        }
    }
    else
    {
        if(vertical == _vertical)
        {
            if(horizontal <= _horizontal && (_horizontal <= horizontal + taille - 1))
            {
                if(coque[_horizontal - horizontal] != 1)
                {
                    coque[_horizontal - horizontal] = 1 ;
                    retour = TOUCHE;
                    if(etatDuBateau != COULE)
                        etatDuBateau = TOUCHE;
                }
            }
        }
    }
    if(retour == TOUCHE)
    {
        int nbTouches = 0;
        for(int indice = 0 ; indice < taille ; indice++)
            nbTouches += coque[indice];
        
        if(nbTouches == taille)
        {
            retour = COULE;      
            etatDuBateau = COULE;
        }
    }
    
    return retour;
}

string Bateau::ObtenirNom()
{
    return nom;
}

Bateau::ETATS_BATEAU Bateau::ObtenirEtatBateau()
{
    return etatDuBateau;
}
