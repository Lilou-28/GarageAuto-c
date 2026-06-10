# GarageAuto-c

Mini-projet en langage C realise dans le cadre de la presentation finale du cours de langages compiles.

Le projet est une application terminal de gestion d'un garage automobile. L'utilisateur choisit la capacite maximale du garage, puis peut ajouter des voitures, afficher la liste des voitures enregistrees, supprimer une voiture et quitter proprement le programme.

## Sujet choisi

Gestion d'un garage automobile.

Ce sujet est proche des exemples de gestion proposes dans la consigne, comme une bibliotheque ou un annuaire. Il permet de manipuler des donnees structurees, d'utiliser un menu interactif, de gerer une collection d'elements et de montrer les notions importantes du langage C.

## Objectifs du projet

Le programme montre la capacite a :

- ecrire, compiler et executer un programme en C ;
- organiser un projet en plusieurs fichiers `.c` et `.h` ;
- utiliser des variables, des types simples et des types structures ;
- utiliser des conditions, des boucles et un menu interactif ;
- creer et appeler des fonctions ;
- manipuler des pointeurs ;
- allouer et liberer de la memoire dynamiquement ;
- produire un affichage clair dans le terminal.

## Fonctionnalites

- Choisir la taille maximale du garage au lancement.
- Ajouter une voiture avec :
  - marque ;
  - modele ;
  - immatriculation au format `AB - 123 - CD` ;
  - annee ;
  - kilometrage ;
  - prix.
- Afficher toutes les voitures presentes dans le garage.
- Supprimer une voiture en choisissant son numero dans la liste.
- Quitter le programme en liberant la memoire utilisee.

## Structure du projet

| Fichier | Role |
| --- | --- |
| `main.c` | Point d'entree du programme, allocation du garage, boucle principale et liberation finale de la memoire. |
| `voiture.h` | Definition des structures `immatriculation` et `voiture`, prototypes des fonctions liees aux voitures. |
| `voiture.c` | Creation dynamique d'une voiture, saisie des informations, verification de l'immatriculation et affichage d'une voiture. |
| `garage.h` | Prototypes des fonctions de gestion du garage. |
| `garage.c` | Ajout, affichage et suppression des voitures dans le tableau de pointeurs. |
| `menu.h` | Prototype de la fonction d'affichage du menu. |
| `menu.c` | Affichage du menu principal dans le terminal. |

## Compilation

Commande de compilation :

```bash
gcc -Wall -Wextra -std=c11 -o garage main.c garage.c menu.c voiture.c
```

Sous Windows, il est aussi possible de produire un executable `.exe` :

```bash
gcc -Wall -Wextra -std=c11 -o garage.exe main.c garage.c menu.c voiture.c
```

Verification effectuee :

```bash
gcc -Wall -Wextra -std=c11 -fsyntax-only main.c garage.c menu.c voiture.c
```

Cette verification ne signale pas d'erreur bloquante.

## Execution

Sous Linux/macOS :

```bash
./garage
```

Sous Windows :

```bash
.\garage.exe
```

## Exemple d'utilisation

```text
Combien de voitures max dans le garage ? 3

===== Menu GarageAuto =====
1. Ajouter une voiture
2. Retirer une voiture
3. Afficher le garage
4. Quitter
Choix : 1
Entrez la marque de votre voiture : Renault
Entrez le modele de votre voiture : Clio
Entrez l'immatriculation (AB - 123 - CD) : AB - 123 - CD
Entrez l'annee de votre voiture : 2018
Entrez le kilometrage de votre voiture : 85000
Entrez le prix de votre voiture : 9500
```

## Notions techniques utilisees

### Variables et types

Le programme utilise plusieurs types adaptes aux informations manipulees :

- `int` pour le choix du menu, la taille du garage, l'annee et le kilometrage ;
- `float` pour le prix d'une voiture ;
- tableaux de `char` pour la marque, le modele et les lettres de l'immatriculation ;
- pointeurs pour manipuler dynamiquement les voitures et le garage.

### Structures

Deux structures sont definies dans `voiture.h` :

