
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

void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA){
    int i, idA,rep, marc;

    printf("afficher 1 activite (entrez 1) ou toutes les actvtees (entrez 2) : ");
    scanf("%d", &rep);
    if (rep == 1){
        printf("entrez l'identifiant de l'actvite : ");
        scanf("%d", &idA);
        for (i = 0; i < tlogA; i++)
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
    FILE *flot = fopen("/donnees/dossierActi.txt","a");
    if (flot == NULL) {exit(1);}

    for (int i=0; i < tlog; i++) {
        fprintf(flot,"%d %d %d %f",tabIDActi[i],tabNbM[i], tabNbS[i], tabPtsActi[i]);
    }
    fclose(flot);
}

void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog) {
    FILE *flot = fopen("/donnees/dossierAd.txt","a");
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
        return tlog; // Aucun changement dans le tableau
    }
    if (trouve == 1 && tabPts[pos] != 0) {
        printf("L'adhérent avec l'identifiant %d ne peut pas être supprimé car il a encore des points.\n", val);
        printf("vous aller etre rembourse de 80%% de vos points soit %.2f\n", tabPts[pos]*0.8);
        return tlog; // Aucun changement dans le tableau
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
    return tlog - 1; // Retourne le nouveau nombre d'adhérents
}
int supprimerActi(int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[], int val, int tlogActi) {
    int trouve , i ;
    int pos = recherche(tabIDActi, val, tlogActi, &trouve);

    if (trouve == 0) {
        printf("L'activité avec l'identifiant %d n'existe pas.\n", val);
        return tlogActi; // Aucun changement dans le tableau
    }

    for ( i = pos; i < tlogActi - 1; ++i) {
        tabIDActi[i] = tabIDActi[i + 1];
        tabNbM[i] = tabNbM[i + 1];
        tabNbS[i] = tabNbS[i + 1];
        tabPtsActi[i] = tabPtsActi[i + 1];
    }

    printf("L'activité avec l'identifiant %d a été supprimée.\n", val);
    return tlogActi - 1; // Retourne le nouveau nombre d'activités
}

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

