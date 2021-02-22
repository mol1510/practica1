#include "local.h"
#include <stdlib.h>
#include <stdio.h>

void contar_caracteres(char *argv[]){
    int x=0;
    char c;
    FILE *fp;

    fp=fopen(argv[1], "r");

    while(fscanf(fp, "%c", &c)!=EOF){
		x = x + 1;
	}
    printf("el archivo %s tiene %i caracteres\n", argv[1], x);
    fclose(fp);
}