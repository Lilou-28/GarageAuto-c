#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>   
#include <string.h>


int infosvoiture(voiture *v){
    printf("\n======= Infos de la voiture =======\n");
    printf("Marque : %s\n", v->marque);
    printf("Modele : %s\n", v->modele);
    printf("Immatriculation : %s - %d - %s\n", v->immatriculation.lettre1, v->immatriculation.nombre, v->immatriculation.lettre2);
    printf("Annee : %d\n", v->annee);
    printf("Kilometrage : %d\n", v->kilometrage);
    printf("Prix : %.2f\n", v->prix);
    return 0;
}

int initvoiture(void){
    voiture v;
    printf("Entrez la marque de votre voiture : ");
    scanf("%19s", v.marque);
    printf("Entrez le modele de votre voiture : ");
    scanf("%19s", v.modele);
    printf("Entrez l'immatriculation de votre voiture (AB - 123 - CD) : ");
    scanf("%2s - %d - %2s", v.immatriculation.lettre1, &v.immatriculation.nombre, v.immatriculation.lettre2);
    printf("Entrez l'annee de votre voiture : ");
    scanf("%d", &v.annee);
    printf("Entrez le kilometrage de votre voiture : ");
    scanf("%d", &v.kilometrage);
    printf("Entrez le prix de votre voiture : ");
    scanf("%f", &v.prix);

    fflush(stdout);

    affichervoiture(&v);
    
    return 0;
}