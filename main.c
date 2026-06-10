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
    
    system("cls");
    printf("============= BIENVENUE =============\n");
    printf("Nous allons d'abord creer votre garage..\n");
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

    chargerGarage(garage, &nbvoiture, taille, "garage.txt");

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
                system("cls");
                voiture *v = initvoiture();
                if (v != NULL) {
                    int result = ajouterVoiture(v, garage, &nbvoiture, taille);
                    if (result == -1) {
                        printf("Appuyez sur Entrée pour continuer...");
                        getchar();
                        getchar();
                    }
                }
                break;
            }
            case 2:
                system("cls");
                supprimervoiture(garage,&nbvoiture);
                break;
            case 3:
                affichergarage(garage, &nbvoiture);
                printf("\nAppuyez sur Entrée pour revenir au menu...");
                getchar();
                getchar();
                break;
            case 4:
                system("cls");
                printf("Au revoir.\n");
                break;
            default:
                system("cls");
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 4);

    if (sauvegarderGarage(garage, nbvoiture, "garage.txt") == 0) {
        printf("Garage sauvegarde dans garage.txt.\n");
    }

    for (int i = 0; i < nbvoiture; i++) {
        free(garage[i]);
    }
    free(garage);

    return 0;
}
