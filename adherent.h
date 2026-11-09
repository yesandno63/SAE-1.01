int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int max);
void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);
void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);
int supprimerAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int val,int tlog);
void insertMajAd(int tabId[],int tabStatus[],int tabNb_Acti[],int  tabActiM[],int tabActiS[],float tabPts[],int *tlogA, int max, int id, float pts, int status, int nbActi, int actiM, int actiS);
void saisirAdherent(int *id, int *status, int *nbActi, int *actiM, int *actiS, float *pts);
void changerStatut(int tabID[], int tabStatus[], int tlog, int idAdherent);
void crediterCarte(int tabID[], float tabPts[], int tlogA, int idAdherent, float mnt);
