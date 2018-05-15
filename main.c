#include "TADLabirinto.h" //
//#include "TADPilha.h"	  //Inclusão das TADs		

int main(int argc, char *argv[])//Assinatura da função principal com os argumentos como parâmetros
{
    Labirinto *lab = LeLabirinto(argv[1]);//Declara um ponteiro para uma variável do tipo Labirinto e le os dados de um txt
	int DeuBom,i,j;//inteiros para loop e resposta da situação final do código
    int **sol = AlocaSolucao(lab->N);//Declara um ponteiro para ponteiros e aloca a matriz
	printf("Labirinto Lido com Sucesso:\n");
	printf("Entrada de Teseu: [%d] [%d].\nPosicao da espada: [%d] [%d]\n\n",lab->x, lab->y, lab->sx, lab->sy);
    if(argv[3][0] == '0')//O terceiro argumento é 0 (Execução deve ser Recursiva)?
    {//sim
		printf("Utilizando funcao Recursiva\n");
        DeuBom = CaminhaLabirintoRecursivo(lab, lab->x, lab->y, sol);//Chama função recursiva
    }
    else//não
    {
		printf("Utilizando funcao Iterativa\n");
        DeuBom = CaminhaLabirintoIterativo(lab, sol);//Chama função iterativa
    }
    if(DeuBom == 1)//O caminho foi encontrado?
        printf("\n\nDeu Bom! :D\nUm caminho até a espada foi encontrado:\n");//Sim
    else//Não
        printf("\n\nDeu Ruim! :/\nNao existe caminho até a espada.\n");    

    GeraSaida(sol, lab->N, argv[2], DeuBom);//Chama a função que gera a saída
	printf("\nArquivo %s gerado com Sucesso.\n", argv[2]);
    LiberaMemoria(lab, sol);//Chama a função que Libera a memória
	printf("Memória Liberada, no Leak ;)\n");
    return 0;
	//Fim da execução
}
