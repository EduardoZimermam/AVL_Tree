/*Autores:
Annelyse Schatzmann           GRR20151731
Eduardo Zimermam Pereira      GRR20152952  */


#ifndef __AVL__
#define __AVL__

typedef struct tno_s{
	int chave;
	int altura;						/*Estrutura do nodo de uma árvore AVL básica. */
	struct tno_s *esq;
	struct tno_s *dir;
}tNo;


/*Protótipos das funções para construção da biblioteca. */
tNo *cria_no (int valor);
int altura_no(tNo *no);
int balanceamento(tNo *no);
int maior(int x, int y);
tNo *minValor (tNo *no);
tNo *rotacaoEsqEsq (tNo *raiz);
tNo *rotacaoDirDir(tNo *raiz);
tNo *insere(tNo *no, int valor);
tNo *remocao(tNo *no, int valor);
tNo *busca (tNo*, int valor);
void imprime_tree(tNo *no);			

#endif
