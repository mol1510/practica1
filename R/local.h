#include <stdio.h>
#include <stdlib.h>

//Paso número uno: Definición de la estructura                                  
typedef struct datos{
    char letras;
    struct datos *sig;
} LISTA;