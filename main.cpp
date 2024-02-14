/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: pcruchet
 *
 * Created on 14 février 2024, 10:43
 */

#include "Plateau.h"

using namespace std;

int main(int argc, char** argv)
{
    Plateau lePlateau("laFlotte.txt");
    lePlateau.Jouer();
    return 0;
}

