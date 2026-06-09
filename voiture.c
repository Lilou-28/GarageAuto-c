#include <stdio.h>
#include <stdlib.h>   
#include <string.h>

typedef struct {
    char marque[20];
    char modele[20];
    char immatriculation[10];
    int annee;
    int kilometrage;
    float prix;
}voiture;


int initvoiture(){
    voiture v;
    printf("Entrez la marque de votre voiture:");
    scanf("%19s", &v.marque);
    printf("Entrez le modele de votre voiture:");
    scanf("%19s", &v.modele);
    printf("Entrez l'immatriculation de votre voiture(sous forme AB - 123 - CD):");
    scanf("%2s - %d - %2s", &v.immatriculation);
    printf("Entrez l'annee de votre voiture:");
    scanf("%d", &v.annee);
    printf("Entrez le kilometrage de votre voiture:");
    scanf("%d", &v.kilometrage);
    printf("Entrez le prix de votre voiture:");
    scanf("%d", &v.prix);

    fflush(stdout);

    return 0;
}