CFLAGS = -Wall

all: busca

busca: arvoreAVL.o arvoreAVL.h
	gcc arvoreAVL.o arvoreAVL.h -o busca $(CFLAGS)

arvoreAVL.o: arvoreAVL.c arvoreAVL.h
	gcc -c arvoreAVL.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm busca