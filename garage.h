#ifndef GARAGE_H
#define GARAGE_H

#include "voiture.h"

int ajouterVoiture(voiture *v, voiture *garage[], int *nbvoiture, int taille);
int affichergarage(voiture *garage[], int *nbvoiture);
int supprimervoiture(voiture *garage[], int *nbvoiture);
int sauvegarderGarage(voiture *garage[], int nbvoiture, const char *nomFichier);
int chargerGarage(voiture *garage[], int *nbvoiture, int taille, const char *nomFichier);
#endif
