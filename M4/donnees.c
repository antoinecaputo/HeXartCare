#include "donnees.h"


//fonction pour lire le fichier et l'afficher sur la console
void lire_csv(void)
{
    //d�claration du pointeur de fichier
    FILE* pointeur_csv=NULL;
    //ouverture du fichier en lecture seule
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    //d�claration et initialisation de lecture, un char de la taille du nombre de lignes maximum
    char lecture[SIZE_INDEX]=" ";;

    printf("\nLecture du fichier csv en cours...\n\n");

    //on v�rifie que le fichier existe et qu'il est dans le m�me dossier que donnees.c
    if(pointeur_csv==NULL)
    {
        //affichage du message d'erreur
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        //affichage du contenu du fichier jusqu'� en atteindre la fin
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
    //d�claration du pointeur de fichier
    FILE* pointeur_csv=NULL;
    //ouvrerture du fichier
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    if(pointeur_csv==NULL) //v�rifie la pr�sence du fichier
    {
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        //d�claration du compteur de ligne, initialis� � 1
        int lignes=1;
        //d�claration du char ch qui sera notre curseur dans le parcours du fichier caract�re par caract�re
        char ch;

        //parcours du fichier caract�re par caract�re pour compter pr�cis�ment le nombre de sauts de lignes
        while(!feof(pointeur_csv)) //=tant que le curseur ch n'a pas atteint la fin du fichier
        {
            ch=fgetc(pointeur_csv); //parcours le csv caract�re par caract�re
            if(ch=='\n')
            {
                lignes++; //on incr�mente le compteur de lignes � chaque fois que ch trouve un saut de ligne
            }
        }
        printf("\nLe fichier csv comporte %d lignes\n",SIZE_INDEX);
    }
    //fermeture du fichier
    fclose(pointeur_csv);
    free(pointeur_csv);
}

//fonction pour �crire les donn�es du csv dans la structure D
void placer_dans_struct(void)
{
    //d�claration du pointeur de fichier
    FILE* pointeur_csv=NULL;

    //ouverture du fichier csv en lecture seule
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","r");

    int i=0;
    if(pointeur_csv==NULL)
    {
        //affichage d'un message au cas o� le fichier est inexistant
        printf("\nERREUR - Fichier inexistant ou corrompu.\n");
        exit(1);
    }
    else
    {
        printf("\nRecuperation des donnees en cours...\n");

        //d�claration d'un char qui stockera le titre du fichier csv
        char titre[256];

        //d�claration d'un char qui stockera les strings contenus dans le csv avant de les transf�rer � la structure
        char temp[20];

        if(pointeur_csv==NULL)
        {
            //affichage d'un message au cas o� le fichier est inexistant
            printf("\nERREUR - Fichier inexistant ou corrompu.\n");
            exit(1);
        }
        else
        {
            //on lit la premi�re ligne du fichier pour en stocker le contenu dans titre[256]
            fgets(titre,256,pointeur_csv);
            //affichage du titre du csv ainsi r�cup�r�
            printf("\nEn-tete du csv : %s\n",titre);

            //lecture du csv et enregistrement des donn�es dans la structure
            for(i=0;i<SIZE_INDEX-1;i++) //-1 puisque nous avons �vinc� la premi�re ligne
            {
                //on indique que les donn�es sont s�par�es par des points virgules
                fscanf(pointeur_csv,"%[^;];%d;%d\n",temp,&donnees[i].frequence_cardiaque,&donnees[i].temps_ms);
                //transfert de temp � donnees.personne_nb, �tant un string
                strcpy(donnees[i].personne_nb,temp);
            }
        }

        /* testing purposes
        //affichage du contenu de la structure contenant les donn�es du csv
        for(i=0;i<SIZE_INDEX-1;i++)
        {
            printf("\n%s\nFrequence cardiaque : %d\tTemps : %d ms\n",donnees[i].personne_nb,donnees[i].frequence_cardiaque, \
                   donnees[i].temps_ms);
        }
        */
        printf("\nLes donnees du fichier ont ete recuperees avec succes !\n");
    }

    //fermeture du fichier
    fclose(pointeur_csv);
    free(pointeur_csv);
}
