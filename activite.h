/**
    \file activite.h
    \fichier fichier renseignant toute les fonctions qui concernant les activités
*/

/**
    \brief fonction concernant le chargement des valeurs présent dans des fichier vers des tableaux
    \param tabIDActi tableau des ID des activités
    \param tabNbM tableau renseignant le nombre de participant à l'activité du matin
    \param tabNbS tableau renseignant le nombre de participant à l'activité du soir
    \param tabPtsActi tableau des points
    \param max taille maximal des tableaux
*/
int chargementActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int max);

/**
    \brief fonction concernant l'affichage des informations des activitées
    \param tabIDActi tableau des ID des activités
    \param tabNbM tableau renseignant le nombre de participant à l'activité du matin
    \param tabNbS tableau renseignant le nombre de participant à l'activité du soir
    \param tabPtsActi tableau des points
    \param tlogA taille logique des tableaux
*/
void affichageActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[], int tlogA);

/**
    \brief fonction de sauvegarde des tableaux vers un fichier
    \param tabIDActi tableau des ID des activités
    \param tabNbM tableau renseignant le nombre de participant à l'activité du matin
    \param tabNbS tableau renseignant le nombre de participant à l'activité du soir
    \param tabPtsActi tableau des points
    \param tlog taille logique des tableaux
*/
void saveActi(int tabIDActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int tlog);

/**
    \brief fonction pour supprimer une acitivité
    \param tabIDActi tableau des ID des activités
    \param tabNbM tableau renseignant le nombre de participant à l'activité du matin
    \param tabNbS tableau renseignant le nombre de participant à l'activité du soir
    \param tabPtsActi tableau des points
    \param val valeur à supprimer
    \param tlogActi taille logique des tableaux
*/
int supprimerActi(int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[], int val, int tlogActi);

/**
    \brief fonction d'insertion d'une nouvelle activité ou de mise à jour d'une
    \param tabIdActi tableau des ID des activités
    \param tabNbM tableau renseignant le nombre de participant à l'activité du matin
    \param tabNbS tableau renseignant le nombre de participant à l'activité du soir
    \param tabPtsActi tableau des points
    \param tlogA taille logique des tableaux
    \param max taille maximale des tableaux
    \param id id de l'acitivté à actualiser
    \param nbreM nombre de participant à l'activité du matin
    \param nbreS nombre de participant à l'activité du soir
    \param ptsActi point de l'acitivté
*/
void insertMajActivite(int tabIdActi[],int tabNbM[], int tabNbS[], float tabPtsActi[],int *tlogA, int max, int id, int nbreM, int nbreS, float ptsActi);

/**
    \brief fonction pour saisir les informations d'une nouvelle activitées
    \param id pointeur vers l'acitivté voulue
    \param nbreM pointeur vers le nombre de participant à l'acitivité du matin
    \param nbreS pointeur vers le nombre de participant à l'acitivité du soir
    \param ptsActi point de l'activité
*/
void saisirActivite(int *id, int *nbreM, int *nbreS, float *ptsActi);