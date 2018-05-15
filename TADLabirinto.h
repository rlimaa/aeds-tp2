#include <stdio.h>
#include <stdlib.h> //Inclusão das bibliotecas
#include "TADPilha.h"
typedef struct
{
    int N;//Dimensão do Labirinto
    int x, y;//Ponto de Entrada no Labirinto
    int sx, sy;//Destino, Ponto onde está a espada
    int **mapa;//Matriz, Mapa do Labirinto
}Labirinto;//Estrutura de Dados para o Labirinto


Labirinto* LeLabirinto(char *entrada);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : Labirinto* LeLabirinto(char *entrada);
Funcao : Abre o txt contendo os dados sobre o labirinto, aloca a estrutura do Labirinto
e Grava os dados do arquivo em uma variavel do tipo Labirinto (struct criada)
Entrada : String contendo o nome do arquivo em que o labirinto se encontra
Saida: Ponteiro para uma variavel do tipo Labirinto contendo os dados lidos do arquivo txt
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


int CaminhaLabirintoRecursivo(Labirinto *lab, int x, int y, int **sol);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : int CaminhaLabirintoRecursivo(Labirinto *lab, int x, int y, int **sol); 
Funcao : Percorre, de forma recursiva, todos os possíveis caminhos do Labirinto até encontrar, ou não, o ponto em que está a espada. 
Grava na matriz Sol um caminho correto até a espada.
Entrada : Variável do tipo Labirinto contendo os dados do Labirinto, coordenada x e y em que a execução
se encontra, matriz solução.
Saida: Inteiro que informa se existe ou não caminho para o ponto em que a espada se encontra.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


int** AlocaSolucao(int n);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : int** AlocaSolucao(int n);
Funcao : Aloca uma matriz n por n e retorna um ponteiro para ela.
Entrada : inteiro contendo as dimensões da matriz
Saida: Ponteiro para a matriz alocada
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


int CaminhaLabirintoIterativo(Labirinto *lab, int **sol);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : int CaminhaLabirintoIterativo(Labirinto *lab, int **sol); 
Funcao : Percorre, de forma iterativa todos os possíveis caminhos do Labirinto até encontrar, ou não, o ponto em que está a espada. 
Grava na matriz Sol um caminho correto até a espada.
Entrada : Variável do tipo Labirinto contendo os dados do Labirinto, matriz solução.
Saida: Inteiro que informa se existe ou não caminho para o ponto em que a espada se encontra.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/



void GeraSaida(int **sol, int n, char *entrada, int DeuBom);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : void GeraSaida(int **sol, int n, char *entrada, int DeuBom);
Funcao : Gera um arquivo txt contendo um caminho até a espada, se existir, senão gera um arquivo com um '0'.
Entrada : Matriz solução, contendo o caminho (se existir), inteiro contendo as dimensões da matriz, string com 
o nome do arquivo a ser gerado, inteiro que informa se há caminho ou não.
Saida: 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

void LiberaMemoria(Labirinto *lab, int **sol);
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Prototipo : void LiberaMemoria(Labirinto *lab, int **sol)
Funcao : Libera a memória alocada para a variável Labirinto e a matriz Solução
Entrada : Variável do tipo Labirinto contendo os dados do Labirinto, matriz solução.
Saida:
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

