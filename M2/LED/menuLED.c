#include "menuLED.h"
void menuLED ()
{
    FILE *fichier
    printf("-------------MENU LED---------------\n");
    fichier=fopen("param.h","w+")
    fprint(fichier,"")
    /*
    on va reecrire a chaque fois celon le choix e l'utilisateur le param.f pour changer le mode
    */

    printf("0 : All");
	printf("1 : Une sur deux");
	printf("2 : Deux sur trois");
	printf ("3 : Chenille" );
	printf ("4 : Vague ");
	scanf ("%d",&mode);

}
