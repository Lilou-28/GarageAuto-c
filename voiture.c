#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>   
#include <string.h>


int affichervoiture(voiture *v){
    printf("\n======= Infos de la voiture =======");
    printf("\nMarque :%19s", v->marque);
    printf("\nModele :%19s", v->modele);
    printf("\nImmatriculation :%2s - %d - %2s", v->immatriculation.lettre1, v->immatriculation.nombre, v->immatriculation.lettre2);
    printf("\nAnnee :%d", v->annee);
    printf("\nKilometrage :%d", v->kilometrage);
    printf("\nPrix :%d", v->prix);
    return 0;
}

int initvoiture(){
    voiture v;
    printf("Entrez la marque de votre voiture:");
    scanf("%19s", &v.marque);
    printf("Entrez le modele de votre voiture:");
    scanf("%19s", &v.modele);
    printf("Entrez l'immatriculation de votre voiture(sous forme AB - 123 - CD):");
    scanf("%2s - %d - %2s", &v.immatriculation.lettre1, &v.immatriculation.nombre, &v.immatriculation.lettre2);
    printf("Entrez l'annee de votre voiture:");
    scanf("%d", &v.annee);
    printf("Entrez le kilometrage de votre voiture:");
    scanf("%d", &v.kilometrage);
    printf("Entrez le prix de votre voiture:");
    scanf("%d", &v.prix);

    fflush(stdout);

    affichervoiture(&v);
    
    return 0;
}