#include <stdio.h>
#include <stdlib.h>
#include "adherent.h"
#include "utilitaires.h"

int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int max) {
    FILE *flot;
    int tlog, id,nbActi,status, i=0;
    int actiM,actiS;
    float pts;
    
    flot = fopen("donnees/dossierAd.txt", "r");
    if (flot == NULL) return -1;
    
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

void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog){
    int i, id,rep,marc;
    printf("afficher 1 adherent (entrez 1) ou tous les adherents (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'adherent : ");
        scanf("%d", &id);
        for (i = 0; i < tlog; i++)
            if (tabID[i] == id){
                marc = 1;
                printf("identifiant: %d\n points : %.2f\n Status de la carte: %d\n nombre d'activite: %d\n Actviter matin: %d\n Actvite après-midi: %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
            }
        if(marc!=1) printf("l'adherent n'existe pas\n");
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

void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog) {
    FILE *flot = fopen("donnees/dossierAd.txt","w");
    if (flot == NULL) {exit(1);}

    for (int i=0; i < tlog; i++) {
        fprintf(flot,"%d %f %d %d %d %d\n", tabID[i], tabPts[i], tabStatus[i], tabNb_Acti[i], tabActiM[i], tabActiS[i]);
    }
    fclose(flot);
}

int supprimerAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int val,int tlog){
    int trouve ,i;
    int pos = recherche(tabID, val, tlog, &trouve);

    if (trouve == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", val);
        return tlog;
    }
    if (trouve == 1 && tabPts[pos] != 0) {
        printf("L'adhérent avec l'identifiant %d ne peut pas être supprimé car il a encore des points.\n", val);
        printf("vous aller etre rembourse de 80%% de vos points soit %.2f\n", tabPts[pos]*0.8);
        return tlog; 
    }

    for ( i = pos; i < tlog - 1; ++i) {
        tabID[i] = tabID[i + 1];
        tabPts[i] = tabPts[i + 1];
        tabStatus[i] = tabStatus[i + 1];
        tabNb_Acti[i] = tabNb_Acti[i + 1];
        tabActiM[i] = tabActiM[i + 1];
        tabActiS[i] = tabActiS[i + 1];
    }
    printf("L'adhérent avec l'identifiant %d a été supprimé.\n", val);
    return tlog - 1; 
}

void insertMajAd(int tabId[],int tabStatus[],int tabNb_Acti[],int  tabActiM[],int tabActiS[],float tabPts[],int *tlogA, int max, int id, float pts, int status, int nbActi, int actiM, int actiS) {
    if (*tlogA >= max) {
        printf("Erreur : le tableau est plein.\n");
        return;
    }
    int trouve;
    int pos = recherche(tabId, id, *tlogA, &trouve);

    if (trouve == 1) {
        tabPts[pos] = pts;
        tabStatus[pos] = status;
        tabNb_Acti[pos] = nbActi;
        tabActiM[pos] = actiM;
        tabActiS[pos] = actiS;
        printf("les données ont été mises à jour");
    }
    
    for (int i = *tlogA; i > pos; --i) {
        tabId[i] = tabId[i - 1];
        tabPts[i] = tabPts[i - 1];
        tabStatus[i] = tabStatus[i - 1];
        tabNb_Acti[i] = tabNb_Acti[i - 1];
        tabActiM[i] = tabActiM[i - 1];
        tabActiS[i] = tabActiS[i - 1];
    }
    if (trouve == 0) 
        printf("il vous est offère 30 pts lors de l'inscription\n");

    tabId[pos] = id;
    tabPts[pos] = pts + 30;
    tabStatus[pos] = status;
    tabNb_Acti[pos] = nbActi;
    tabActiM[pos] = actiM;
    tabActiS[pos] = actiS;
}

void saisirAdherent(int *id, int *status, int *nbActi, int *actiM, int *actiS, float *pts) {
    printf("Entrez l'identifiant de l'adhérent : ");
    scanf("%d", id);
    printf("Entrez les points de l'adhérent : ");
    scanf("%f", pts);
    printf("Entrez le statut de la carte (0 ou 1) : ");
    scanf("%d", status);
    while(*status != 0 && *status !=1){
        printf("Erreur: le status doit valoir soit 0 ou 1. Veuillez réessayer : ");
        scanf("%d", status);
    }
    printf("Entrez le nombre d'activités : ");
    scanf("%d", nbActi);
    while (*nbActi < 0 || *nbActi > 2) {
        printf("Erreur : le nombre d'activités doit être compris entre 0 et 2. Veuillez réessayer : ");
        scanf("%d", nbActi);
    }
    printf("Entrez le nombre d'activités du matin : ");
    scanf("%d", actiM);
    printf("Entrez le nombre d'activités de l'après-midi : ");
    scanf("%d", actiS);

    while(*actiM + *actiS != *nbActi) {
        printf("Erreur : le nombre total d'activités ne correspond pas au nombre d'activités du matin et de l'après-midi. Veuillez réessayer : ");
        printf("Entrez le nombre d'activités du matin : ");
        scanf("%d", actiM);
        printf("Entrez le nombre d'activités de l'après-midi : ");
        scanf("%d", actiS);
    }
}

void changerStatut(int tabID[], int tabStatus[], int tlog, int idAdherent) {
    int trouve;
    int pos = recherche(tabID, idAdherent, tlog, &trouve);

    if (trouve == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", idAdherent);
        return; 
    }
    printf("Le statut actuel de l'adhérent avec l'identifiant %d est : %d\n", idAdherent, tabStatus[pos]);
    printf ("entrez le nouveau satut de l'adhérents (0 desactivé ou 1 activé) : ");
    scanf("%d", &tabStatus[pos]);
    while(tabStatus[pos] != 0 && tabStatus[pos] != 1){
        printf("Erreur: le status doit valoir soit 0 ou 1. Veuillez réessayer : ");
        scanf("%d", &tabStatus[pos]);
    }
    printf("Le statut de l'adhérent avec l'identifiant %d a été changé à %d.\n", idAdherent, tabStatus[pos]);
}

void crediterCarte(int tabID[], float tabPts[], int tlogA, int idAdherent, float mnt){
    int trouve;
    int pos = recherche(tabID, idAdherent, tlogA, &trouve);

    if (trouve == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", idAdherent);
        return; 
    }
    if (mnt <= 0) {
        printf("Le montant à créditer doit être positif et supérieur à zéro.\n");
        return; 
    }
    else if (mnt > 250){
        printf("vous obtnez un bonus de 10%% sur le montant \n");
        mnt *= 1.1;
    }
    tabPts[pos] += mnt;
    printf("Le solde de l'adhérent avec l'identifiant %d a été crédité de %.2f. Nouveau solde : %.2f\n", idAdherent, mnt, tabPts[pos]);
}