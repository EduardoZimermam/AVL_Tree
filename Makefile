CFLAGS = -Wall
LDFLAGS = -g

all: busca

busca: Busca.o arvoreAVL.o arvoreAVL.h
	gcc Busca.o arvoreAVL.o arvoreAVL.h -o busca $(CFLAGS) $(LDFLAGS)

Busca.o: Busca.c
	gcc -c Busca.c $(CFLAGS) $(LDFLAGS)

arvoreAVL.o: arvoreAVL.c arvoreAVL.h
	gcc -c arvoreAVL.c $(CFLAGS) $(LDFLAGS)

clean:
	-rm *.o

purge:
	-rm busca