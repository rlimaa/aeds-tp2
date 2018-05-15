#include <stdio.h>
#include <stdlib.h> //Declaração das Bibliotecas

typedef struct Celula *Apontador;//Estrutura para apontar o próximo item da pilha

typedef struct //Define tipo item
{
	int x; //Coordenada x do item
	int y; //Coordenada y do item
}ponto;//Estrutura Item da Pilha

typedef struct Celula //Define tipo célula
{
    ponto coord; //item da célula
    Apontador Prox; //Apontador para a próxima célula
}Celula;//Estrutura Célula da Pilha


typedef struct //Define o tipo Pilha
{
    Apontador Fundo, Topo; //Apontadores para o fundo e o Topo da Pilha
    int Tamanho; //Inteiro contendo o tamanho da pilha
}TipoPilha; //Estrutura da Pilha


void FPVazia(TipoPilha *Pilha);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : void FPVazia(TipoPilha *Pilha);
Funcao : Cria uma pilha vazia.
Entrada : Recebe o endereço de memória no qual a pilha será criada
Saida: 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


int Vazia(TipoPilha *Pilha);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : int Vazia(TipoPilha *Pilha);
Funcao : Checa se a pilha está vazia
Entrada : Ponteiro para a pilha a ser avaliada
Saida: Inteiro contendo o resultado da comparação, 1 para Vazia, 0 para não Vazia
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


void Empilha(ponto ponto1, TipoPilha *Pilha);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : void Empilha(ponto ponto1, TipoPilha *Pilha)
Funcao : Empilha um item na pilha.
Entrada : Ponto a ser empilhado, Ponteiro para a Pilha em que ele será empilhado
Saida: 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


ponto Desempilha(TipoPilha *Pilha);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : ponto Desempilha(TipoPilha *Pilha);
Funcao : Retira o último item empilhado da pilha e retorna o seu valor.
Entrada : Ponteiro para a Pilha da qual o valor será desempilhado
Saida: Item Desempilhado.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


int Tamanho(TipoPilha *Pilha);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : int Tamanho(TipoPilha *Pilha);
Funcao : Retorna o tamanho da pilha avaliada
Entrada : Ponteiro para a pilha que será avaliada.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
