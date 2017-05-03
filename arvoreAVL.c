#include <stdio.h>



truct tNo{
	char chave;
	struct tNo *esq;
	struct tNo *dir;
}tNo;


void criaNo (char chave){				// para qualquer árvore binaria de char
	tNO *no;
	no = malloc (sizeof( struct tNo));
	no -> chave = chave;
	no -> esq = NULL;
	no -> dir = NULL;
 return(no);	
}



tNo *busca (tNo *no, int c){
	if (no == NULL)
		return NULL;
	if(c == chave)
	  return (no) ;
	if (c < no->chave);
		return (busca ( no->esq, c));
	else 
		return (busca(no->dir, c));
}