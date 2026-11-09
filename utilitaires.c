#include <stdio.h>
#include "utilitaires.h"

int recherche(int tab[], int val, int tlog, int *trouve) {
    int i;
    for (i=0; i<tlog; ++i) {
        if (tab[i] == val) {
            *trouve=1;
            return i;
        }
        if (tab[i] > val) {
            *trouve=0;
            return i;
        }
    }
    *trouve=0;
    return i;
}

int participation(int tabID[], int tabIDActi[], float tabPts[], float tabPtsActi[], int tabStatus[], int tabNb_Acti[],int tabNbS[],int tabNbM[], int tabActiM[], int tabActiS[],int tlogA, int *trouveAd, int *trouveActi, int idAdherent, int idActivite) {
    int choix ;
    
    int posAdherent = recherche(tabID, idAdherent, tlogA, trouveAd);
    if (*trouveAd == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", idAdherent);
        return -3; 
    }

    int posActivite = recherche(tabIDActi, idActivite, tlogA, trouveActi);
    if (*trouveActi == 0) {
        printf("L'activité avec l'identifiant %d n'existe pas.\n", idActivite);
        return -3; 
    }

    if (tabStatus[posAdherent] == 0) {
        printf("L'adhérent avec l'identifiant %d n'a pas de statut valide pour participer à une activité.\n", idAdherent);
        return -2; 
    }

    if ((tabNb_Acti[posAdherent]) >= 2) {
        printf("L'adhérent avec l'identifiant %d a déjà atteint le nombre maximum d'activités.\n", idAdherent);
        return -4; 
    }

    if ((tabPts[posAdherent]) < tabPtsActi[posActivite]) {
        printf("L'adhérent avec l'identifiant %d n'a pas assez de points pour participer à l'activité avec l'identifiant %d.\n", idAdherent, idActivite);
        return -1; 
    }

    printf("ajout l'activité le matin ou l'après-midi ? (1 pour matin, 2 pour après-midi) : \n");
    scanf("%d", &choix);
    while (choix != 1 && choix != 2) {
        printf("Erreur : vous devez entrer 1 pour le matin ou 2 pour l'après-midi. Veuillez réessayer : \n");
        scanf("%d", &choix);
    }

    if (choix == 1) {
        tabActiM[posAdherent]++;
        tabNbM[posActivite]++;
        tabNb_Acti[posAdherent]++;
        tabPts[posAdherent] -= tabPtsActi[posActivite];
        printf("il vous reste %.2f points\n", tabPts[posAdherent]);
        return 1;
    } else {
        tabActiS[posAdherent]++;
        tabNbS[posActivite]++;
        tabNb_Acti[posAdherent]++;
        tabPts[posAdherent] -= tabPtsActi[posActivite];
        printf("il vous reste %.2f points\n", tabPts[posAdherent]);
        return 1;
    }
}