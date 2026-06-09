#ifndef GARAGE_H
#define GARAGE_H

#include "voiture.h"

int ajouterVoiture(voiture *v, voiture *garage[], int *nbvoiture, int *taille);
int initgarage(void);
int affichergarage(voiture *garage[], int *nbvoiture);

#endif
