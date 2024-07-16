#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail_lib.h"

#define MAX_CHAR 1000

int main(int argc, char *argv[]) {
	FILE* file=NULL;
	optionManager(file,argv,argc);
    return 0;
}
