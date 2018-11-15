#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

int main()
{
    int choix_csv,check=0;
    do
    {
        printf("\nBienvenue.\nQue voulez-vous faire ?\n \
            0: Fermer le gestionnaire de .csv\n \
            1: Lire le fichier .csv\n \
            2: Afficher le nombre de lignes du fichier .csv\n \
            3: Transferer les données du .csv vers la structure de données\n");
        printf("\n   > ");
        scanf("%d",&choix_csv);

        //évite de choisir plusieurs fois de transférer dans la structure, écrasement de données inutile
        if(choix_csv==3 && check==1)
        {
            printf("\nLes donnees ont deja ete transferees, action impossible.\n");
            choix_csv=4;
        }
        switch(choix_csv)
        {
            case 0:
                exit(0);
                break;
            case 1:
                lire_csv();
                break;
            case 2:
                nombre_lignes_csv();
                break;
            case 3:
                placer_dans_struct();
                check=1;
                break;
            default:
                printf("\nErreur lors de la saisie, veuillez recommencer.\n");
                break;
        }
    }while(choix_csv!=0);
    /*
    int choix_traitement;

    do
    {
        printf("\n")
    }while(choix_traitement!=0);
    */

    return 0;
}
