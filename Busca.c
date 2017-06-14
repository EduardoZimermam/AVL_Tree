#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

int main(int argc, char **argv){ 
 FILE *arq;
 tNo *no = NULL;
 int valor;
 char ch;
 

	arq = fopen (argv[1], "r") ;
 
	if ( ! arq ){
    	arq = stdin; 											
   	}

	fscanf(arq,"%c %d",&ch,&valor); 
	while(!feof (arq)){
		switch(ch){
			case 'i':                     
				no = insere(no, valor);
				printf("i %d\n(",valor);
				imprime_tree(no);
				printf(")\n\n");
			break;

			case 'b':					    
				printf("b %d\n",valor);
				busca(no,valor);
			break;

			case 'r':					 
				//remove(no,valor);
				printf("r %d\n(",valor);
				imprime_tree(no);
				printf(")\n\n");
			break;
		}
		fscanf(arq,"%c %d",&ch,&valor); 
	}
 fclose(arq);
 return(0);
}
