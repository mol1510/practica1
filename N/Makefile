# Makefile del programa de ejemplos de texto

ejemploArchivo.out: modulo1.o modulo2.o modulo3.o
	gcc -o ejemploArchivo.out modulo1.o modulo2.o modulo3.o

modulo1.o: modulo1.c
	gcc -c modulo1.c

modulo2.o: modulo2.c
	gcc -c modulo2.c

modulo3.o: modulo3.c
	gcc -c modulo3.c

clean:
	rm *.o
	clear