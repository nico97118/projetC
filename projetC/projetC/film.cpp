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

void initFilm(t_film* film,const char* titre, long annee,long duree,t_personne* real,t_genre genre1,t_genre genre2, t_personne* acteur1 ,t_personne* acteur2 , t_personne* acteur3, t_personne* acteur4)
{
    film->titre = new char[strlen(titre)+1];
    strcpy(film->titre, titre);
    
    film->duree = duree;
    film->annee = annee;
    
    film->realis = real;
    
    film->genres[0] = genre1;
    film->genres[1] = genre2;
    
    film->acteurs[0] = acteur1;
    film->acteurs[1] = acteur2;
    film->acteurs[2] = acteur3;
    film->acteurs[3] = acteur4;
}
