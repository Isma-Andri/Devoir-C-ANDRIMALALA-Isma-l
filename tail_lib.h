#include <stdio.h>
#define LONGUEUR_MAX 100
void ouvrir(FILE **fic, const char *fichier);
int compteur(FILE *fic);
void tail(FILE *fic, int start_line, int n);
