#include <stdio.h>
#include <stdlib.h>
#include "voiture.h"
#include "garage.h"
#include "menu.h"

int main(void){
    int choix = 0;
    int taille = 0;
    int nbvoiture = 0;
    voiture **garage = NULL;

    printf("Combien de voitures max dans le garage ? ");
    if (scanf("%d", &taille) != 1 || taille <= 0) {
        printf("Taille invalide.\n");
        return 1;
    }

    garage = malloc(taille * sizeof(voiture *));
    if (garage == NULL) {
        printf("Erreur allocation garage.\n");
        return 1;
    }

    do {
        affichermenu();
        if (scanf("%d", &choix) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Choix invalide.\n");
            choix = 0;
            continue;
        }

        switch (choix) {
            case 1:
            {
                voiture *v = initvoiture();
                if (v != NULL) {
                    ajouterVoiture(v, garage, &nbvoiture, taille);
                }
                break;
            }
            case 2:
                supprimervoiture(garage,&nbvoiture);
                break;
            case 3:
                affichergarage(garage, &nbvoiture);
                break;
            case 4:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 4);

    for (int i = 0; i < nbvoiture; i++) {
        free(garage[i]);
    }
    free(garage);

    return 0;
}
