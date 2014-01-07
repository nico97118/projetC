//
//  film.cpp
//  projetC
//
//  Created by Nicolas Loridon on 07/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include "film.h"
#include "personne.h"
#include <iostream>

using namespace std;

void afficherGenre(t_genre g)
{
    char nomgenre[9][20]={"aucun","Action","Horreur","Comedie","Documentaire","Policier","Drame","Animation","Science-Fiction"};
    
    cout << nomgenre[g];
    
    return;
}

void afficherFilm(t_film f)
{
    long cptact;
    
    cout << f.titre << " (" << f.annee << ")" << endl;
    cout << "Realisateur : ";
    afficherPers(*(f.realis),false);
    cout << endl;
    
    
    cptact = 0;
    
    cout << "Acteurs : ";
    
    while ((cptact < 4) && (f.acteurs[cptact] != NULL))
    {
        if (cptact >0)
        {
            cout << ", ";
        }
        
        afficherPers(*(f.acteurs[cptact]),false);
        cout << " ";
        cptact = cptact+1;
    }
    
    cout << endl;
    cout << "Duree : " << (f.duree/60) << "h" << (f.duree % 60) << endl;
    cout << "Genre : ";
    afficherGenre(f.genres[0]);
    
    if (f.genres[0] != AUCUN)
    {
        cout << ", ";
        afficherGenre(f.genres[1]);
    }
    
    return;
}

