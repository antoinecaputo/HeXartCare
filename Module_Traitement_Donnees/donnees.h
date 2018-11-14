#ifndef DONNEES_H
#define DONNEES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONNES 300

typedef struct donnees_aleatoires
{
    char *personne_nb;
    int frequence_cardiaque;
    int heure;
    int minutes;
    int secondes;
}D;

D donnees[301];

/*
enum temps_max
{
    heure_max=23,
    heure_min=0,
    minute_max=60,
    minute_min=0,
    seconde_max=60,
    seconde_min=0
};
*/
void nombre_lignes_csv(void);
void donnees_vers_structures(void);

#endif // DONNEES_H
