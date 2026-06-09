#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "garage.h"

int creationgarage(){
        printf("====Bienvenu dans GARAGE AUTO====\n");
        printf("Nous allons commencer par créer votre garage..\n");
        initgarage();
}

int menu(){
    int choix;
    printf("===Bienvenu dans votre Garage===\n");
    printf("Que voulez vous faire ?\n");
    printf("1.Ajouter une voiture a votre collection\n");
    printf("2.Supprimer une voiture de votre collection\n");
    printf("3.Afficher votre garage\n");
    printf("4.Modifier votre voiture\n");
    printf("5.Quitter\n");
    scanf("%d", &choix);

    switch(choix){
        case 1:
            initvoiture();
            break;
    }
    return 0;
}

int main(){
    creationgarage();
}