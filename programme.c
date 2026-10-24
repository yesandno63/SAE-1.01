
#include <stdio.h>
#include <stdlib.h>

#include "prototype.h"

int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int max)
{
    FILE *flot;
    
    int tlog, id,nbActi,status, i=0;
    int actiM,actiS;
    float pts;
    
    flot = fopen("donnees/dossierAd.txt", "r");

    if (flot == NULL)
        return -1;
    fscanf(flot,"%d%f%d%d%d%d", &id,&pts,&status,&nbActi,&actiM,&actiS);
    while (!feof(flot)){
        if(i == max){
            fclose(flot);
            return -2;
        }
        tabID[i] = id;
        tabPts[i] = pts;
        tabStatus[i] = status;
        tabNb_Acti[i] = nbActi;
        tabActiM[i] = actiM;
        tabActiS[i] = actiS;

        i++;
        fscanf(flot,"%d%f%d%d%d%d", &id, &pts, &status, &nbActi, &actiM, &actiS);
    }
    return tlog = i;
}


int chargementActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int max)
{ 
    FILE *flot;
    int idActi, nbM,nbS, tlog = 0;
    float ptsA;

    flot = fopen("donnees/dossierActi.txt", "r");
    if (flot == NULL)
        return -1;
        
    fscanf(flot,"%d%d%d%f",&idActi, &nbM, &nbS, &ptsA);
    while (!feof(flot))
    {
       if(tlog == max)
       {
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
    return tlog;
}

void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog){
    int i, id,rep;
    

    printf("afficher 1 adherent (entrez 1) ou tous les adherents (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'adherent : ");
        scanf("%d", &id);
        for (i = 0; i < tlog; i++)
            if (tabID[i] == id)
              printf("identifiant: %d\n points : %.2f\n Status de la carte: %d\n nombre d'activite: %d\n Actviter matin: %d\n Actvite après-midi: %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
            else printf("l'adherent n'existe pas");
    }         
    if (rep == 2) {
        printf("Identifiant\t Points\t Status\t Nombre d'activite\t Activite matin\t Activite après-midi\n");
        for (i = 0; i < tlog; i++)
            printf("%d\t %.2f\t %d\t %d\t %d\t %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
    }
    while(rep != 1 && rep != 2){
        printf("erreur de saisie, vous devez entrer 1 ou 2, veuillez réessayer : ");
        scanf("%d", &rep);
    }
} 

void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA){
    int i, idA,rep;

    printf("afficher 1 activite (entrez 1) ou toutes les actvtees (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'actvite : ");
        scanf("%d", &idA);
        for (i = 0; i < tlogA; i++)
            if (tabIDActi[i] == idA)
              printf("identifiants Activite: %d\n nombre de participant matin : %d\n  nombre de participant soir: %d\n coût %.2f\n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
            else printf("l'activite n'existe pas\n");
            }         
    if (rep == 2) {
        printf("Identifiant \t  nombre activite matin \t nombre activite après-midi\t Points\n");
        for (i = 0; i < tlogA; i++)
            printf("%d \t %d \t %d \t %.2f \n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    while(rep != 1 && rep != 2){
        printf("erreur de saisie, vous devez entrez 1 ou 2, veuillez réessayer : ");
        scanf("%d", &rep);
    }
}

void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog) {
    FILE *flot = fopen("/donnees/dossierActi.txt","r");
    if (flot == NULL) {exit(1);}

    for (int i=0; i < tlog; i++) {
        fprintf(flot,"%d %d %d %f",tabIDActi[i],tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    fclose(flot);
}

void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog) {
    FILE *flot = fopen("/donnees/dossierAd.txt","r");
    if (flot == NULL) {exit(1);}

    for (int i=0; i < tlog; i++) {
        fprintf(flot,"%d %f %d %d %d %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
    }
    fclose(flot);
}


void menu(void) {
    int choix,tlogA,tlogActi, pos;
    int max=15;
    /*Partie Adherent*/
    int tabID[max], tabStatus[max], tabNb_Acti[max], tabActiM[max], tabActiS[max];
    float tabPts[max];

    /*Partie Activitee*/
    int tabIDActi[max], tabNbM[max], tabNbS[max];
    float tabPtsActi[max];

    tlogA=chargementAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,max);
    tlogActi=chargementActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,max);

    while (1) {
        printf("1. Menu Adherent\n");
        printf("2. Menu Activite\n");
        printf("3. Exit\n");
        printf("   Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {

        }
        else if (choix == 2) {

        }
        else if (choix == 3) {
            saveAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,tlogA);
            saveActi(tabActiM,tabNbM,tabNbS,tabPtsActi,tlogA);
            printf("Sauvegarde effectue");
            exit(1);
        }
    }

}
