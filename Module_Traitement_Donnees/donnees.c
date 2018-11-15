#include "donnees.h"

//fonction pour lire le fichier et l'afficher sur la console
void lire_csv(void)
{
    //déclaration du pointeur de fichier
    FILE* pointeur_csv=NULL;
    //ouverture du fichier en lecture seule
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    //déclaration et initialisation de lecture, un char de la taille du nombre de lignes maximum
    char lecture[SIZE_INDEX]=" ";;

    printf("\nLecture du fichier csv en cours...\n\n");

    //on vérifie que le fichier existe et qu'il est dans le même dossier que donnees.c
    if(pointeur_csv==NULL)
    {
        //affichage du message d'erreur
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        //affichage du contenu du fichier jusqu'à en atteindre la fin
        while(fgets(lecture,SIZE_INDEX,pointeur_csv)!=NULL)
        {
            printf("%s",lecture);
        }
    }

    printf("\n\nFin du fichier csv.\n");

    //fermeture du fichier
    fclose(pointeur_csv);
    free(pointeur_csv);
}

//fonction pour lire le fichier et compter le nombre de lignes
void nombre_lignes_csv(void)
{
    //déclaration du pointeur de fichier
    FILE* pointeur_csv=NULL;
    //ouvrerture du fichier
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    if(pointeur_csv==NULL) //vérifie la présence du fichier
    {
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        //déclaration du compteur de ligne, initialisé à 1
        int lignes=1;
        //déclaration du char ch qui sera notre curseur dans le parcours du fichier caractère par caractère
        char ch;

        //parcours du fichier caractère par caractère pour compter précisément le nombre de sauts de lignes
        while(!feof(pointeur_csv)) //=tant que le curseur ch n'a pas atteint la fin du fichier
        {
            ch=fgetc(pointeur_csv); //parcours le csv caractère par caractère
            if(ch=='\n')
            {
                lignes++; //on incrémente le compteur de lignes à chaque fois que ch trouve un saut de ligne
            }
        }

        //affichage du résultat
        printf("\nLe fichier csv comporte %d lignes\n",lignes);

    }

    //fermeture du fichier
    fclose(pointeur_csv);
    free(pointeur_csv);
}

//fonction pour écrire les données du csv dans la structure D
void placer_dans_struct(void)
{
    //déclaration du pointeur de fichier
    FILE* pointeur_csv=NULL;

    //ouverture du fichier csv en lecture seule
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    int i=0;
    if(pointeur_csv==NULL)
    {
        //affichage d'un message au cas où le fichier est inexistant
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        printf("\nRecuperation des donnees en cours...\n");

        //déclaration d'un char qui stockera le titre du fichier csv
        char titre[256];

        //déclaration d'un char qui stockera les strings contenus dans le csv avant de les transférer à la structure
        char temp[20];

        if(pointeur_csv==NULL)
        {
            //affichage d'un message au cas où le fichier est inexistant
            printf("\nERREUR - Fichier inexistant ou corrompu.\n");
            exit(1);
        }
        else
        {
            //on lit la première ligne du fichier pour en stocker le contenu dans titre[256]
            fgets(titre,256,pointeur_csv);
            //affichage du titre du csv ainsi récupéré
            printf("\n%s\n",titre);

            //lecture du csv et enregistrement des données dans la structure
            for(i=0;i<SIZE_INDEX-1;i++) //-1 puisque nous avons évincé la première ligne
            {
                //on indique que les données sont séparées par des points virgules
                fscanf(pointeur_csv,"%[^;];%d;%d\n",temp,&donnees[i].frequence_cardiaque,&donnees[i].temps_ms);
                //transfert de temp à donnees.personne_nb, étant un string
                strcpy(donnees[i].personne_nb,temp);
            }
        }

        //affichage du contenu de la structure contenant les données du csv
        for(i=0;i<SIZE_INDEX-1;i++)
        {
            printf("\n%s\nFrequence cardiaque : %d\tTemps : %d ms\n",donnees[i].personne_nb,donnees[i].frequence_cardiaque, \
                   donnees[i].temps_ms);
        }

        printf("\nLes donnees du fichier ont ete recuperees avec succes !\n");
    }

    //fermeture du fichier
    fclose(pointeur_csv);
    free(pointeur_csv);
}
