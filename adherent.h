/**
    \file adherent.h
    \fichier fichier renseignant toute les fonctions qui concernant les adhérents
*/



/**
    \brief fonction concernant le chargement des valeurs présent dans des fichier vers des tableaux
    \param tabID tableau des ID
    \param tabPts tableau des points
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param max taille maximal des tableaux
*/
int chargementAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int max);

/**
    \brief fonction concernant l'affichage des informations des adhérents
    \param tabID tableau des ID
    \param tabPts tableau des points
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param tlog taille logique des tableaux
*/
void affichageAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);

/**
    \brief fonction de sauvegarde des tableaux vers un fichier
    \param tabID tableau des ID
    \param tabPts tableau des points
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param tlog taille logique des tableaux
*/
void saveAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int tlog);

/**
    \brief fonction pour supprimer un adhérent ainsi que ses informations
    \param tabID tableau des ID
    \param tabPts tableau des points
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param tlog taille logique des tableaux
*/
int supprimerAd(int tabID[],float tabPts[],int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[],int val,int tlog);

/**
    \brief fonction d'insertion d'un nouvel adhérent avec ses informations ou de mise à jour des informations d'un adhérent
    \param tabId tableau des ID
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des activitées du soir
    \param tabPts tableau des points
    \param tlogA taille logique des tableaux
    \param max taille maximal des tableaux
    \param id id de l'adhérent
    \param pts point de l'adhérent
    \param status status d'activation de la carte de l'adhérent
    \param nbActi nombre d'activité de l'adhérent
    \param actiM participe à l'activité du matin ou non
    \param actiS participe à l'activité du soir ou non
*/
void insertMajAd(int tabId[],int tabStatus[],int tabNb_Acti[],int  tabActiM[],int tabActiS[],float tabPts[],int *tlogA, int max, int id, float pts, int status, int nbActi, int actiM, int actiS);

/**
    \brief fonction pour saisir les informations d'un nouvel adhérent
    \param id pointeur renvoyant l'id de l'adhérents
    \param status pointeur renvoyant le status de la carte d'adhérent
    \param nbActi nombre d'activité de l'adhérent
    \param actiM participe à l'activité du matin ou non
    \param actiS participe à l'activité du soir ou non
    \param pts nombre de point de l'adhérent
*/
void saisirAdherent(int *id, int *status, int *nbActi, int *actiM, int *actiS, float *pts);

/**
    \brief fonction pour changer le status de la carte d'adhérent
    \param tabID tableau des ID
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tlog taille logique des tableaux
    \param idAdherent id de l'adhérents
*/
void changerStatut(int tabID[], int tabStatus[], int tlog, int idAdherent);

/**
    \brief fonction pour créditer en point la carte d'adhérent
    \param tabID tableau des ID
    \param tabPts tableau des points
    \param tlogA taille logique des tableaux
    \param idAdherent id de l'adhérents
    \param mnt montant de point à ajouter
*/
void crediterCarte(int tabID[], float tabPts[], int tlogA, int idAdherent, float mnt);
