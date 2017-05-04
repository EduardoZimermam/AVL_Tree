#ifndef __AVL__
#define __AVL__

typedef struct tno_s{
	char chave;						/*Estrutura do nodo de uma árvore AVL básica. */
	struct tno_s *esq;
	struct tno_s *dir;
}tNo;

tNo *criaNo (char);
tNo *busca (tNo*, int);



#endif