#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Paso número uno: Definición de la estructura
typedef struct datos{
    char letras;
    struct datos *sig;
} LISTA;