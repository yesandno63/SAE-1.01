int chargementActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int max);
void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA);
void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog);
int supprimerActi(int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[], int val, int tlogActi);
void insertMajActivite(int tabIdActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int *tlogA, int max, int id, int nbreM, int nbreS, float ptsActi);
void saisirActivite(int *id, int *nbreM, int *nbreS, float *ptsActi);