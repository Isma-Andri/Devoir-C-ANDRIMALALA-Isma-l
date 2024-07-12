#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail_lib.h"



int main(int argc, char *argv[]) {
    int n = 10;
    int verbose = 0;
    char *fichier = NULL;

    optionq(argc, argv, &n, &verbose, &fichier);

    if (fichier == NULL) {
        printf("Veuillez spécifier un nom de fichier.\n");
        return 1;
    }

    FILE *fic = NULL;
    ouvrir(&fic, fichier);
    int nbr_ligne = compteur(fic);
    fclose(fic);

    ouvrir(&fic, fichier);
    tail(fic, nbr_ligne - n, n, verbose);
    fclose(fic);

    return 0;
}

