#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "voiture.h"


int initgarage()
{
    int taille = 0;
    printf("Entrez le nombre de voiture que vous pouvez mettre dans votre garage :");
    scanf("%d", taille);
    
    voiture *garage = malloc(taille * sizeof(voiture));
    printf("Votre garage peut acceuillir %d voiture !", taille);
    fflush(stdout);
    free(garage);
}