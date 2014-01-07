//
//  personne.cpp
//  projetC
//
//  Created by Nicolas Loridon on 07/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include "personne.h"

#include <iostream>

using namespace std;

void afficherDate(t_datenaiss d)
{
    char mois[12][10]={"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
    
    cout << d.jj << " ";
    cout << mois[d.mm-1] << " ";
    cout << d.aa;
    
    return;
}

void afficherPers(t_personne p, bool detailed)
{
    if (detailed == false)
    {
        cout << p.prenom << " " << p.nom;
    }
    else
    {
        cout << "Nom : " << p.prenom << " " << p.nom << endl;
        cout << "Date de naissance : ";
        afficherDate(p.daten);
        cout << endl;
        cout << p.natio;
    }
    
    return;
}

