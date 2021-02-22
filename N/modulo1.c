#include "local.h"


extern void CrearLista(char c, LISTA **aux, LISTA **inicio);
extern void RecorrerLista(LISTA *inicio);
extern void LiberarMemoria(LISTA *inicio);


int main(int argc, char *argv[]){
	FILE *fp;
	char c;
	// Paso número dos: Crear variables del tipo de la estructura
	LISTA *inicio, *aux;

	// Paso número tres: inicializar a NULL el apuntador inicio
	inicio=NULL;

	if(argc!=2){
		printf("Error al ejecutar el programa. Faltan o sobran argumentos\n");
		exit(1);
	}

	fp=fopen(argv[1], "r");
	if(fp==NULL){
		printf("Error al abrir el archivo\n");
		exit(1);
	}

	while((c=getc(fp))!=EOF){
		CrearLista(c,&aux,&inicio);
	}
	RecorrerLista(inicio);
	LiberarMemoria(inicio);
	fclose(fp);
}
