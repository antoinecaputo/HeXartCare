#include "actions.h"

//fonction qui va inverser le contenu du tableau tableau avec le contenu du paramètre de struct et inversement
void transferer_tab_struct(int* tableau,int choix,int ordre)
{
    //int choix 0: donnees.frequence_cardiaque | 1: donnees.temps_ms
    //int ordre 0: paramètre struct -> tableau | 1: tableau -> paramètre struct
    int i;
    switch(choix)
    {
        case 0:
            if(ordre==0)
            {
                for(i=0;i<SIZE_INDEX;i++)
                {
                    tableau[i]=donnees[i].frequence_cardiaque;
                }
            }
            else
            {
                for(i=0;i<SIZE_INDEX;i++)
                {
                    donnees[i].frequence_cardiaque=tableau[i];
                }
            }
            break;
        case 1:
            if(ordre==0)
            {
                for(i=0;i<SIZE_INDEX;i++)
                {
                    tableau[i]=donnees[i].temps_ms;
                }
            }
            else
            {
                for(i=0;i<SIZE_INDEX;i++)
                {
                    donnees[i].temps_ms=tableau[i];
                }
            }
            break;
    }
}

//TRI FUSION
void tri_fusion(int* a,int taille,int ordre_tri)
{
    //int tri_ordre 0: croissant | 1: décroissant

    int m=0;
    m=(taille/2); //initialisation du milieu
    int *L,*R; //déclaration des moitiés de tableau de t/a
    int i;

    if(taille<2)
    {
        return;
    }
    else
    {
        L=malloc(sizeof(int)*m);
        R=malloc(sizeof(int)*(taille-m));

        for(i=0;i<m;i++)
        {
            L[i]=a[i];
        }
        for(i=m;i<taille;i++)
        {
            R[i-m]=a[i];
        }

        if(ordre_tri==0)
        {
            tri_fusion(L,m,ordre_tri);
            tri_fusion(R,taille-m,ordre_tri);
            fusionner_croissant(a,L,R,taille);
        }
        else
        {
            tri_fusion(L,m,ordre_tri);
            tri_fusion(R,taille-m,ordre_tri);
            fusionner_decroissant(a,L,R,taille);
        }

    }

}

//ORDRE CROISSANT
void fusionner_croissant(int *a,int *L,int *R, int taille)
{
    int i=0,j=0,k=0; //index des tableaux t/a, L et R
    int mL,mR;
    mL=taille/2;
    mR=taille-mL;

    while(i<mL && j<mR)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    for(;i<mL;i++)
    {
        a[k]=L[i];
        k++;
    }
    for(;j<mR;j++)
    {
        a[k]=R[j];
        k++;
    }
}

//ORDRE DECROISSANT
void fusionner_decroissant(int *a,int *L,int *R, int taille)
{
    int i=0,j=0,k=0; //index des tableaux t/a, L et R
    int mL,mR;
    mL=taille/2;
    mR=taille-mL;

    while(i<mL && j<mR)
    {
        if(L[i]<R[j])
        {
            a[k]=R[j];
            j++;
        }
        else
        {
            a[k]=L[i];
            i++;
        }
        k++;
    }
    for(;j<mR;j++)
    {
        a[k]=R[j];
        k++;
    }
    for(;i<mL;i++)
    {
        a[k]=L[i];
        k++;
    }
}
//FIN TRI FUSION


/*
void recherche(D)
{
    //insérer code...
}
*/
