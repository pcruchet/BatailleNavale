/* 
 * File:   testFlotte.cpp
 * Author: pcruchet
 *
 * Created on 14 février 2024, 10:16
 */

#include <iostream>
#include "Flotte.h"

using namespace std;

int main()
{
    Flotte laFlotte("laFlotte.txt");
    cout << "Nombre de bateaux  : " << laFlotte.ObtenirNbBateaux();
    cout <<endl;
    
    Bateau::ETATS_BATEAU resultat;
    bool sortie = false;

    char vertical;
    int horizontal;
    if (laFlotte.ObtenirNbBateaux() != 0)
    {
        do
        {
            cout << "Entrer les coordonnée de la torpille : ";
            cin >> vertical >> horizontal;
            resultat = laFlotte.TirerSurLaFlotte(vertical, horizontal);
            switch (resultat)
            {
            case Bateau::TOUCHE:
                cout << endl << "Bateau touché " << endl;
                cout << "rejoué" << endl;
                break;
            case Bateau::COULE:
                cout << endl << "Bateau coulé " << endl;
                if(laFlotte.VerifierEtatDeLaFlotte() != Bateau::COULE)
                    cout << "rejoué" << endl;
                else
                    sortie = true;
                break;
            case Bateau::MANQUE:
                cout << endl << "rejoué" << endl;
                break;
            }

        }
        while (sortie == false);
    }

    cout << endl << "Fin de la partie" << endl;

    return 0;
}

