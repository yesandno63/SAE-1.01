// programme sae 1.01
#include <stdio>
#include "prototype.h"
int chargementAd(int tabID[],float tabPts[],int tabStatus, int tabNb_Acti[], int tabActiM[], int tabActiS[],int max)
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

    retrun tlog = i;

}

int chargementActi(int tabIDActi[],int tabNbM, int tabNbS, float tabPtsActi, int max)
{
    FILE *flot;
    int idActi, nbM,nbS, tlog = 0;
    float ptsA;

    flot = fopen("donnees/dossierActi.txt", "w");
    if (flot == NULL)
        return -1;

    fscanf(flot,"%d%d%d%f",&idActi, &nbM, &nbS, &ptsA);
    while (!feof(flot)){
       if(tlog == max){
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


}

/*void affichageAd(int tabID[],float tabPts[],int tabStatus, int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog)
{
    int i, id, stat, nbA, actiM, actiS;
    float pts;

    printf("afficher 1 adhérent (entrez 1) ")

} */
