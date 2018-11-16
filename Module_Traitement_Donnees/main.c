#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

int main()
{
    int choix_csv,check=0;
    int i, choix_action, choix_variable,choix_ordre_tri;
    int *tableau;
    tableau=malloc(sizeof(int)*SIZE_INDEX);

    do
    {
        printf("\nBienvenue.\nQue voulez-vous faire ?\n \
            0: Fermer le gestionnaire de .csv\n \
            1: Afficher les donnees du fichier .csv\n \
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
    /*
    int choix_traitement;

    do
    {
        printf("\n")
    }while(choix_traitement!=0);
    */

    //exécution d'un tri par ordre croissant


        printf("\nVous pouvez traiter les donnees du .csv dans ce menu.\n");
        printf("\nVoulez-vous :\n \
               0: Quitter le programme\n \
               1: Trier les donnees (par ordre croissant/decroissant)\n \
               2: Rechercher des frequences cardiaques dans une plage de temps\n \
               3: Afficher la frequence cardiaque minimum/maximum ?\n");
        scanf("%d",&choix_action);
        printf("\nVoulez-vous faire un tri fusion des frequences cardiaques (0) ou par temps (ms) (1) ?\n");
        scanf("%d",&choix_variable);

        printf("\n0: Tri par ordre croissant\n1: Tri par ordre decroissant\n");
        scanf("%d",&choix_ordre_tri);

        transferer_tab_struct(tableau,choix_variable,0);
        tri_fusion(tableau,SIZE_INDEX,choix_ordre_tri);
        transferer_tab_struct(tableau,choix_variable,1);

        printf("\nLe tableau a ete trie par ordre croissant :\n");
        if(choix_variable==0)
        {
            printf("\n--------------------\n");
            for(i=0;i<SIZE_INDEX;i++)
            {
                printf(" %d /",donnees[i].frequence_cardiaque);
            }
        }
        else if (choix_variable==1)
        {
            printf("\n--------------------\n");
            for(i=0;i<SIZE_INDEX;i++)
            {
                printf(" %d /",donnees[i].temps_ms);
            }
        }
        else
        {
            printf("\nSaisie incorrecte\n");
            exit(-1);
        }
    }while(choix_csv!=0 && choix_action!=0);

    printf("\n");

    return 0;
}
