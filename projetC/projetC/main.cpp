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

#define NB_FILM 10
#define NB_ACTEUR 20
#define NB_REAL 10
using namespace std;

void initbdd();
t_personne* rechercheActeur(const char* search);
t_personne* rechercheReali(const char* search);
t_personne* rechercheNom(const char* search);
int playinthis(t_personne* act,t_film* film);
t_film* rechercheFilm(const char* search);
void filmographie(t_personne* search,long annee =-1);
void filmographie(const char* search,long annee = -1);
void filmographie(e_genre genre);
void filmographie(long annee);

t_personne real[NB_REAL];
t_personne   acteurs[NB_ACTEUR];
t_film     films[NB_FILM];

int main()
{
    initbdd();
    
     filmographie(2010);
    cout<<endl;
    filmographie("Leonardo",2012);
    
    return 0;
}

t_personne* rechercheActeur(const char* search)
{
    for(int i = 0;i<NB_ACTEUR;i++)
    {
        if(strcmp(search ,acteurs[i].nom)== 0 || strcmp(search, acteurs[i].prenom) == 0)
           return &acteurs[i];

    }
    return NULL;
}

t_personne* rechercheReali(const char* search)
{
    for(int i =0;i<NB_REAL;i++)
        if(strcmp(search,real[i].nom) == 0|| strcmp(search,real[i].prenom) == 0)
            return &real[i];
    return NULL;
}

t_personne* rechercheNom(const char* search)
{
    if(rechercheActeur(search))
        return rechercheActeur(search);
    else if (rechercheReali(search))
        return rechercheReali(search);
    else
        return NULL;
}

t_film* rechercheFilm(const char* search)
{
    for (int i=0;i<NB_FILM;i++)
        if(strcmp(search,films[i].titre)==0)
            return &films[i];
    return NULL;
}

int playinthis(t_personne* act,t_film* film) // retourne 1 si l'acteur joue dans ce film
{
    for(int i = 0; i<4 ; i++)
        if (act == film->acteurs[i])
            return 1;
    return 0;
}

void filmographie(t_personne* search,long annee) // affiche la filmographie de la personne
{
    cout<<"    Filmographie de ";
    afficherPers(*search, false);
    cout<<endl;
    for(int i=0;i<NB_FILM;i++)
    {
        if(search == films[i].realis ||  playinthis(search,&films[i]) )
        {
            if(annee<0 || films[i].annee <= annee)
            {
            cout<<endl;
            afficherFilm(films[i]);
            cout<<endl;
            }
        }
    }
}

void filmographie(const char* search, long annee)
{
    if(rechercheNom(search))
        filmographie(rechercheNom(search),annee);
    
}

void filmographie(long annee)
{
    cout<<"   Les films plus vieux que :"<<annee<<endl<<endl;
    for(int i=0;i<NB_FILM;i++)
    {
        if(films[i].annee <= annee && films[i].annee>0)
        {
            cout<<endl;
            afficherFilm(films[i]);
            cout<<endl;
        }
    }
}

void filmographie(e_genre genre)
{
    cout<<"   Les Films du genre :"; afficherGenre(genre);cout<<endl;
    for(int i=0;i<NB_FILM;i++)
        if (films[i].genres[0] == genre || films[i].genres[1] == genre)
        {
            cout<<endl;
            afficherFilm(films[i]);
            cout<<endl;
        }
}

void initbdd()
{
    initPersonne(&acteurs[0], "Spacey", "kevin", "americain",0,0,0);
    initPersonne(&acteurs[1], "Byrne", "Gabriel", "americain", 0, 0, 0);
    initPersonne(&acteurs[2], "Leonardo", "Di Caprio", "americain", 0, 0, 0);
    initPersonne(&acteurs[3], "Sandra", "Bullock", "americaine", 0, 0, 0);
    initPersonne(&acteurs[4], "George", "Clooney", "americain", 0, 0, 0);
    initPersonne(&acteurs[5], "Jean", "Du Jardin", "francais", 0, 0, 0);
    initPersonne(&acteurs[6], "Marion", "Cottillard", "francaise", 0, 0, 0);
    initPersonne(&acteurs[7], "Robert", "Doney Jr", "americain", 0, 0, 0);
    initPersonne(&acteurs[8], "Vin", "Diesel", "americain", 0, 0, 0);
    initPersonne(&acteurs[9], "Paul", "Walker", "americain", 0, 0, 0);
    initPersonne(&acteurs[10], "Brad", "Pitt", "americain", 0, 0, 0);
    initPersonne(&acteurs[11], "Natalie", "Portman", "americaine", 9, 6, 1981);
    initPersonne(&acteurs[12], "Jose", "Garcia", "Francais", 0, 0, 0);
    
    initFilm(&films[0], "les Seigneurs", 2012, 80,&real[0],COMEDIE,AUCUN,&acteurs[12]);
    initFilm(&films[1], "La Verité si je mens 3", 2012, 120,&real[1],COMEDIE,AUCUN,&acteurs[12]);
    initFilm(&films[2], "Fast and Furious",2001,102,&real[2],ACTION,COMEDIE,&acteurs[8],&acteurs[9]);
    initFilm(&films[3], "Inception", 2010, 148,&real[3],DRAME,SCIENCE_FICTION,&acteurs[2],&acteurs[6]);
    initFilm(&films[4], "Le loup de wallstreet", 2013, 179,&real[4],COMEDIE,DRAME,&acteurs[2],&acteurs[5]);
    initFilm(&films[5], "Gravity", 2013, 91,&real[5],DRAME,SCIENCE_FICTION,&acteurs[3],&acteurs[4]);
    initFilm(&films[6], "Thor", 2011, 115,&real[6],ACTION,FANTASTIQUE,&acteurs[11],&acteurs[10]);
    
    
    initPersonne(&real[0], "Olivier", "Dahan", "francais", 0, 0, 0);
    initPersonne(&real[1], "Thomas", "Gilou", "francais", 0, 0, 0);
    initPersonne(&real[2], "Rob", "Cohen", "americain", 0, 0, 0);
    initPersonne(&real[3], "Christopher", "Nolan", "britanique", 0, 0, 0);
    initPersonne(&real[4], "Martin", "Scoresse", "americain", 0,0, 0);
    initPersonne(&real[5],"Alfonso","Cuaron","mexique",28,11,1961);
    initPersonne(&real[6],"Kenneth","Branagh","americain",10,12,1960);
}