#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "local.h"



int validar_opcion(char *opcion, int argc)
{
    char *opciones[] = {"-n", "-r", "-c", "-e", "-v", "-h"};
    char *temp;
    if(argc == 2)
    {
        if(strcmp(opcion, opciones[5]) == 0)
        {
            return 1;
        }else if(strcmp(opcion, opciones[5]) != 0);
        {
            opcion[1] = tolower(opcion[1]);
            if(strcmp(opcion, opciones[5]) == 0)
            {
                printf("ERROR: ¿quisiste decir: %s ?\n", opciones[5]);
                exit(1);
            }
        }
        printf("ERROR: Para ayuda -h\n");
        exit(1);
    }

    for(int i = 0; i < 6; i++)
    {
        temp = strdup(opcion);
        if(strcmp(opcion, opciones[i]) == 0)
        {
            return i;
        }else
        {
            temp[1] = tolower(temp[1]);
            if(strcmp(temp, opciones[i]) == 0)
            {
                printf("ERROR: ¿quisiste decir %s?\n", opciones[i]);
                exit(1);
            }
        }
    }

    printf("ERROR: Para ayuda -h\n");
    exit(1);
}


void CrearLista(char c, LISTA **aux, LISTA **inicio){
	LISTA *nodo;

	// 1.- Crear el espacio
	nodo=malloc(sizeof(LISTA));
	if(nodo==NULL){
		printf("No hay memoria\n");
		exit(1);
	}

	// 2.- Llenar la información
	nodo->letras=c;

	// 3.- Encadenar
	if(*inicio==NULL){
		*inicio=nodo;
	}
	else{
		(*aux)->sig=nodo;
	}
	*aux=nodo;
	nodo->sig=NULL;
}


void RecorrerLista(LISTA *inicio){
	LISTA *nodo;
    FILE *fp;
    fp=fopen("salida.arch", "w");
	nodo=inicio;
		while(nodo!=NULL){
            fprintf(fp,"%c", nodo->letras);
			nodo=nodo->sig;
		}
        fclose(fp);
}

void LiberarMemoria(LISTA *inicio){
	LISTA *nodo;
	nodo=inicio;

	while(nodo!=NULL){
		inicio=nodo->sig;
		free(nodo);
		nodo=inicio;
}