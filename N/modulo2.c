#include <unistd.h>


#include "local.h"

extern int validar_opcion(char *opcion, int argc);
extern void RecorrerLista(LISTA *inicio);
extern void LiberarMemoria(LISTA *inicio);
extern void CrearLista(char c, LISTA **aux, LISTA **inicio);

void opcion(int argc, char *argv[])
{
    void (*opciones[])(char *argv[], int argc) = {copiar_normal, copiar_alreves, num_caracteres, num_espacios, imprimir_datos, imprimir_ayuda};
    int index;
    if(argc == 2)
    {
        system("clear");
        validar_opcion(argv[1], argc);
        imprimir_ayuda();

    }else if(argc == 3 || argc == 4)
    {
        system("clear");
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
