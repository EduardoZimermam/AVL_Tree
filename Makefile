CFLAGS = -Wall

all: busca

busca: Busca.o arvoreAVL.o arvoreAVL.h
	gcc Busca.o arvoreAVL.o arvoreAVL.h -o busca $(CFLAGS)

Busca.o: Busca.c
	gcc -g -c Busca.c $(CFLAGS)

arvoreAVL.o: arvoreAVL.c arvoreAVL.h
	gcc -c arvoreAVL.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm busca