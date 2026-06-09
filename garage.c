#include <stdio.h>
#include <stdlib.h>
#include "voiture.h"

int ajouterVoiture(voiture *v, voiture *garage[], int *nbvoiture, int taille){

    if (*nbvoiture + 1 > taille){
        printf("Votre Garage est plein !\n");
        free(v);
        return -1;
    }else{
        garage[*nbvoiture] = v;
        (*nbvoiture)++;
    }
    
    return *nbvoiture;
}

int affichergarage(voiture *garage[], int *nbvoiture){
    if (*nbvoiture == 0){
        printf("Vous n'avez aucune voiture.\n");
        return 0;
    }
    for(int i = 0;i < *nbvoiture; i++){
        printf("%d.",i+1);
        infosvoiture(garage[i]);
    }
    return 0;
}

int supprimervoiture(voiture *garage[], int *nbvoiture)
{
    if (*nbvoiture == 0)
    {
        printf("Aucune voiture a supprimer.\n");
        return -1;
    }
    for (int i = 0; i < *nbvoiture; i++)
    {
        printf("%d. Marque : %s, Modele : %s, Immatriculation : %s - %d - %s\n", i + 1, garage[i]->marque, garage[i]->modele, garage[i]->immatriculation.lettre1 ,garage[i]->immatriculation.nombre, garage[i]->immatriculation.lettre2);
    }

    int choix;
    printf("Choisissez la voiture a supprimer : ");
    if (scanf("%d", &choix) != 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Choix invalide.\n");
        return -1;
    }

    int index = choix - 1;

    if (index < 0 || index >= *nbvoiture)
    {
        printf("Choix invalide.\n");
        return -1;
    }
    free(garage[index]);

    for (int i = index; i < *nbvoiture - 1; i++)
    {
        garage[i] = garage[i + 1];
    }

    (*nbvoiture)--;
    garage[*nbvoiture] = NULL;

    printf("Voiture supprimee.\n");

    return 0;
}