void insertMajActivite(int tabIdActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int *tlogA, int max, int id, int nbreM, int nbreS, float ptsActi) {
    if (*tlogA >= max) {
        printf("Erreur : le tableau est plein.\n");
        return;
    }

    int trouve;
    int pos = recherche(tabIdActi, id, *tlogA, &trouve);

    if (trouve) {
        tabNbM[pos] = nbreM;
        tabNbS[pos] = nbreS;
        tabPtsActi[pos] = ptsActi;
        printf("les données ont été mises à jour");
    }

    for (int i = *tlogA; i > pos; --i) {
        tabIdActi[i] = tabIdActi[i - 1];
        tabNbM[i] = tabNbM[i - 1];
        tabNbS[i] = tabNbS[i - 1];
        tabPtsActi[i] = tabPtsActi[i - 1];
    }

    tabIdActi[pos] = id;
    tabNbM[pos] = nbreM;
    tabNbS[pos] = nbreS;
    tabPtsActi[pos] = ptsActi;
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

int participation(int tabID[], int tabIDActi[], float tabPts[], float tabPtsActi[], int tabStatus[], int tabNb_Acti[],int tabNbS[],int tabNbM[], int tabActiM[], int tabActiS[],int tlogA, int *trouveAd, int *trouveActi, int idAdherent, int idActivite) {
    int choix ;
    
    int posAdherent = recherche(tabID, idAdherent, tlogA, trouveAd);
    if (trouveAd == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", idAdherent);
        return -3; // Adhérent non trouvé
    }

    int posActivite = recherche(tabIDActi, idActivite, tlogA, trouveActi);
    if (trouveActi == 0) {
        printf("L'activité avec l'identifiant %d n'existe pas.\n", idActivite);
        return -3; // Activité non trouvée
    }

    if (tabStatus[posAdherent] == 0) {
        printf("L'adhérent avec l'identifiant %d n'a pas de statut valide pour participer à une activité.\n", idAdherent);
        return -2; // Statut non valide ( statu = 0 )
    }

    if ((tabNb_Acti[posAdherent]) >= 2) {
        printf("L'adhérent avec l'identifiant %d a déjà atteint le nombre maximum d'activités.\n", idAdherent);
        return -4; // Nombre maximum d'activités atteint
    }

    if ((tabPts[posAdherent]) < tabPtsActi[posActivite]) {
        printf("L'adhérent avec l'identifiant %d n'a pas assez de points pour participer à l'activité avec l'identifiant %d.\n", idAdherent, idActivite);
        return -1; // Points insuffisants
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

void changerStatut(int tabID[], int tabStatus[], int tlog, int idAdherent) {
    int trouve;
    int pos = recherche(tabID, idAdherent, tlog, &trouve);

    if (trouve == 0) {
        printf("L'adhérent avec l'identifiant %d n'existe pas.\n", idAdherent);
        return; // Aucun changement dans le tableau
    }
    printf("Le statut actuel de l'adhérent avec l'identifiant %d est : %d\n", idAdherent, tabStatus[pos]);

    /*saisie contrôler pour le satut*/
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
        return; // Aucun changement dans le tableau
    }

    if (mnt <= 0) {
        printf("Le montant à créditer doit être positif et supérieur à zéro.\n");
        return; // Aucun changement dans le tableau
    }
    else if (mnt > 250){
        printf("vous obtnez un bonus de 10%% sur le montant \n");
        mnt *= 1.1;
    }
    tabPts[pos] += mnt;
    printf("Le solde de l'adhérent avec l'identifiant %d a été crédité de %.2f. Nouveau solde : %.2f\n", idAdherent, mnt, tabPts[pos]);
}

void menuAdherent(int tlogA,int tabID[], int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[], float tabPts[], float tabPtsActi[], int tabIDActi[],int tabNbS[],int tabNbM[]) {
    int choix, pos, res;
    int id, status, nbActi, actiM, actiS, val, val2;
    float pts;
    int max=200;
    int trouveAd, trouveActi;

    

    while (1) {
        printf("1. Afficher adherent\n");
        printf("2. Ajouter adherent\n");
        printf("3. Supprimer adherent\n");
        printf("4. Participer à une activité\n");
        printf("5. Changer le statut d'un adherent\n");
        printf("6. Retour au menu principal\n");
        printf("   Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {
            affichageAd(tabID,tabPts,tabStatus,tabNb_Acti,tabActiM,tabActiS,tlogA);
        }
        else if (choix == 2) {
            saisirAdherent(&id, &status, &nbActi, &actiM, &actiS, &pts);
            insertMajAd(tabID,tabStatus,tabNb_Acti,tabActiM,tabActiS,tabPts,&tlogA,max,id,pts,status,nbActi,actiM,actiS);
        }
        else if (choix == 3) {
            printf("entrez l'identifiant de l'adhérent à supprimer : ");
            scanf("%d", &val);
            tlogA = supprimerAd(tabID, tabPts, tabStatus, tabNb_Acti, tabActiM, tabActiS, val, tlogA);
        }
        else if(choix == 4){
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
            printf("Entrez l'identifiant de l'adhérent : ");
            scanf("%d", &val2);
            changerStatut(tabID, tabStatus, tlogA, val2);
        }
        else if (choix == 6) {
            break; // Retour au menu principal
        }
    }
}



void menuActivite(int tlogActi, int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[]) {
    int choix, pos;
    int max=200;
    
    int id, nbreM, nbreS, val;
    float ptsActi;

    while (1) {
        printf("1. Afficher activite\n");
        printf("2. Ajouter activite\n");
        printf("3. Supprimer activite\n");
        printf("4. Retour au menu principal\n");
        printf("   Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {
            affichageActi(tabIDActi,tabNbM,tabNbS,tabPtsActi,tlogActi);
        }
        else if (choix == 2) {
            saisirActivite(&id, &nbreM, &nbreS, &ptsActi);
            insertMajActivite(tabIDActi,tabNbM,tabNbS,tabPtsActi,&tlogActi,max,id,nbreM,nbreS,ptsActi);
        }
        else if (choix == 3) {
            printf("entrez l'identifiant de l'activite à supprimer : ");
            scanf("%d", &val);
            tlogActi = supprimerActi(tabIDActi, tabNbM, tabNbS, tabPtsActi, val, tlogActi);
        }
        else if (choix == 4) {
            break; // Retour au menu principal
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
            saveActi(tabActiM,tabNbM,tabNbS,tabPtsActi,tlogActi);
            printf("Sauvegarde effectue");
            exit(1);
        }
    }

}


