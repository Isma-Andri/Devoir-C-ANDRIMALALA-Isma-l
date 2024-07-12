#include <stdio.h>
//#define LONGUEUR_MAX 100
void ouvrir(FILE **fic, const char *fichier);
int compteur(FILE *fic);
void tail(FILE *fic, int ligne_depart, int n, int verbose);
void optionq(int argc, char *argv[], int *n, int *verbose, char **fichier);
