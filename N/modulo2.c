#include <unistd.h>


#include "local.h"

extern int validar_opcion(char *opcion, int argc);
extern void recorrer_lista(char *argv[], int argc, LISTA *inicio);
extern void liberar_memoria(LISTA *inicio);
extern void crear_lista(char c, LISTA **inicio);

void copiar_normal(char *argv[], int argc);
void copiar_al_reves(char *argv[], int argc);
void num_caracteres(char *argv[], int argc);
void num_espacios(char *argv[], int argc);
void imprimir_datos(char *argv[], int argc);
void imprimir_ayuda();
void opcion(int argc, char *argv[])
{
    void (*opciones[])(char *argv[], int argc) = {copiar_normal, copiar_al_reves, num_caracteres, num_espacios, imprimir_datos, imprimir_ayuda};
    int index;
    if(argc == 2)
    {
        system("clear");
        validar_opcion(argv[1], argc);
        imprimir_ayuda();

    }else if(argc == 3 || argc == 4)
    {
        system("clear");
        printf("%i", index);
        index = validar_opcion(argv[1], argc);
        (*opciones[index])(argv, argc);

    }else if(argc == 5)
    {
        system("clear");
        index = validar_opcion(argv[1], argc);
        (*opciones[index])(argv, argc);

        if(index != 4)
        {
            (*opciones[4])(argv, argc);
        }
    }
}

void copiar_normal(char *argv[], int argc){
    FILE *fp, *fp1;
    char *file = "salida.arch";
    char a;

    if(argc > 2){
        file = argv[3];
    }
    fp=fopen(argv[2], "r");
    fp1=fopen(strdup(file), "w");
    if(fp==NULL){
        printf("ERROR NO EXISTE EL ARCHIVO\n");
        exit(1);
    }
    while(fscanf(fp, "%c", &a) != EOF){
        putc(a, fp1);
    }

    fclose(fp);
    fclose(fp1);
}

void copiar_al_reves(char *argv[], int argc){
    LISTA *inicio;
    char c;
    FILE *fp;
    inicio =NULL;
    fp=fopen(argv[2], "r");
    if(fp==NULL){
        printf("ERROR\n");
        exit(1);
    }
     while((c=getc(fp)) != EOF){
        crear_lista(c, &inicio);
    }
    recorrer_lista(argv, argc, inicio);
    liberar_memoria(inicio);
    fclose(fp);
}

void num_caracteres(char *argv[], int argc){
    int x=0;
    char c;
    FILE *fp;

    fp=fopen(argv[2], "r");

    while(fscanf(fp, "%c", &c)!=EOF){
		x = x + 1;
	}
    printf("el archivo %s tiene %i caracteres\n", argv[2], x);
    fclose(fp);
}

void num_espacios(char *argv[], int argc){
    int x=0;
    char c;
    FILE *fp;

    fp=fopen(argv[2], "r");

    while(fscanf(fp, "%c", &c)!=EOF){
        if(c == ' '){
		    x = x + 1;
        }
	}
    printf("el archivo %s tiene %i espacios\n", argv[2], x);
    fclose(fp);
}

void imprimir_datos(char *argv[], int argc){
    FILE *fp;
    char c;

}

void imprimir_ayuda(){
    printf("puto\n");

}