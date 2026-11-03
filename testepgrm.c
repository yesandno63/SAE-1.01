#include <stdio.h>
#include "prototype.h"

void testeCharAd(void){
    int pos, tabID[15], tabStatus[15], tabNb_Acti[15], tabActiM[15], tabActiS[15];
    float tabPts[15]; 

    pos = chargementAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,15);
    affichageAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,pos);

}

void testeCharActi(void){
    int pos, tabIDActi[15], tabNbM[15], tabNbS[15];
    float tabPtsActi[15]; 

    pos = chargementActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,15);
    affichageActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,pos);

}

void testeMenuAd(void){
    int tlogA = 0;
     int pos, tabID[15], tabStatus[15], tabNb_Acti[15], tabActiM[15], tabActiS[15] ;
    float tabPts[15],tabPtsActi[15]; 
    int tabIDActi[15], tabNbM[15], tabNbS[15];
    tlogA = chargementAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,15);
    menuAdherent(tlogA, tabID, tabStatus, tabNb_Acti, tabActiM, tabActiS, tabPts, tabPtsActi, tabIDActi, tabNbS, tabNbM);
}

void testeMenuActi(void){
    int tlogA = 0;
    int pos, tabIDActi[15], tabNbM[15], tabNbS[15];
    float tabPtsActi[15]; 
    tlogA = chargementActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,15);
    menuActivite(tlogA, tabIDActi, tabNbM, tabNbS, tabPtsActi);
}

void testPart(void){
    int tlogA = 0;
    int pos, tabID[15], tabStatus[15], tabNb_Acti[15], tabActiM[15], tabActiS[15];
    float tabPts[15]; 
    tlogA = chargementAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,15);
    int trouveAd, trouveActi, nbSad, nbMad, nbTotAd, nbAS, nbAM;
    float ptsAd;

    int tlogActi = 0;
    int pos2, tabIDActi[15], tabNbM[15], tabNbS[15];
    float tabPtsActi[15]; 
    tlogActi = chargementActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,15);

    int idAdherent = 1; // Remplacez par l'identifiant de l'adhérent que vous voulez tester
    int idActivite = 101; // Remplacez par l'identifiant de l'activité que vous voulez tester

    printf("entrez un identifiant d'adhérent : ");
    scanf("%d", &idAdherent);
    printf("entrez un identifiant d'activité : ");
    scanf("%d", &idActivite);
    

    int result = participation(tabID, tabIDActi, tabPts, tabPtsActi, tabStatus, tabNb_Acti, tabNbS, tabNbM, tabActiM, tabActiS, tlogA, &trouveAd, &trouveActi, idAdherent, idActivite, &nbSad, &nbMad, &ptsAd, &nbTotAd, &nbAS, &nbAM);
    printf("Résultat de la participation : %d\n", result);
}

int main(void){
    //testeCharActi();
    //testeCharAd();
    //testeMenuAd();
    //testeMenuActi();
    testPart();
    //global();
    return 0;
}