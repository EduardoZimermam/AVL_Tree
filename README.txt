FATOR DE BALANCEAMENTO

Se o valor do balanceamento for maior que 1, o nó atual esta desbalanceado = caso Esquerda Esquerda ou Caso Esquerda Direita. 
Para verificar se é o caso Esquerda Esquerda ou Esquerda Direita, obetemos o valor do balanceamento da subárvore da esquerda. 
Se o valor do balanceamento da subárvore da esquerda for maior ou igual a 0, então é o caso Esquerda Esquerda, caso contrário Esquerda Direita.
Se o valor do balanceamento for inferior a -1, o nó atual esta desbalanceado e estamos no caso Direita Direita ou no caso Direita Esquerda. 
Para verificar se é o caso Direita Direita ou Direita Esquerda., obetemos o valor do balanceamento da subárvore da direita. 
Se o valor do balanceamento da subárvore direita for menor ou igual a 0, então é o caso Direita Direita, caso contrário caso Direita Esquerda.
