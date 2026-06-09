#ifndef VOITURE_H
#define VOITURE_H

typedef struct {
    char marque[20];
    char modele[20];
    char immatriculation[10];
    int annee;
    int kilometrage;
    float prix;
} voiture;

int initvoiture(void);
int affichervoiture(voiture *v);

#endif