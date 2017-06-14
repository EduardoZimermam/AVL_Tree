/*Autores:
Annelyse Schatzmann           GRR20151731
Eduardo Zimermam Pereira      GRR20152952  */


#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

tNo *cria_no (int valor){				
 tNo *no;
	no = (tNo*) malloc (sizeof(tNo));			/*Definição de uma função para criar o nodo da árvore*/
	no->chave = valor;
	no->esq = NULL;
	no->dir = NULL;
	no->altura = 1;

 return(no);	
}


int altura_no(tNo *no){   						/*Função para encontrar a altura da árvore*/
	if (no == NULL){
		return (0);                   
	}
	else{
		return (no-> altura);
	}
}


int balanceamento(tNo *no){                           /*Diferença nas alturas das sub-árvores*/
 int total;
 	if(no == NULL){
 		total = 0;
 	}
 	else{
 		total = altura_no(no->esq) - altura_no(no->dir);          /*Função labs retorna o valor real,podendo ser um valor negativo*/
 	}
	
 return(total);
}


int maior(int x, int y){             /*Função que determina o maior*/
	if(x > y){
		return (x);
	}
	else{
		return (y);
	}
}

tNo *minValor (tNo *no){    				/*Devolve o nó com o menor valor encontrado nessa árvore.*/

 tNo *atual = no;

 	while(atual->esq != NULL){
 		atual= atual-> esq;
 	}

 return(atual);
}


/*As rotações são aplicadas no ancestral do nó inserido cujo o valor de balanceamento passa a ser +2 ou -2*/
tNo *rotacaoEsqEsq (tNo *raiz){            /*Rotação Simples à Esquerda - quanto há dois nós para a direita*/
 tNo *no;

 	no = raiz-> dir;
 	no->esq = raiz;							  
 	raiz-> dir = no-> esq;					//filho direito passa a ser filho esquerdo da raiz

 	raiz->altura = maior (altura_no(raiz-> esq), altura_no(raiz-> dir)) + 1;
	no->altura = maior (altura_no(no-> esq),altura_no (no->dir))+1;

 return(no);
}


tNo *rotacaoDirDir(tNo *raiz){           /*Rotação Simples à Direita - quanto há dois nós para a esquerda*/
 tNo *no;

 	no = raiz->esq;
    no->dir = raiz;
	raiz->esq = no->dir;

 	raiz->altura = maior (altura_no(raiz->esq), altura_no(raiz->dir)) + 1;
	no->altura = maior(altura_no(no-> esq), altura_no (no->dir))+ 1;

 return(no);
}


tNo *insere(tNo *no, int valor){

	int b;

	if(!no){
		return (cria_no(valor));
	}

	if(valor < no->chave){
		no->esq = insere(no->esq, valor);
	}
	else if (valor > no->chave){
		no->dir = insere(no->dir, valor);
	}
	else{
		return(no);
	}

	no->altura = 1 + maior(altura_no(no->esq),altura_no(no->dir));  /*atualiza a altura do nodo*/

	b = balanceamento(no);     /*verifica se esta balanceado ou nao*/

	/*Se o nó ficar desbalanceado,existem 4 casos*/

	//Caso Esqueda Esquerda
	if (b > 1 && valor < no->esq->chave){
		return rotacaoDirDir(no);
	}

	//Caso Direita Direita
	if (b < -1 && valor > no->dir->chave)
        return rotacaoEsqEsq(no);
 
    //Caso Esquerda Direita
    if (b > 1 && valor > no->esq->chave){
        no->esq =  rotacaoEsqEsq(no->esq);
        return rotacaoDirDir(no);
    }
 
    //Caso Direita Esquerda
    if (b < -1 && valor < no->dir->chave)
    {
        no->dir = rotacaoDirDir(no->dir);
        return rotacaoEsqEsq(no);
    }

 	return(no);
}

tNo *remocao(tNo *no, int valor){
 int b;
 tNo *aux = NULL;

	if(no == NULL){
		return(no);
	}

	if( valor < no->chave){									//Se a chave a ser excluída for menor que a chave da raiz, então ela fica na subárvore da esquerda
		no->esq = remocao(no->esq,valor);
	}
	else if(valor > no->chave){								//Se a chave a ser excluída for maior que a chave da raiz, então ela fica na subárvore da direita
		no->dir = remocao(no->dir,valor);
	}

	else{												//nó com uma ou nenhuma criança

		if ((no->esq == NULL) || (no->dir == NULL)){
			
			if(aux = no->esq){                         //aux = no -> esq ? no -> esq : no -> dir;
				return(no->esq);
			}
			else{
				return(no->dir);
			}

			if (aux == NULL){				//sem filhos
				aux= no;
				no = NULL;
			}
			else{							//copia conteudo do filho
				(*no) = (*aux);
				free (aux);
			}
		}

		else{										//nós com dois filhos- obtem o sucessor

			aux = minValor (no->dir);
			no->chave = aux->chave;								//copia dados do sucessor
			no->dir = remocao(no->dir,aux->chave);				//exclui o sucessor
		}
	}

	if(no == NULL){											//se tiver apenas um no
		return(no);
	}

	no->altura = 1+ maior(altura_no(no->esq),altura_no(no->dir));  /*atualiza a altura do nodo*/

	b = balanceamento(no);     /*verifica se esta balanceado ou nao*/


		/*Se o nó ficar desbalanceado,existem 4 casos*/

		//Caso Esqueda Esquerda
		if (b > 1 && balanceamento(no->esq) >= 0){
			return rotacaoDirDir(no);
		}

		//Caso Direita Direita
		if (b < -1 && balanceamento(no->dir) <= 0){
        	return rotacaoEsqEsq(no);
		}
 
    	//Caso Esquerda Direita
    	if (b > 1 && balanceamento(no->esq) < 0){
       	 	no->esq =  rotacaoEsqEsq(no->esq);
        	return rotacaoDirDir(no);
    	}
 
    	//Caso Direita Esquerda
   		if (b < -1 && balanceamento(no->dir) > 0){
      		no->dir = rotacaoDirDir(no->dir);
       	 	return rotacaoEsqEsq(no);
    	}
 
  return (no);
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

void imprime_tree(tNo *no){

	if(no != NULL){
		printf("%d,(",no->chave);
		imprime_tree(no->esq);
		printf("),(");
		imprime_tree(no->dir);
		printf(")");
	}
}