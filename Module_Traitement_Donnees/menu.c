#include "menu.h"

void menu(void)
{
    //initialisation de la structure avec les valeurs du .csv
    placer_dans_struct();

    //déclaration des variables
    int choix_action,choix_variable,choix_ordre_tri,choix_temps,min_t,max_t,index, \
    tps_temp,index_min,index_max,i;
    float moyenne_pouls;
    int *tableau; //utilisation d'un tableau pour stocker temporairement les valeurs choisies de la struct

    //utilisation d'une boucle do pour répéter les actions tant que l'utilisateur n'aura pas entré 0
    do
    {
        //initialisation du tableau
        tableau=malloc(sizeof(int)*SIZE_INDEX);

        //affichage du menu
        printf("\nBienvenue dans le menu principal.\n\n \
            1 : Afficher les donnees du csv.\n \
            2 : Afficher le nombre de lignes du .csv en memoire\n \
            3 : Rechercher des pouls en fonction du temps (ms)\n \
            4 : Rechercher des pouls dans une plage de temps (ms)\n \
            5 : Faire la moyenne des pouls\n \
            6 : Afficher un extremum des pouls avec le temps associe\n \
            7 : Trier les donnees par ordre croissant/decroissant\n \
            \n \
            0 : Quitter le programme\n\n \
            Que voulez-vous faire ?\n");
        scanf("%d",&choix_action);

        //lancement des fonctions correspondantes au choix de l'utilisateur
        switch(choix_action)
        {
            //Affiche les donnees du csv
            case 1:
                lire_csv();
                printf("\n");
                break;
            //Affiche le nombre de lignes du csv
            case 2:
                nombre_lignes_csv();
                printf("\n");
                break;
            //Recherche des pouls en fonction du temps
            case 3:
                printf("\nEntrez le temps (en ms) :\n");
                scanf("%d",&choix_temps);
                index=recherche_lineaire(choix_temps);
                if(index==-1)
                {
                    printf("\nErreur, aucun resultat n'a ete trouve.\n");
                }
                else
                {
                    printf("\nDes resultats ont ete trouves !\n");
                    printf("\n-----------------\n");
                    for(i=index;i<index+1;i++)
                    {
                        printf("Pouls : %d bpm\tTemps : %d ms",donnees[i].frequence_cardiaque,donnees[i].temps_ms);
                    }
                }
                printf("\n");
                break;
            //Recherche des pouls en fonction d'une plage de temps
            case 4:
                printf("\nEntrez votre plage de temps (en ms):\nEntre : ");
                scanf("%d",&min_t);
                printf("Et : ");
                scanf("%d",&max_t);

                if(min_t>max_t)
                {
                    tps_temp=min_t;
                    min_t=max_t;
                    max_t=tps_temp;
                }

                printf("\nRecherche des pouls entre %d ms et %d ms...\n",min_t,max_t);
                index_min=recherche_lineaire(min_t);
                index_max=recherche_lineaire(max_t);
                if(index_min==-1||index_max==-1)
                {
                    printf("\nErreur, aucun resultat n'a ete trouve.\n");
                }
                else
                {
                    printf("\nDes resultats ont ete trouves !\n");
                    printf("\nLes resultats sont aux index %d\t %d\n",index_min,index_max);
                    printf("\n-----------------\n");
                    if(index_max>index_min)
                    {
                        tps_temp=index_max;
                        index_max=index_min;
                        index_min=tps_temp;
                    }
                    for(i=index_min;i<index_max;i++)
                    {
                       printf("Temps : %d ms\tPouls : %d\n",donnees[i].temps_ms,donnees[i].frequence_cardiaque);
                    }
                }
                printf("\n");
                break;
            //Calcul de la moyenne des pouls
            case 5:
                moyenne_pouls=calcul_moyenne_pouls();
                printf("\nLa moyenne des pouls du fichier .csv est de %.3f bpm.\n",moyenne_pouls);
                printf("\n");
                break;
            //Affichage du minimum et du maximum des pouls
            case 6:
                min_et_max();
                printf("\n");
                break;
            //Tri croissant ou décroissant du pouls ou du temps (ms)
            case 7:
                printf("\nVoulez-vous faire un tri fusion des pouls (0) ou par temps (ms) (1) ?\n");
                scanf("%d",&choix_variable);

                printf("\n0: Tri par ordre croissant\n1: Tri par ordre decroissant\n");
                scanf("%d",&choix_ordre_tri);

                transferer_tab_struct(tableau,choix_variable,0);
                tri_fusion(tableau,SIZE_INDEX,choix_ordre_tri);

                printf("\nTri effectue avec succes !\n");
                printf("\n--------------------\n");
                for(i=0;i<SIZE_INDEX;i++)
                {
                    printf("%d\n",tableau[i]);
                }
                free(tableau);
                printf("\n");
                break;
            //Quitte le programme
            case 0:
                break;
            //message d'erreur en cas de saisie ne correspondant à aucun des cas
            default:
                printf("\nERREUR\nSaisie incorrecte, veuillez recommencer.\n");
                break;
        }
    }while(choix_action!=0);
    printf("\n\nFermeture du programme.\nAu revoir !\n");
}
