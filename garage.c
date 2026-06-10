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

    system("cls");
    printf("================================ GarageAuto ================================\n");
    printf("%-4s %-19s %-19s %-16s %-6s %-12s %-10s\n",
           "N", "Marque", "Modele", "Immatriculation", "Annee", "Kilometrage", "Prix");
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0;i < *nbvoiture; i++){
        printf("%-4d %-19s %-19s %s-%03d-%s       %-6d %-12d %.2f\n",
               i + 1,
               garage[i]->marque,
               garage[i]->modele,
               garage[i]->immatriculation.lettre1,
               garage[i]->immatriculation.nombre,
               garage[i]->immatriculation.lettre2,
               garage[i]->annee,
               garage[i]->kilometrage,
               garage[i]->prix);
    }

    printf("============================================================================\n");
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

int sauvegarderGarage(voiture *garage[], int nbvoiture, const char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "w");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return -1;
    }

    for (int i = 0; i < nbvoiture; i++)
    {
        fprintf(fichier, "%s|%s|%s|%d|%s|%d|%d|%.2f\n",
                garage[i]->marque,
                garage[i]->modele,
                garage[i]->immatriculation.lettre1,
                garage[i]->immatriculation.nombre,
                garage[i]->immatriculation.lettre2,
                garage[i]->annee,
                garage[i]->kilometrage,
                garage[i]->prix);
    }

    fclose(fichier);
    return 0;
}

int chargerGarage(voiture *garage[], int *nbvoiture, int taille, const char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL)
    {
        return 0;
    }

    while (*nbvoiture < taille)
    {
        voiture *v = malloc(sizeof(voiture));

        if (v == NULL)
        {
            printf("Erreur allocation voiture pendant le chargement.\n");
            fclose(fichier);
            return -1;
        }

        if (fscanf(fichier, " %19[^|]|%19[^|]|%2[^|]|%d|%2[^|]|%d|%d|%f",
                   v->marque,
                   v->modele,
                   v->immatriculation.lettre1,
                   &v->immatriculation.nombre,
                   v->immatriculation.lettre2,
                   &v->annee,
                   &v->kilometrage,
                   &v->prix) != 8)
        {
            free(v);
            break;
        }

        garage[*nbvoiture] = v;
        (*nbvoiture)++;
    }

    fclose(fichier);
    return *nbvoiture;
}
