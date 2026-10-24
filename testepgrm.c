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

int main(void){
    menu();
    return 0;
}