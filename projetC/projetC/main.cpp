//
//  main.cpp
//  projetC
//
//  Created by Nicolas Loridon on 07/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include <iostream>
#include "film.h"
#include <cstring>
using namespace std;

int main()
{
    t_personne real;
    t_personne   acteur1, acteur2;
    t_film     f;
    
    char letitre[100]="Usual Suspects";
    
    char nomr[100]      = "Singer";
    char prenomr[100]   = "Bryan";
    
    char noma1[100]     = "Spacey";
    char prenoma1[100]  = "Kevin";
    
    char noma2[100]     = "Byrne";
    char prenoma2[100]  = "Gabriel";
    
    f.titre = new char[strlen(letitre)+1];
    strcpy(f.titre,letitre);
    f.annee = 1995;
    f.duree = 106;
    f.genres[0] = POLICIER;
    f.genres[1] = ACTION;
    
    real.prenom = new char[strlen(prenomr)+1];
    real.nom    = new char[strlen(prenomr)+1];
    strcpy(real.prenom,prenomr);
    strcpy(real.nom,nomr);
    
    acteur1.prenom = new char[strlen(prenoma1)+1];
    acteur1.nom    = new char[strlen(noma1)+1];
    strcpy(acteur1.prenom,prenoma1);
    strcpy(acteur1.nom,noma1);
    
    acteur2.prenom = new char[strlen(prenoma2)+1];
    acteur2.nom    = new char[strlen(noma2)+1];
    strcpy(acteur2.prenom,prenoma2);
    strcpy(acteur2.nom,noma2);
    
    f.realis = &real;
    f.acteurs[0] = &acteur1;
    f.acteurs[1] = &acteur2;
    f.acteurs[2] = NULL;
    
    afficherFilm(f);
    cout << endl;
    
    return 0;
}
