#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

tNo *cria_no (char chave){				
	tNo *no;
	no = malloc (sizeof(tNo));			/*Definição de uma função para criar o nodo da árvore*/
	no->chave = chave;
	no->esq = NULL;
	no->dir = NULL;
 return(no);	
}


tNo *busca (tNo *no, int c){
	if (no == NULL)
		return NULL;
	if(c == no->chave)
	  return (no);								/*Definição de uma função para buscar um determinado nodo na árvore. O seu retorno depende se o nodo foi encontrado ou não*/
	if (c < no->chave)
		return (busca(no->esq, c));
	else
		return (busca(no->dir, c));
}

void imprime_tree(tNo *raiz){
	if (raiz == NULL)
		printf("()");
	
}