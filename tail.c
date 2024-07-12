#include <stdio.h>
#include <stdlib.h>
#include "tail_lib.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilisation: %s <nbr_de_ligne> <nom_du_fichier>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Veuillez entrer un entier positif pour n.\n");
        return 1;
    }

    FILE *fic = NULL;
    ouvrir(&fic, argv[2]);
    int nbr_ligne = compteur(fic);
    fclose(fic);

    printf("Nombre total de lignes : %d\n", nbr_ligne);

    if (nbr_ligne < n) {
        printf("Le fichier ne contient que %d lignes, affichage de toutes les lignes.\n", nbr_ligne);
        n = nbr_ligne; 
    }

    ouvrir(&fic, argv[2]);
    tail(fic, nbr_ligne - n, n);
    fclose(fic);

    return 0;
}

