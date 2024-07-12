#include <stdio.h>
#include <stdlib.h>
#include "tail_lib.h"

void ouvrir(FILE **fic, const char *fichier) {
    *fic = fopen(fichier, "r");
    if (*fic == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
}

int compteur(FILE *fic) {
    int nbr_ligne = 0;
    char chaine[LONGUEUR_MAX];

    while (fgets(chaine, sizeof(chaine), fic) != NULL) {
        nbr_ligne++;
    }

    return nbr_ligne;
}

void tail(FILE *fic, int start_line, int n, int verbose) {
    char chaine[LONGUEUR_MAX];
    int current_line = 0;

    if (start_line < 0) start_line = 0;

    while (fgets(chaine, sizeof(chaine), fic) != NULL) {
        if (current_line >= start_line) {
            printf("%s", chaine);
        }
        current_line++;
    }

    if (verbose) {
        printf("Nombre total de lignes : %d\n", current_line);
        if (current_line < n) {
            printf("Le fichier ne contient que %d lignes, affichage de toutes les lignes.\n", current_line);
        }
    }
}

void optionq(int argc, char *argv[], int *n, int *verbose, char **fichier) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                *n = atoi(argv[++i]);
                if (*n <= 0) {
                    printf("Veuillez entrer un entier positif pour n.\n");
                    exit(1);
                }
            } else {
                printf("Option -n nécessite un argument.\n");
                exit(1);
            }
        } else if (strcmp(argv[i], "-v") == 0) {
            *verbose = 1;
        } else {
            *fichier = argv[i];
        }
    }
}

