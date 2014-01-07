//
//  personne.h
//  projetC
//
//  Created by Nicolas Loridon on 07/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

typedef struct s_datenaiss
{
    long jj,mm,aa;
} t_datenaiss;

typedef struct s_personne
{
    char    *nom;
    char    *prenom;
    t_datenaiss daten;
    char    *natio;
} t_personne;

void    afficherDate(t_datenaiss);
void    afficherPers(t_personne, bool);
void initPersonne(t_personne* personne,const char* prenom,const char* nom,const char* natio, long jn,long mn,long an);


#endif // PERSONNE_H_INCLUDED
