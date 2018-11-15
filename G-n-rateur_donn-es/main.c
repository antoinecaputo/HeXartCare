#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct echantillon_aleatoire
{
    int freq;
    int tps;
}E;

enum taille_frequence
{
    //pour un adulte, au repos
    lowest_pulse=10,
    highest_pulse=70,
    echantillon=300, //nombre de personnes
};

enum temps_int
{
    max_heure=23,
    min_heure=0,

    max_minute=60,
    min_minute=0,

    max_seconde=60,
    min_seconde=0,
};

void convert_to_csv(E*);

int main()
{
    srand(time(NULL)); //initialisation du random

    E e[echantillon]; //création du tableau de structure e de taille echantillon = 150
    int i;

    //remplissage du tableau de structures
    for(i=0;i<echantillon;i++)
    {
        e[i].freq=(rand()% (highest_pulse-lowest_pulse + 1))+lowest_pulse;
        e[i].tps=(rand()% (max_heure - min_heure + 1))+min_heure;
        printf("Personne %d :\n\nFrequence cardiaque : %d\tTemps : %d ms\n\n",i+1,e[i].freq,e[i].tps);
    }

    //appel de la fonction pour convertir en csv
    convert_to_csv(e);

    return 0;
}

void convert_to_csv(E *e)
{
    printf("\nCreation du fichier csv en cours...\n");

    //création du fichier csv
    FILE *pointeur_csv;
    pointeur_csv=fopen("donnees_aleatoires_v7.csv","w");

    //titre du fichier
    fprintf(pointeur_csv,"Personne;Frequence;Temps(ms)");

    //ajout des données de la structure au fichier
    int j;
    for(j=0;j<echantillon;j++)
    {
        //printf("Ajout des elements en cours..."); //test
        fprintf(pointeur_csv,"\nPersonne_%d",j+1);
        fprintf(pointeur_csv,";%d",e[j].freq);
        fprintf(pointeur_csv,";%d",e[j].tps);
    }

    //fermeture du fichier
    fclose(pointeur_csv);

    printf("\nFichier cree avec succes !\n");
}
