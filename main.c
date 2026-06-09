#include <stdio.h>
#include "voiture.h"

static void afficherMenu(void){
    printf("\n===== Menu GarageAuto =====\n");
    printf("1. Creer et afficher une voiture\n");
    printf("2. Quitter\n");
    printf("Choix : ");
}

int main(void){
    int choix = 0;

    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Choix invalide.\n");
            choix = 0;
            continue;
        }

        switch (choix) {
            case 1:
                initvoiture();
                break;
            case 2:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 2);

    return 0;
}
