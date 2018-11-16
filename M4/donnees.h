#ifndef DONNEES_H
#define DONNEES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//nombre de lignes du csv (et taille max du tableau de structures)
#define SIZE_INDEX 301

//d�claration de la structure dans laquelle iront les donn�es du csv
typedef struct donnees_aleatoires
{
    char personne_nb[20]; //valeur arbitraire de 20, estim�e assez large pour contenir "Personne_#"
    int frequence_cardiaque;
    int temps_ms;
}D;

//d�claration de la structure donnees de type D que nous allons utiliser
D donnees[SIZE_INDEX];

//prototypes des fonctions
void lire_csv(void);
void nombre_lignes_csv(void);
void placer_dans_struct(void);

#endif // DONNEES_H
