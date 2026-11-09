# SAÉ 1.01 - Gestion d'un complexe sportif

Ce projet est une application en C permettant de gérer les adhérents et les activités d'un centre sportif ou de bien-être. Projet réalisé dans le cadre de la SAÉ 1.01 du BUT Informatique.

## Architecture du code

Le code source a été découpé de manière modulaire pour éviter les conflits lors du travail en groupe :

*   **`main.c`** : Point d'entrée du programme. Gère l'exécution principale.
*   **`menus.c` / `.h`** : Interface utilisateur, boucle de menus et navigation.
*   **`adherent.c` / `.h`** : Gestion exclusive des adhérents (création, suppression, affichage, modification de statut, crédit de carte, chargement/sauvegarde).
*   **`activite.c` / `.h`** : Gestion exclusive des activités (création, suppression, affichage, chargement/sauvegarde).
*   **`utilitaires.c` / `.h`** : Fonctions transversales (algorithme de recherche générique) et interactions croisées (participation d'un adhérent à une activité).
*   **`/donnees/`** : Dossier contenant les fichiers de persistance des données (`dossierAd.txt` et `dossierActi.txt`).
  
