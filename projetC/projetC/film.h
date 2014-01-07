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

#endif // FILM_H_INCLUDED
