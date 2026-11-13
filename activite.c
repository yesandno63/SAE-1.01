#include <stdio.h>
#include <stdlib.h>
#include "activite.h"
#include "utilitaires.h"

int chargementActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int max) { 
    FILE *flot;
    int idActi, nbM,nbS, tlog = 0;
    float ptsA;

    flot = fopen("donnees/dossierActi.txt", "r");
    if (flot == NULL) return -1;
        
    fscanf(flot,"%d%d%d%f",&idActi, &nbM, &nbS, &ptsA);
    while (!feof(flot)) {
       if(tlog == max) {
            fclose(flot);
            return -2;
       } 
        tabIDActi[tlog] = idActi;
        tabNbM[tlog] = nbM;
        tabNbS[tlog] = nbS;
        tabPtsActi[tlog] = ptsA;
        tlog ++;
        fscanf(flot,"%d%d%d%f",&idActi, &nbM, &nbS, &ptsA);
    }
    fclose(flot);
    return tlog;
}

void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA){
    int i, idA,rep, marc;
    printf("afficher 1 activite (entrez 1) ou toutes les actvtees (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'actvite : ");
        scanf("%d", &idA);
        for (i = 0; i <= tlogA; i++)
            if (tabIDActi[i] == idA){
            marc = 1;
              printf("identifiants Activite: %d\nnombre de participant matin : %d\nnombre de participant soir: %d\ncoût %.2f\n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
            }
        if(marc!=1)
            printf("l'activite n'existe pas\n");
        }                 
    if (rep == 2) {
        printf("Id \t matin \t soir \t Points\n");
        for (i = 0; i < tlogA; i++)
            printf("%d \t %d \t %d \t %.2f \n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    while(rep != 1 && rep != 2){
        printf("erreur de saisie, vous devez entrez 1 ou 2, veuillez réessayer : ");
        scanf("%d", &rep);
    }
}

void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog) {
    int i;
    FILE *flot = fopen("donnees/dossierActi.txt","w");
    if (flot == NULL) {exit(1);}

    for (i=0; i < tlog; i++) {
        fprintf(flot,"%d %d %d %.2f\n",tabIDActi[i],tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    fclose(flot);
}

int supprimerActi(int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[], int val, int tlogActi) {
    int trouve , i ;
    int pos = recherche(tabIDActi, val, tlogActi, &trouve);

    if (trouve == 0) {
        printf("L'activité avec l'identifiant %d n'existe pas.\n", val);
        return tlogActi;
    }
    for ( i = pos; i < tlogActi - 1; ++i) {
        tabIDActi[i] = tabIDActi[i + 1];
        tabNbM[i] = tabNbM[i + 1];
        tabNbS[i] = tabNbS[i + 1];
        tabPtsActi[i] = tabPtsActi[i + 1];
    }
    printf("L'activité avec l'identifiant %d a été supprimée.\n", val);
    return tlogActi - 1; 
}

void insertMajActivite(int tabIdActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int *tlogA, int max, int id, int nbreM, int nbreS, float ptsActi) {
    
    int trouve;
    int pos = recherche(tabIdActi, id, *tlogA, &trouve);

    if (trouve == 1) {
        tabNbM[pos] = nbreM;
        tabNbS[pos] = nbreS;
        tabPtsActi[pos] = ptsActi;
        printf("les données ont été mises à jour\n");
    }
    if(trouve == 0){
        if (*tlogA >= max) {
            printf("Erreur : le tableau est plein.\n");
            return;
        }
        for (int i = *tlogA ; i > pos ; i--) {
            tabIdActi[i] = tabIdActi[i - 1];
            tabNbM[i] = tabNbM[i - 1];
            tabNbS[i] = tabNbS[i - 1];
            tabPtsActi[i] = tabPtsActi[i - 1];
        }
        tabIdActi[pos] = id;
        tabNbM[pos] = nbreM;
        tabNbS[pos] = nbreS;
        tabPtsActi[pos] = ptsActi;
        *tlogA ++;
    }
}

void saisirActivite(int *id, int *nbreM, int *nbreS, float *ptsActi) {
    printf("Entrez l'identifiant de l'activité : ");
    scanf("%d", id);
    while (*id <= 0) {
        printf("Erreur : l'identifiant de l'activité doit être un entier positif. Veuillez réessayer : ");
        scanf("%d", id);
    }
    printf("Entrez le nombre de participants du matin : ");
    scanf("%d", nbreM);
    while (*nbreM < 0) {
        printf("Erreur : le nombre de participants du matin doit être un entier positif. Veuillez réessayer : ");
        scanf("%d", nbreM);
    }
    printf("Entrez le nombre de participants de l'après-midi : ");
    scanf("%d", nbreS);
    while (*nbreS < 0) {
        printf("Erreur : le nombre de participants de l'après-midi doit être un entier positif. Veuillez réessayer : ");
        scanf("%d", nbreS);
    }
    printf("Entrez les points de l'activité : ");
    scanf("%f", ptsActi);
    while (*ptsActi < 0) {
        printf("Erreur : les points de l'activité doivent être un nombre positif. Veuillez réessayer : ");
        scanf("%f", ptsActi);
    }
}