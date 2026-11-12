/**
    \file utilitaires.h
    \fichier fichier renseignant des fonctions pour recherche des élément et vérifier la participation
*/


/**
    \brief fonction concernant la recherche dans des tableaux
    \param tab tableau dans lequel chercher
    \param val valeur à chercher
    \param tlog taille logique des tableaux
    \param trouve renvois de valeur par pointeur en fonction de si la valeur est trouvé ou non
*/
int recherche(int tab[], int val, int tlog, int *trouve);

/**
    \brief fonction concernant la recherche de la participation ou non des adhérents
    \param tabID tableau des ID
    \param tabIDActi tableau des ID des activitées
    \param tabPts tableau des points
    \param tabPtsActi tableau des point par activitées
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabNbS tableau du nombre de participant le soir
    \param tabNbM tableau du nombre de participant le matin
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param tlogA taille logique des tableaux
    \param trouveAd pointeur renseignant si l'adhérent à était trouvé
    \param trouveActi pointeur renseignant si l'acitvitées à était trouvé
    \param idAdherent ID de l'adhérent
    \param idActivite ID de l'acitivté
*/
int participation(int tabID[], int tabIDActi[], float tabPts[], float tabPtsActi[], int tabStatus[], int tabNb_Acti[],
    int tabNbS[],int tabNbM[], int tabActiM[], int tabActiS[],int tlogA, int *trouveAd, int *trouveActi, int idAdherent,
    int idActivite);