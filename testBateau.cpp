/* 
 * File:   main.cpp
 * Author: pcruchet
 *
 * Created on 14 février 2024, 08:07
 */

#include <iostream>
#include "Bateau.h"

using namespace std;

int main()
{
    char vertical;
    int horizontal;
    
    Bateau::ETATS_BATEAU torpille;
    //Bateau leBateau("Cuirassé",'H',5,4);
    Bateau leBateau("Croiseur",'C',3,3,'V');
    do
    {
        cout << "Entrer les coordonnée de la torpille : ";
        cin >> vertical >> horizontal;
        torpille = leBateau.Torpiller(vertical,horizontal);
        switch(torpille)
        {
        case Bateau::TOUCHE:
            cout << endl << "Bateau touché " << endl;
            cout << "rejoué" << endl;
            break;
        case Bateau::COULE:
            cout << endl << "Bateau coulé " << endl;
            break;
        case Bateau::MANQUE:
            cout << endl << "rejoué" << endl;
            break;
        }
        
    } while(torpille != Bateau::COULE);
    
    cout << endl << "Fin de la partie" << endl;
    
    
    return 0;
}

