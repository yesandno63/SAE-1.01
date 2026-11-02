/* fonction pour charger depuis le fichiers adhérents */
int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActi1[], int tabActi2[],int max);

/* fonction de chargement du fichier actvitées */
int chargementActi(int tabIDActi[],int nbreM[], int nbreS[], float ptsActi[], int max);

/*fonctions d'affichage*/
void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);
void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA);

/* fonction de sauvegarde*/
void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);
void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog);

/*fonction de menu*/

void menuAdherent(int tlogA,int tabID[], int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[], float tabPts[]);
void menuActivite(int tlogActi, int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[]);

/*fonction de manipulation des lites*/
int recherche(int tab[], int val, int tlog, int *trouve);
int supprimerAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int val,int tlog);
void insertMajAd(int tabId[],int tabStatus[],int tabNb_Acti[],int  tabActiM[],int tabActiS[],float tabPts[],int *tlogA, int max, int id, float pts, int status, int nbActi, int actiM, int actiS);
void insertMajActivite(int tabIdActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int *tlogA, int max, int id, int nbreM, int nbreS, float ptsActi);

/*fonction de saisie*/
void saisirAdherent(int *id, int *status, int *nbActi, int *actiM, int *actiS, float *pts);
void saisirActivite(int *id, int *nbreM, int *nbreS, float *ptsActi);

/*fonction de Global*/
void global(void);