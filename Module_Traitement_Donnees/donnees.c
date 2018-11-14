#include "donnees.h"

//fonction pour lire le fichier et compter le nombre de lignes
void nombre_lignes_csv(void)
{
    //ouvrir le fichier
    FILE* pointeur_csv=NULL;

    pointeur_csv=fopen("donnees_aleatoires_v6.csv","r"); //r pour "en lecture"

    if(pointeur_csv==NULL) //vérifie la présence du fichier
    {
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        int lignes=1;
        char ch;
        while(!feof(pointeur_csv)) //feof cherche la fin du fichier
        {
            ch=fgetc(pointeur_csv); //parcours le csv caractère par caractère
            if(ch=='\n')
            {
                lignes++;
            }
        }
        printf("\nLe fichier csv comporte %d lignes\n",lignes);

    }
    fclose(pointeur_csv);
    free(pointeur_csv);
}

//fonction pour écrire les données du csv dans la structure D
void donnees_vers_structures(void)
{
    //ouverture du fichier csv
    printf("\nOuverture du fichier csv...\n");

    FILE* pointeur_csv=NULL;
    int i=0;
    pointeur_csv=fopen("donnees_aleatoires_v6.csv","r");

    if(pointeur_csv==NULL)
    {
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        printf("\nRecuperation des donnees...\n");
        /*
        char *tmp[301];
        char ligne[50];

        for(i=0;i<301;i++)
        {
            tmp[i]=fgets(ligne,50,pointeur_csv);
            printf("%s",tmp[i]);
        }
        */
        i=0;
        char *pointeur;
        do
        {
            printf("\ntest\n");
            printf("\n%d\n",i);
            pointeur = strtok(tmp[i],";");
            donnees[i].personne_nb=strdup(pointeur);
            pointeur=strtok(NULL,";");
            donnees[i].frequence_cardiaque=atoi(pointeur);
            pointeur=strtok(NULL,";");
            donnees[i].heure=atoi(pointeur);
            pointeur=strtok(NULL,";");
            donnees[i].minutes=atoi(pointeur);
            pointeur=strtok(NULL,"\n");
            donnees[i].secondes=atoi(pointeur);
            pointeur=strtok(NULL,";");
            printf("\n%s\nFrequence cardiaque : %d\nHeure %d:%d:%d\n",donnees[i].personne_nb,donnees[i].frequence_cardiaque, \
                   donnees[i].heure,donnees[i].minutes,donnees[i].secondes);
            i++;
            printf("\n%d\n",i);
        }while(i!=301);

        printf("\nLes donnees du fichier ont ete recuperees avec succes !\n");
    }

    printf("\nFermeture du fichier csv\n");
    fclose(pointeur_csv);
    free(pointeur_csv);
}
