//
//  film.h
//  projetC
//
//  Created by Nicolas Loridon on 07/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include "personne.h"



typedef enum e_genre
{
    AUCUN,
    ACTION,
    HORREUR,
    COMEDIE,
    FANTASTIQUE,
    DOCUMENTAIRE,
    POLICIER,
    DRAME,
    ANIMATION,
    SCIENCE_FICTION
} t_genre;

typedef struct s_film
{
    char        *titre;
    long        annee;
    t_personne  *realis;
    t_personne  *acteurs[4];
    long        duree; // duree en minutes
    t_genre     genres[2];
} t_film;

void afficherGenre(t_genre);
void afficherFilm(t_film);
void initFilm(t_film* film,const char* titre, long annee,long duree,t_personne* real=0,t_genre genre1=AUCUN,t_genre genre2=AUCUN, t_personne* acteur1=0,t_personne* acteur2=0, t_personne* acteur3=0, t_personne* acteur4= 0);

#endif // FILM_H_INCLUDED
