#include "local.h"

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
}