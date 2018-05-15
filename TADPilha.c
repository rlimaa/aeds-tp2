#include "TADPilha.h"//Inclui o header da TAD de pilha



void FPVazia(TipoPilha *Pilha)//Cria uma pilha vazia
{
    Pilha->Topo = (Apontador) malloc(sizeof(Celula));//Aloca memória para o Topo da pilha (nó cabeça)
    Pilha->Fundo = Pilha->Topo;//Faz o Apontador Topo apontar para o mesmo lugar que o Fundo, ou seja, pilha vazia
    Pilha->Topo->Prox = NULL;//Última posição da pilha aponta para NULL (caso da pilha vazia, a primeira é a última)
    Pilha->Tamanho = 0;//Tamanho da pilha é 0
}

int Vazia(TipoPilha *Pilha)//Verifica se a pilha está vazia
{
    return(Pilha->Topo == Pilha->Fundo);//Retorna 1 se o apontador Topo apontar para o mesmo lugar que o Fundo, ou seja, posição 0 é a última
}

void Empilha(ponto ponto1, TipoPilha *Pilha)//Empilha um item na pilha
{
    Apontador aux = (Apontador) malloc(sizeof(Celula));//Aloca memória dinamicamente para uma nova célula, que será adicionada
    Pilha->Topo->coord = ponto1;//Item da primeira posição recebe o item que está sendo empilhado
    aux->Prox = Pilha->Topo;//Apontador para a próxima posição do item a ser empilhado recebe a antiga primeira posição
    Pilha->Topo = aux;//Primeira posição da pilha recebe o apontador para o item que foi empilhado
    Pilha->Tamanho++;//Incrementa o tamanho da pilha
}

ponto Desempilha(TipoPilha *Pilha)//Desempilha um ponto da pilha
{
    Apontador q;//Declara um apontador auxiliar
    if(Vazia(Pilha))//A pilha está vazia?
    {//Sim
        printf("Erro: Pilha vazia\n");//Informa o erro ao usuário
		free(Pilha->Topo);//Libera memória alocada para a pilha 
		free(Pilha);      //        
		exit(0);//Fim da execução
    }
    q = Pilha->Topo;//Apontador auxiliar recebe a posição que será desempilhada
    Pilha->Topo = q->Prox;//Primeira posição da pilha recebe a antiga segunda posição
    free(q);//Libera a memória da célula que foi desempilhada
    Pilha->Tamanho--;//Decrementa o Tamanho da pilha
    return Pilha->Topo->coord;//Retorna o item da posição que foi desempilhada
}

int Tamanho(TipoPilha *Pilha)//Informa o tamanho da pilha
{
    return(Pilha->Tamanho);//Retorna o Tamanho da Pilha
}
