
#include <stdio.h>
#include "prototype.h"
int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int max){
    /* fonction pour charger depuis le fichiers adhérents */
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
    return tlog = i;}


int chargementActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int max)
{ 
    /* fonction de chargement du fichier actvitées */
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

void affichageAd(int tabID[],float tabPts[],int tabStatus, int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog){
    int i, id,rep;
    

    printf("afficher 1 adhérent (entrez 1) ou tous les adhérents (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'adhérent : ");
        scanf("%d", &id);
        for (i = 0; i < tlog; i++)
            if (tabID[i] == id)
              printf("identifiant: %d\n points : %.2f\n Status de la carte: %d\n nombre d'activité: %d\n Actviter matin: %d\n Actvité après-midi: %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
            else printf("l'adhérent n'existe pas");
    }         
    if (rep == 2) {
        printf("Identifiant\t Points\t Status\t Nombre d'activité\t Activité matin\t Activité après-midi\n");
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

    printf("afficher 1 activité (entrez 1) ou toutes les actvtées (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'actvité : ");
        scanf("%d", &idA);
        for (i = 0; i < tlogA; i++)
            if (tabIDActi[i] == idA)
              printf("identifiants Activité: %d\n nombre de participant matin : %d\n  nombre de participant soir: %d\n coût %.2f\n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
            else printf("l'activité n'existe pas");
            }         
    if (rep == 2) {
        printf("Identifiant\t Points\t Status\t Nombre d'activité\t Activité matin\t Activité après-midi\n");
        for (i = 0; i < tlogA; i++)
            printf("%d\t %.2f\t %d\t %d\t %d\t %d\n", tabIDActi[i], tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    while(rep != 1 && rep != 2){
        printf("erreur de saisie, vous devez entrez 1 ou 2, veuillez réessayer : ");
        scanf("%d", &rep);
    }
}