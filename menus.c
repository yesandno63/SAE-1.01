#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "adherent.h"
#include "activite.h"
#include "utilitaires.h"

void menuAdherent(int tlogA,int tabID[], int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[], float tabPts[], float tabPtsActi[], int tabIDActi[],int tabNbS[],int tabNbM[]) {
    int choix, pos, res;
    int id, status, nbActi, actiM, actiS, val, val2;
    float pts;
    int max=200;
    int trouveAd, trouveActi;

    while (1) {
        printf("---------------------------------------\n");
        printf("1. Afficher adherent\n");
        printf("2. Ajouter ou Modifier un adherent\n");
        printf("3. Supprimer adherent\n");
        printf("4. Participer à une activité\n");
        printf("5. Changer le statut d'un adherent\n");
        printf("6. Retour au menu principal\n");
        printf("   Choix: ");
        scanf("%d", &choix);
        

        if (choix == 1) {
            printf("---------------------------------------\n");
            affichageAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,tlogA);
        }
        else if (choix == 2) {
            printf("---------------------------------------\n");
            saisirAdherent(&id, &status, &nbActi, &actiM, &actiS, &pts);
            insertMajAd(tabID,tabStatus,tabNb_Acti,tabActiM,tabActiS,tabPts,&tlogA,max,id,pts,status,nbActi,actiM,actiS);
        }
        else if (choix == 3) {
            printf("---------------------------------------\n");
            printf("entrez l'identifiant de l'adhérent à supprimer : ");
            scanf("%d", &val);
            tlogA = supprimerAd(tabID, tabPts, tabStatus, tabNb_Acti, tabActiM, tabActiS, val, tlogA);
        }
        else if(choix == 4){
            printf("---------------------------------------\n");
            printf("Entrez l'identifiant de l'adhérent : ");
            scanf("%d", &val2);
            printf("Entrez l'identifiant de l'activité : ");
            scanf("%d", &val);
            res = participation(tabID,tabIDActi, tabPts, tabPtsActi, tabStatus, tabNb_Acti, tabNbS, tabNbM, tabActiM, tabActiS, tlogA, &trouveAd, &trouveActi, val2, val);
            if (res == 1) {
                printf("Participation réussie.\n");
            }
        }
        else if (choix == 5) {
            printf("---------------------------------------\n");
            printf("Entrez l'identifiant de l'adhérent : ");
            scanf("%d", &val2);
            changerStatut(tabID, tabStatus, tlogA, val2);
        }
        else if (choix == 6) {
            break; 
        }
    }
}

void menuActivite(int tlogActi, int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[]) {
    int choix, pos;
    int max=200;
    int id, nbreM, nbreS, val;
    float ptsActi;

    while (1) {
        printf("---------------------------------------\n");
        printf("1. Afficher activite\n");
        printf("2. Ajouter ou Modifier une activite\n");
        printf("3. Supprimer activite\n");
        printf("4. Retour au menu principal\n");
        printf("   Choix: ");
        scanf("%d", &choix);
        

        if (choix == 1) {
            printf("---------------------------------------\n");
            affichageActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,tlogActi);
        }
        else if (choix == 2) {
            printf("---------------------------------------\n");
            saisirActivite(&id, &nbreM, &nbreS, &ptsActi);
            insertMajActivite(tabIDActi,tabNbM,tabNbS,tabPtsActi,&tlogActi,max,id,nbreM,nbreS,ptsActi);
        }
        else if (choix == 3) {
            printf("---------------------------------------\n");
            printf("entrez l'identifiant de l'activite à supprimer : ");
            scanf("%d", &val);
            tlogActi = supprimerActi(tabIDActi, tabNbM, tabNbS, tabPtsActi, val, tlogActi);
        }
        else if (choix == 4) {
            break; 
        }
    }
}

void global(void) {
    int choix,tlogA,tlogActi, pos;
    int max=200;

    /*Partie Adherent*/
    int tabID[max], tabStatus[max], tabNb_Acti[max], tabActiM[max], tabActiS[max];
    float tabPts[max];

    /*Partie Activitee*/
    int tabIDActi[max], tabNbM[max], tabNbS[max];
    float tabPtsActi[max];

    tlogA=chargementAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,max);
    tlogActi=chargementActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,max);

    while (1) {
        printf("\n=== Bienvenue au Complexe Sportif Xtrem ===\n");
        printf("1. Menu Adherent\n");
        printf("2. Menu Activite\n");
        printf("3. Exit\n");
        printf("   Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {
            menuAdherent(tlogA, tabID, tabStatus, tabNb_Acti, tabActiM, tabActiS, tabPts, tabPtsActi, tabIDActi, tabNbS, tabNbM);
        }
        else if (choix == 2) {
            menuActivite(tlogActi, tabIDActi, tabNbM, tabNbS, tabPtsActi);
        }
        else if (choix == 3) {
            saveAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,tlogA);
            saveActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,tlogActi);
            printf("Sauvegarde effectue\n");
            exit(1);
        }
    }
}