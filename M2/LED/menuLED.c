#include "menuLED.h"
void menuLED ()
{
	
    /*
    on va reecrire a chaque fois selon le choix de l'utilisateur le param.h pour changer le mode
    */
	
    printf("-------------MENU LED---------------\n");

    	printf("0 : All");
	printf("1 : Une sur deux");
	printf("2 : Deux sur trois");
	printf ("3 : Chenille" );
	printf ("4 : Vague ");
	scanf ("%d",&mode);

}
