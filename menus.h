/**
    \file menus.h
    \fichier fonction renseignant les fonctions référent au diférent menu utilisé et utilisable
*/

/**
    \brief fonction concernant le menu de la partie adhérent
    \param tlogA taille logique des tableaux
    \param tabID tableau des ID
    \param tabStatus tableau renseignant le status d'activation de la carte d'adhérent
    \param tabNb_Acti tableau du nombre d'acitivtées faites par personne
    \param tabActiM tableau des acitvitées du matin
    \param tabActiS tableau des acitvitées du soir
    \param tabPts tableau des points
    \param tabPtsActi tableau des point par activitées
    \param tabIDActi tableau des ID des activitées
    \param tabNbS tableau du nombre de participant le soir
    \param tabNbM tableau du nombre de participant le matin
*/
void menuAdherent(int tlogA,int tabID[], int tabStatus[], int tabNb_Acti[], int tabActiM[], int tabActiS[], float tabPts[], float tabPtsActi[], int tabIDActi[],int tabNbS[],int tabNbM[]);
/**
    \brief fonction concernant le menu de la partie activité
    \param tlogActi taille logique du tableau acitivtées
    \param tabIDActi tableau des ID des activitées
    \param tabNbS tableau du nombre de participant le soir
    \param tabNbM tableau du nombre de participant le matin
    \param tabPtsActi tableau des point par activitées
*/
void menuActivite(int tlogActi, int tabIDActi[], int tabNbM[], int tabNbS[], float tabPtsActi[]);

/**
    \brief fonction global
*/
void global(void);