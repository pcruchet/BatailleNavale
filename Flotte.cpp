/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flotte.cpp
 * Author: pcruchet
 * 
 * Created on 14 février 2024, 09:33
 */

#include "Flotte.h"
#include "Bateau.h"

Flotte::Flotte(const string &_nomDuFichier) :
nbBateaux(0)
{
    ifstream fichier(_nomDuFichier);
    int indice = 0;
    if (!fichier.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier " << endl;
    }
    else
    {
        string nom;
        string position;
        int taille;
        char sens;
        char lettre;
        int chiffre;
        do
        {
            fichier >> nom >> position >> taille >> sens;
            if (fichier.good() && indice < NB_BATEAUX_MAX)
            {
                lettre = position.front();
                stringstream ss(position.substr(1));
                ss >> chiffre;
                lesBateaux[indice++] = new Bateau(nom, lettre, chiffre, taille, sens);
            }
        }
        while (!fichier.eof() && indice < NB_BATEAUX_MAX);
        nbBateaux = indice;
    }
    while (indice < NB_BATEAUX_MAX)
    {
        lesBateaux[indice++] = nullptr;
    }
}

Flotte::~Flotte()
{
    for (int indice = 0; indice < nbBateaux; indice++)
        if (lesBateaux[indice] != nullptr)
            delete lesBateaux[indice];
}

Bateau::ETATS_BATEAU Flotte::TirerSurLaFlotte(const char _vertical, const int _horizontal)
{
    Bateau::ETATS_BATEAU retour = Bateau::MANQUE;
    int indice = 0;
    do
    {
        if (lesBateaux[indice] != nullptr)
        {
            retour = lesBateaux[indice]->Torpiller(_vertical, _horizontal);
        }
        indice++;
    }
    while (retour == Bateau::MANQUE && indice < nbBateaux);
    return retour;
}

Bateau::ETATS_BATEAU Flotte::VerifierEtatDeLaFlotte()
{
    Bateau::ETATS_BATEAU retour = Bateau::MANQUE;
    Bateau::ETATS_BATEAU resultat = Bateau::MANQUE;
    int cpt = 0;
    for (int indice = 0; indice < nbBateaux; indice++)
    {
        if (lesBateaux[indice] != nullptr)
        {
            resultat = lesBateaux[indice]->ObtenirEtatBateau();
            if (resultat == Bateau::COULE)
                cpt++;
            if (resultat == Bateau::TOUCHE)
                retour = Bateau::TOUCHE;
        }
    }

    if (cpt == nbBateaux)
        retour = Bateau::COULE;

    return retour;

}

int Flotte::ObtenirNbBateaux() const
{
    return nbBateaux;
}

