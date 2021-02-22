#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct datos{
    char letras;
    struct datos *sig;
} LISTA;