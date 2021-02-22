#include <stdlib.h>
#include <stdio.h>

extern void opcion(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    if(argc < 2 || argc > 5)
    {
        printf("ERROR: Para consultar ayuda -h\n");
        exit(1);
    }

    opcion(argc, argv);

}