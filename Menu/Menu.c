#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu()
{
    printf(" Bonjour !\n\n Veuillez poser votre doigt dans le dispositif et appuyez sur entrer\n\n------------------<MENU> ---------------------\n");
     // a ce moment on fait lallumage des LED en CHAINE
     /*

     RECUPERATIN DE DONNEES DU POU

     */
    int choix;
    int ordre ;
    int critere ;
    int startTime;
    int endTime;
    int extrem;
    int age;


     printf("1 - \n");
     printf("2 - Affichage des donnees\n");
     printf("3 - Recherche de données en fonction du temps\n");
     printf("4 - Moyenne de pouls en fonction d'une plage de temps\n");
     printf("5 - Afficher le nombre de ligne de donnees actuellement en memoire\n");
     printf("6 - Afficher un extremum avec un temps associe\n");
     printf("7 - Diagnostique\n");
     printf("8 - Quitter \n");
    printf("QUE VOULEZ VOUS FAIRE : ");
     scanf(" %d",&choix);

     switch (choix){
     case 1:
     printf("Vous avez choisi le cas 1\n\n");

     break;
     case 2:

     printf("Vous avez choisi le cas 2\n\n");
     printf("En fonction du (1)temps ou du (2)pouls ?\n");
     scanf("%d",&critere);
     printf("Dans quelle ordre voulez vous afficher vos donees ?\n (1)croissant  (2)decroissant \n");
     scanf("%d",&ordre);

     if (critere == 1 && ordre == 1)
     {

     }

     else if (critere == 1 && ordre == 2)
     {

     }

     else if (critere == 2 && ordre == 1)
{

}
     else if (critere == 2 && ordre == 2)
{

}

     break;
     case 3:
     printf("Vous avez choisi le cas 3\n\n");

     printf("Choisissez une plage horaire\n");
     printf("Heure de debut ->");
     scanf("%d",&startTime);
     printf("\nHeure de fin ->");
     scanf("%d",&endTime);

     break;
     case 4:
     printf("Vous avez choisi le cas 4\n\n");

     printf("Vous avez choisi le cas 3\n\n");
     printf("Choisissez une plage horaire\n");
     printf("Heure de debut ->");
     scanf("%d",&startTime);
     printf("\nHeure de fin ->");
     scanf("%d",&endTime);
     printf("La moyenne de vos donnees \n")
     printf("%d",fctmoyenne());

     break;
     case 5:
     printf("Vous avez choisi le cas 5\n\n");
     printf("Le nombre de ligne %d",fctnbligne());

     break;
     case 6:
     printf("Vous avez choisi le cas 6\n\n");
     printf("Vous avez choisi le cas 3\n\n");
     printf("Choisissez une plage horaire\n");
     printf("Heure de debut ->");
     scanf("%d",&startTime);
     printf("\nHeure de fin ->");
     scanf("%d",&endTime);
     printf("Afficher un extremum (1) minimum / (2) maximum");
     scanf("%d",&extrem);
     if (extrem == 1 )
        else if
     break;
     case 7:
     printf("Vous avez choisi le cas 7\n\n");
     printf("Votre diagnostique vital\n");
     printf("veuiller indiquer votre age ->");
     scanf("%d",&age);
     printf("veuiller poser votre doigt dans le dispositif");
     /*
     calcul du puls
     */
     if (age<20)
     {
       if(pulse<80)
       {
        printf("vous etes en dessous de la moyenne");
       }
       else if (pulse>80 && pulse <125)
       {
        printf("vous etes dans la moyenne");
       }
       else if (pulse >125)
       {
        printf("vous etes au dessus de la moyenne");
       }
     }
     else if (age<30)
     {
       if(pulse<140)
       {
        printf("vous etes en dessous de la moyenne");
       }
       else if (pulse>140 && pulse <160)
       {
        printf("vous etes dans la moyenne");
       }
       else if (pulse >160)
       {
        printf("vous etes au dessus de la moyenne");
       }
     }
      else if (age<40)
     {
        if(pulse<130)
       {
        printf("vous etes en dessous de la moyenne");
       }
       else if (pulse>130 && pulse <152)
       {
        printf("vous etes dans la moyenne");
       }
       else if (pulse >152)
       {
        printf("vous etes au dessus de la moyenne");
       }
     }

      else if (age<50)
     {
         if(pulse<126)
       {
        printf("vous etes en dessous de la moyenne");
       }
       else if (pulse>126 && pulse <144)
       {
        printf("vous etes dans la moyenne");
       }
       else if (pulse >144)
       {
        printf("vous etes au dessus de la moyenne");
       }
     }

      else if (age<60)
     {
       if(pulse<119)
       {
        printf("vous etes en dessous de la moyenne");
       }
       else if (pulse>119 && pulse <136)
       {
        printf("vous etes dans la moyenne");
       }
       else if (pulse >136)
       {
        printf("vous etes au dessus de la moyenne");
       }
     }
     break;
     case 8:
     printf("Vous avez choisi le cas 8\n Vous avez choisis de quitter\n\n");
     return 0;
     break;
     }

    return 0;
}
