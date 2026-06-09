#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "garage.h"

void affichermenu(void);

void affichermenu(void) {
    printf("\n===== Menu GarageAuto =====\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Retirer une voiture\n");
    printf("3. Afficher le garage\n");
    printf("4. Quitter\n");
    printf("Choix : ");
}