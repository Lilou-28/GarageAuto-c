#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "voiture.h"

int ajouterVoiture(voiture *v, voiture *garage[], int *nbvoiture, int *taille){

    if (*nbvoiture + 1 > *taille){
        printf("Votre Garage est plein !");
    }else{
        garage[*nbvoiture] = v;
        (*nbvoiture)++;
    }
    

    return *nbvoiture;
}

int initgarage()
{
    int taille = 0;
    int nbVoiture = 0;
    printf("Entrez le nombre de voiture que vous pouvez mettre dans votre garage :");
    scanf("%d", &taille);
    
    voiture *garage = malloc(taille * sizeof(voiture));
    printf("Votre garage peut acceuillir %d voiture !", taille);
    fflush(stdout);
    free(garage);

    return 0;
}

int affichervoiture(voiture *v){
    printf("Marque: %s , Modele : %s, Immatriculation : %s - %d - %s\n",v->marque, v->modele, v->immatriculation.lettre1, v->immatriculation.nombre, v->immatriculation.lettre2);
}

int affichergarage(voiture *garage[], int *nbvoiture){
    for(int i = 0;i < *nbvoiture; i++){
        printf("%d.",i+1);
        affichervoiture(garage[i]);
    }

    return 0;
}