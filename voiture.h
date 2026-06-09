#ifndef VOITURE_H
#define VOITURE_H

typedef struct {
    char lettre1[3];
    int nombre;
    char lettre2[3];
} immatriculation;

typedef struct {
    char marque[20];
    char modele[20];
    immatriculation immatriculation;
    int annee;
    int kilometrage;
    float prix;
} voiture;

int initvoiture(void);
int infosvoiture(voiture *v);

#endif