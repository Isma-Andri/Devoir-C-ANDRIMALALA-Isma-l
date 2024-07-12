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

void tail(FILE *fic, int start_line, int n) {
    char chaine[LONGUEUR_MAX];
    int current_line = 0;

    while (fgets(chaine, sizeof(chaine), fic) != NULL) {
        if (current_line >= start_line) {
            printf("%s", chaine);
        }
        current_line++;
    }
}

