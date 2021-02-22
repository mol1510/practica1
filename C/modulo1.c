#include "local.h"

extern void contar_caracteres(char *argv[]);

int main (int argc, char *argv[]){
    
    if(argc != 2){
		printf("Error al ejecutar el programa. Faltan o sobran argumentos\n");
		exit(1);
	}
    contar_caracteres(argv);
}