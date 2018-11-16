#ifndef ACTIONS_H
#define ACTIONS_H

#include "donnees.h"

//fonction pour transf�rer un tableau de structures vers un tableau temporaire et inversement
void transferer_tab_struct(int*,int,int);

//calcul de la moyenne des pouls
float calcul_moyenne_pouls(void);

//affiche le minimum et le maximum des pouls de la structure de donnees
void min_et_max(void);

//fonctions du tri croissant/d�croissant utilisant la m�thode du tri fusion
void tri_fusion(int*,int,int);
void fusionner_croissant(int*,int*,int*,int);
void fusionner_decroissant(int*,int*,int*,int);

//fonction de recherche lin�aire
int recherche_lineaire(int);


#endif // ACTIONS_H
