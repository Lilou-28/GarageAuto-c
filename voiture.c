#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static void viderBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int infosvoiture(voiture *v){
    system("cls");
    printf("\n======= Infos de la voiture =======\n");
    printf("Marque : %s\n", v->marque);
    printf("Modele : %s\n", v->modele);
    printf("Immatriculation : %s - %d - %s\n", v->immatriculation.lettre1, v->immatriculation.nombre, v->immatriculation.lettre2);
    printf("Annee : %d\n", v->annee);
    printf("Kilometrage : %d\n", v->kilometrage);
    printf("Prix : %.2f\n", v->prix);
    return 0;
}

voiture *initvoiture(void){
    voiture *v = malloc(sizeof(voiture));

    if (v == NULL) {
        printf("Erreur allocation voiture.\n");
        return NULL;
    }

    printf("Entrez la marque de votre voiture : ");
    if (scanf(" %19[^\n]", v->marque) != 1) {
        printf("Marque invalide.\n");
        free(v);
        return NULL;
    }
    printf("Entrez le modele de votre voiture : ");
    if (scanf(" %19[^\n]", v->modele) != 1) {
        printf("Modele invalide.\n");
        free(v);
        return NULL;
    }
    while (1)
    {
        printf("Entrez l'immatriculation (AB - 123 - CD) : ");

        if (scanf("%2s - %d - %2s",
                v->immatriculation.lettre1,
                &v->immatriculation.nombre,
                v->immatriculation.lettre2) != 3)
        {
            printf("Format invalide.\n");

            viderBuffer();
            continue;
        }

        if (strlen(v->immatriculation.lettre1) != 2 ||
            strlen(v->immatriculation.lettre2) != 2)
        {
            printf("Les groupes de lettres doivent contenir 2 lettres.\n");
            continue;
        }

        if (!isalpha((unsigned char)v->immatriculation.lettre1[0]) ||
            !isalpha((unsigned char)v->immatriculation.lettre1[1]) ||
            !isalpha((unsigned char)v->immatriculation.lettre2[0]) ||
            !isalpha((unsigned char)v->immatriculation.lettre2[1]))
        {
            printf("Les lettres doivent etre alphabetiques.\n");
            continue;
        }

        if (v->immatriculation.nombre < 1 ||
            v->immatriculation.nombre > 999)
        {
            printf("Le nombre doit etre compris entre 1 et 999.\n");
            continue;
        }

        break;
    }
    printf("Entrez l'annee de votre voiture : ");
    if (scanf("%d", &v->annee) != 1) {
        printf("Annee invalide.\n");
        free(v);
        viderBuffer();
        return NULL;
    }
    printf("Entrez le kilometrage de votre voiture : ");
    if (scanf("%d", &v->kilometrage) != 1) {
        printf("Kilometrage invalide.\n");
        free(v);
        viderBuffer();
        return NULL;
    }
    printf("Entrez le prix de votre voiture : ");
    if (scanf("%f", &v->prix) != 1) {
        printf("Prix invalide.\n");
        free(v);
        viderBuffer();
        return NULL;
        system("cls");
    }

    fflush(stdout);
    return v;
}
