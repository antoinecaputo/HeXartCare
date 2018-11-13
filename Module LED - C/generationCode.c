#include "generationCode.h"

void creation_param_h(void)
{
    //Création et édition du fichier param.h

    FILE *parametre_ptr; //création du pointeur vers le fichier param.h

    parametre_ptr=fopen("param.h","w"); //création de param.h

    fprintf(parametre_ptr,"const byte IR = 0; // photo-transistor PIN A0\n"); //ligne 1
    fprintf(parametre_ptr,"byte mode = 0; // Mode d'allumage LED\n"); //ligne 2
    fprintf(parametre_ptr,"byte nLED = 9; //Nombre de LED\n"); //ligne 3
    fprintf(parametre_ptr,"\n/* MODE D'ECLAIRAGE DES LEDS\n0 : All\n1 : Une sur deux\
            \n3 : Chenille\n4 : Vague\n*/"); //ligne 4

}