```c
typedef struct {
    char lettre1[3];
    int nombre;
    char lettre2[3];
} immatriculation;

typedef struct {
    char marque[20];
    char modele[20];
    immatriculation immatriculation;
    int annee;
    int kilometrage;
    float prix;
} voiture;
```

La structure `voiture` regroupe toutes les informations d'un vehicule. Elle contient elle-meme une structure `immatriculation`, ce qui rend les donnees plus organisees.

### Fonctions

Le projet est decoupe en fonctions pour rendre le code plus lisible :

- `affichermenu` affiche le menu principal ;
- `initvoiture` cree et initialise une voiture ;
- `infosvoiture` affiche les informations d'une voiture ;
- `ajouterVoiture` ajoute une voiture au garage ;
- `affichergarage` affiche toutes les voitures ;
- `supprimervoiture` supprime une voiture choisie par l'utilisateur.

### Conditions et boucles

Le programme utilise :

- une boucle `do while` pour afficher le menu jusqu'au choix de sortie ;
- un `switch` pour executer l'action correspondant au choix de l'utilisateur ;
- des conditions `if` pour verifier les erreurs de saisie, la capacite du garage et les allocations memoire ;
- des boucles `for` pour parcourir les voitures du garage ;
- une boucle `while` pour redemander l'immatriculation tant que le format est incorrect.

### Pointeurs

Les pointeurs sont utilises pour manipuler les donnees sans les copier inutilement :

- `voiture *v` represente une voiture allouee dynamiquement ;
- `voiture **garage` represente un tableau dynamique de pointeurs vers des voitures ;
- `int *nbvoiture` permet aux fonctions de modifier directement le nombre de voitures dans le garage.

### Allocation et liberation de memoire

La memoire est allouee dynamiquement avec `malloc` :

- dans `main.c`, le garage est alloue selon la taille choisie par l'utilisateur ;
- dans `voiture.c`, chaque voiture est allouee lors de sa creation.

La memoire est liberee avec `free` :

- quand une voiture est supprimee ;
- quand une voiture ne peut pas etre ajoutee parce que le garage est plein ;
- a la fin du programme, pour toutes les voitures restantes et pour le tableau du garage.

Cette gestion est importante en C, car le langage ne possede pas de ramasse-miettes automatique.

## Choix techniques

Le garage est represente par un tableau dynamique de pointeurs vers des structures `voiture`.

Ce choix permet :

- de fixer la capacite du garage au lancement ;
- d'ajouter facilement une voiture en stockant son adresse ;
- de supprimer une voiture en liberant sa memoire puis en decalant les elements du tableau ;
- de montrer clairement l'utilisation des pointeurs et de l'allocation dynamique.

Le projet est separe en plusieurs modules pour mieux organiser le code :

- un module pour les voitures ;
- un module pour le garage ;
- un module pour le menu ;
- un fichier principal pour coordonner le programme.

## Points importants pour la presentation orale

Pendant la presentation, il est possible d'expliquer :

- le role de la compilation avec `gcc` ;
- la difference entre les fichiers `.c` et `.h` ;
- pourquoi une structure est adaptee pour representer une voiture ;
- pourquoi le garage est un tableau dynamique ;
- comment `malloc` et `free` sont utilises ;
- comment les pointeurs permettent de modifier le nombre de voitures depuis les fonctions ;
- comment le menu permet de rendre le programme interactif ;
- comment le programme gere les erreurs simples de saisie.

## Limites et ameliorations possibles

Le projet fonctionne en memoire vive : les voitures disparaissent lorsque le programme se termine. Une amelioration possible serait d'ajouter une sauvegarde dans un fichier.

Autres ameliorations possibles :

- rechercher une voiture par immatriculation ;
- modifier une voiture existante ;
- trier les voitures par prix, annee ou kilometrage ;
- sauvegarder et charger automatiquement le garage ;
- renforcer la validation des saisies utilisateur.

## Conclusion

GarageAuto-c repond aux attendus du mini-projet en langage C : il est compilable, executable, interactif, organise en plusieurs fichiers et utilise les notions essentielles du cours, notamment les structures, les fonctions, les pointeurs et la gestion dynamique de la memoire.


GitHub : https://github.com/Lilou-28/GarageAuto-c.git
