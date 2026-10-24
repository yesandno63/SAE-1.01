/* fonction pour charger depuis le fichiers adhérents */
int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActi1[], int tabActi2[],int max);

/* fonction de chargement du fichier actvitées */
int chargementActi(int tabIDActi[],int nbreM[], int nbreS[], float ptsActi[], int max);

void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);

void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA);

/* fonction de sauvegarde*/
void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);
void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog);

/*fonction de menu*/
void menu(void);