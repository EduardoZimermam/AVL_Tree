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



int altura(){   						/*Função para encontrar a altura da árvore*/
	if (no == NULL)
		return (-1);
	else
		return (no-> altura);
}

/*int balanceamento(){

}*/


int maior(int x, int y){
	if(x > y)
		return (x);
	else
		return (y);
}



void rotacaoEE (tNo *raiz){
 struct tNo *no;

 	no = (*raiz)-> esq;
 	no-> dir = *raiz;
 	(*raiz)-> altura = maior (altura_tNo((*raiz)-> esq), altura_tNo((*raiz)-> dir)) + 1;

 	no-> altura = maior(altura_tNo (no-> esq), (*raiz)-> altura)+1;

 	(*raiz) = no;
}



void rotacaoDD(tNo *raiz){
 struct tNo *no;

 	no = (*raiz)-> dir;
 	no-> dir = no-> esq;
 	no-> esq = (*raiz);
 	(*raiz)-> altura = maior (altura_tNo((*raiz)-> esq), altura_tNo((*raiz)-> dir)) + 1;

 	no-> altura = maior(altura_tNo(no-> dir), (*raiz)-> altura)+ 1;

 	(*raiz) = no;
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
	else
												/*Definir uma impressão por nodo, criando uma nova função que imprime nodo por nodo da árvore, criando uma pilha para abertura de cada
													parênteses e seu fechamento, assim controlamos para que não falte nenhum parenteses, para as vírgulas precisamos definir um padrão
													para que elas também fiquem corretas.*/

}

