#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1000

void tail_default(FILE* file,int argc, char *argv[]){
	file=fopen(argv[1],"r");
	if (file==NULL){
		perror("Erreur d'ouverture du fichier\n");
		return;
	}
	char lines[MAX_CHAR];
	int compteur1=0,compteur2=0;
	while((fgets(lines,MAX_CHAR,file)) != NULL){
		compteur1++;
	}
	rewind(file);
	while((fgets(lines,MAX_CHAR,file)) != NULL){
		compteur2++;
		if(compteur2 >= compteur1 - 10){
			printf("%s",lines);
		}
	}
	fclose(file);
}

void optionManager(FILE* file,char* argv[],int argc){
	if (argc < 2){
		printf("Utilisation: %s -<option> <fichier>\n",argv[0]);
	}
	else if (argc == 2){
		if (strcmp(argv[1],"--help")==0){
			printf("Utilisation: %s -<option> <fichier>\nAfficher les 10 dernières lignes de chaque FICHIER sur la sortie standard.\n\t-n:\tafficher les N dernières lignes, au lieu des 10\n\t-v:\tafficher toujours les en-têtes des noms de fichier\n",argv[0]);
			printf("\t-c:\tafficher les N derniers octets\n");
			printf("\t--help:\tpour afficher l'aide\n");
		}
		else {
			tail_default(file,argc,argv);
		}
	} 
	else if (argc > 2){
		///Options
		// -n
		if (strcmp(argv[1],"-n")==0){
			file=fopen(argv[3],"r");
			if (file==NULL){
				perror("Erreur d'ouverture du fichier\n");
				return;
			}
			char lines[MAX_CHAR];
			int n=atoi(argv[2]);
			int compteur1=0,compteur2=0;
			while((fgets(lines,MAX_CHAR,file)) != NULL){
				compteur1++;
			}
			rewind(file);
			while((fgets(lines,MAX_CHAR,file)) != NULL){
				compteur2++;
				if(compteur2 >= compteur1 - n + 1){
					printf("%s",lines);
				}
			}
			fclose(file);
		}
		// -v
		if (strcmp(argv[1],"-v")==0){
			printf("=> %s <=\n",argv[2]);
			file=fopen(argv[2],"r");
			if (file==NULL){
				perror("Erreur d'ouverture du fichier\n");
				return;
			}
			char lines[MAX_CHAR];
			int compteur1=0,compteur2=0;
			while((fgets(lines,MAX_CHAR,file)) != NULL){
				compteur1++;
			}
			rewind(file);
			while((fgets(lines,MAX_CHAR,file)) != NULL){
				compteur2++;
				if(compteur2 >= compteur1 - 10){
					printf("%s",lines);
				}
			}
			fclose(file);
		}
		// -c
 /*       if (strcmp(argv[1], "-c") == 0) {
            file = fopen(argv[2], "r");
            if (file == NULL) {
                perror("Erreur d'ouverture du fichier\n");
                return;
            }
            char lines[MAX_CHAR];
            int compteur = 1;
            while (fgets(lines, MAX_CHAR, file) != NULL) {
                printf("%d: %s", compteur, lines);
                compteur++;
            }
            fclose(file);
		}
*/ 
	}
}
