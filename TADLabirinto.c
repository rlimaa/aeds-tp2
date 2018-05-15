#include "TADLabirinto.h" //Inclui o Header da TAD do Labirinto
//#include "TADPilha.h" //Inclui o Header da TAD de Pilha

int** AlocaSolucao(int n) //Aloca matriz solução
{
    int i,j; //variáveis utilizadas no laço iterativo
	int **sol = (int**) calloc(n, sizeof(int*));//Aloca as n linhas da matriz solução dinamicamente
    if(sol == NULL) //A memória foi alocada?
	{//Não
		printf("Erro, Memoria nao alocada\n");
        exit(0); //Fim da execução
	}
    for(i=0; i < n; i++)//Laço para alocar as colunas da matriz
    {
		sol[i] = (int *) calloc (n, sizeof(int));//Aloca cada uma das n colunas da matriz
		if(sol[i] == NULL)//As colunas foram alocadas?
		{//Não
			printf("Erro, Memoria nao alocada\n");
			exit(0);//Fim da execução
		}
	}
	//Matriz alocada com sucesso
    return sol;//Retorna ponteiro para a matriz
}

int CaminhaLabirintoIterativo(Labirinto *lab, int **sol)//Percorre todos os caminhos possíveis iterativamente
{
    TipoPilha *pilha = (TipoPilha *) malloc(sizeof(TipoPilha));//Aloca memória para a pilha
	int count=0;//inteiro para o contador
    ponto p;//ponto que percorre o labirinto
    p.x = lab->x;//inicia o ponto na entrada do labirinto
    p.y = lab->y;//inicia o ponto na entrada do labirinto
    FPVazia(pilha);//Cria uma pilha vazia
	if(p.x == lab->x && p.y == lab->y)
	{
		sol[p.x][p.y]=1;
		free(pilha->Topo);
		free(pilha);
		return 1;
	}	
	if(lab->mapa[lab->sx][lab->sy] == 1)//A espada está em uma parede?
	{//Sim
		free(pilha->Topo);//
		free(pilha);      //Libera a memória da pilha
		return 0;//retorna caminho impossível
	}
    if(lab->mapa[p.x][p.y] == 1)//A entrada é uma parede?
	{//Sim
		free(pilha->Topo);//
		free(pilha);      //Libera a memória da pilha
	    return 0;//retorna caminho impossível
	}
	else//Não
		sol[p.x][p.y] = 1;//Entrada do labirinto pertence ao caminho de saída
    do//Início do Loop
    {
		if(p.x+1<(lab->N))//Um passo abaixo da posição atual está dentro do labirinto?
		    if(lab->mapa[p.x+1][p.y] == 0)//Sim, a posição logo abaixo de Teseu é parede?
		    {//Não
		        lab->mapa[p.x][p.y] = 1;//Marca a posição onde Teseu já esteve
		        p.x++;//Atualiza a posição de Teseu
		        Empilha(p, pilha);//Empilha essa posição, pois ela pode fazer ser parte do caminho correto
		    }
		if(p.y+1<(lab->N))//A posição imediatamente a direita da posição de Teseu está dentro do Labirinto?
		    if(lab->mapa[p.x][p.y+1] == 0)//Sim, Teseu pode avançar para a posição imediatamente a sua direita?
		    {//Sim
		        lab->mapa[p.x][p.y] = 1;//Marca a posição onde Teseu já esteve
		        p.y++;//Atualiza a posição de Teseu
		        Empilha(p, pilha);//Empilha essa posição, pois ela pode fazer parte do caminho correto
		    }
		if(p.x-1>=0)//A posição imediatamente acima de Teseu está dentro do Labirinto?
		    if(lab->mapa[p.x-1][p.y] == 0)//Sim, Teseu pode avançar para a posição imediatamente acima de sua posição atual?
		    {//Sim
		        lab->mapa[p.x][p.y] = 1;//Marca a posição onde Teseu já esteve
		        p.x--;//Atualiza a posição de Teseu
		        Empilha(p, pilha);//Empilha essa posição, pois ela pode fazer parte do caminho correto
		    }
		if(p.y-1>=0)//A posição imediatamente a esquerda de Teseu está dentro do Labirinto?
		    if(lab->mapa[p.x][p.y-1] == 0)//Sim, Teseu pode ir para a esquerda?
		    {//Sim
		        lab->mapa[p.x][p.y] = 1;//Marca a posição onde Teseu já esteve?
		        p.y--;//Atualiza a posição de Teseu
		        Empilha(p, pilha);//Empilha essa posição, pois ela pode fazer parte do caminho correto
		    }
        if(((lab->mapa[p.x+1][p.y]) && (lab->mapa[p.x-1][p.y]) && (lab->mapa[p.x][p.y+1]) && (lab->mapa[p.x][p.y-1])) && ((p.x!=lab->sx) || (p.y!=lab->sy))) //Teseu está em um beco sem saída e ainda não encontrou a espada?
        {//Sim
			lab->mapa[p.x][p.y]=1;//Marca a posição onde ele já esteve
            if(!Vazia(pilha))//A pilha contendo o caminho até o ponto atual está vazia?
			{//Não
				p = Desempilha(pilha);//Teseu volta para sua posição anterior
				if(!((lab->mapa[p.x+1][p.y]) && (lab->mapa[p.x-1][p.y]) && (lab->mapa[p.x][p.y+1]) && (lab->mapa[p.x][p.y-1])))//Teseu está em um beco sem saída em sua posição atual (após voltar uma posição)?
					Empilha(p,pilha);//Não, Empilha novamente essa posição, pois ainda existem caminhos não explorados (possivelmente corretos) que passam por ela
			}
			else{//Sim, a pilha está vazia e Teseu está em um beco sem saída. Ou seja, ele voltou a posição inicial e não tem pra onde ir
				free(pilha->Topo);//
				free(pilha);	  //Libera memória alocada para a pilha
				return 0;//Retorna 0, não existe caminho possível
			}
        }
		
    }while((p.x != lab->sx) || (p.y != lab->sy ));//Condição do loop, enquanto Teseu não encontrou a espada

	while(!Vazia(pilha))//Enquanto a pilha não estiver vazia executa o bloco a seguir
    {
        p = Desempilha(pilha);//Todos os caminhos errados foram desempilhados, resta na pilha apenas o caminho correto, Teseu retorna então pelo caminho correto
		sol[p.x][p.y] = 1;//Marca na matriz solução o caminho correto, por onde Teseu passa.
    }
	free(pilha->Topo);//
	free(pilha);	  //Libera memória da pilha
	return 1;//Retorna 1, caminho encontrado
}

int CaminhaLabirintoRecursivo(Labirinto *lab, int x, int y, int **sol)//Percorre todos os caminhos possíveis recursivamente
{
    if(lab->mapa[x][y] == 1)//A posição em que Teseu está é uma parede?(utilizado principalmente caso a entrada seja uma parede)
        return 0;//Sim, retorna 0, não existe caminho
	if(lab->mapa[lab->sx][lab->sy] == 1)//A espada se encontra em uma parede?
		return 0;//Sim, retorna 0, não existe caminho
    if((x == lab->sx) && (y == lab->sy))//Condição de parada, Teseu encontrou a espada
    {//Sim
        sol[x][y] = 1;//Marca a solução, posição faz parte do caminho certo
        return 1;//Retorna 1, existe caminho
    }
    else//A espada ainda não foi encontrada
    {
        if((lab->mapa[x][y] == 0) && (sol[x][y] == 0))//A posição atual não é parede e Teseu ainda não esteve nela?
        {//Sim
            sol[x][y] = 1;//Marca como uma posição que Teseu já visitou
			if(x+1 < lab->N)//A posição imediatamente abaixo de Teseu faz parte do labirinto?
		        if(CaminhaLabirintoRecursivo(lab, x+1, y, sol))//Sim, Chama a mesma função para a posição abaixo de Teseu
		            return 1;//Se a posição abaixo da atual fizer parte da solução, Retorna 1
			if(y+1 < lab->N)//A posição imediatamente a direita de Teseu faz parte do labirinto?
		        if(CaminhaLabirintoRecursivo(lab, x, y+1, sol))//Sim, chama a mesma função para a posição a direita de Teseu
		            return 1;//Se a posição a direita de Teseu fizer parte da solução, Retorna 1
			if(x-1 >= 0)//A posição acima de Teseu faz parte do Labirinto?
		        if(CaminhaLabirintoRecursivo(lab, x-1, y, sol))//Sim, chama a mesma função para a posição acima de Teseu
		            return 1;//Se a posição a esquerda de Teseu fizer parte da solução, Retorna 1
			if(y-1 >= 0)//A posição a esquerda de Teseu faz parte do labirinto?
		        if(CaminhaLabirintoRecursivo(lab, x, y-1, sol))//Sim, chama a mesma função para a posição a esquerda de Teseu
		            return 1;//Se a posição a esquerda de Teseu fizer parte da solução retorna 1
            sol[x][y] = 0;//Após todas as chamadas recursivas se nenhum dos vizinhos da posição atual fizer parte da solução marca 0 na solução
        }
    }
    return 0;//A posição atual nao faz parte da solução, retorna 0
}

void GeraSaida(int **sol, int n, char *entrada, int DeuBom)//Gera a saída
{
    FILE *file;//Declara ponteiro do tipo file
    file = fopen(entrada,"w");//Abre um arquivo com o nome guardado na string entrada, argumento para escrita no arquivo
    int i, j;//variáveis para o loop
	if(DeuBom==1)//O labirinto tem solução?
		for(i=0; i<n; i++)//Sim, laço para escrita das linhas da solução na arquivo
		{
		    for(j=0; j<n; j++)//laço para a escrita das colunas da solução no arquivo
		    {
		        fprintf(file, "%d ", sol[i][j]);//Escreve o conteúdo da posição atual no arquivo
		    }
		    fprintf(file,"\n");//Quebra a linha, após a escrita de todas as colunas da linha i
		}
	else//Não tem solução
		fprintf(file,"0");//Escreve um 0 no arquivo de saída
    fclose(file);//Fecha o arquivo de saída
}

void LiberaMemoria(Labirinto *lab, int **sol)//Libera a memória
{
    int  i;//Variável para o loop
    for (i=0; i<lab->N; i++)//laço para liberar as colunas da matriz sol
        free(sol[i]);//libera a coluna i da matriz sol
    free(sol);//libera as linhas da matriz sol
	for(i=0; i<lab->N;i++)//laço para liberar as colunas da matriz que contém o mapa do labirinto
		free(lab->mapa[i]);//libera a coluna i do mapa do labirinto
	free(lab->mapa);//libera as linhas do mapa do labirinto
	free(lab);//libera a estrutura do labirinto
}

Labirinto* LeLabirinto(char* entrada)//Le o labirinto
{
    FILE *file;//Declara ponteiro do tipo arquivo
    file = fopen(entrada, "r");//Abre o arquivo com nome contido na string entrada, argumento para leitura
    Labirinto *lab = (Labirinto*) malloc(sizeof(Labirinto));//Aloca memória dinamicamente para o tipo Labirinto
	if(lab == NULL)//A memória pôde ser alocada?
	{//Não
		printf("Erro ao alocar memoria para o Labirinto\n");//informa o erro ao usuário
		exit(0);//Fim da execução
	}
    if(file == NULL)//O arquivo pôde ser aberto?
    {//Não
        printf("Erro ao abrir arquivo\n");//Informa o erro ao usuário
        exit(1);//Fim da execução
    }
    fscanf(file,"%d %d %d %d %d", &lab->N, &lab->x, &lab->y, &lab->sx, &lab->sy);//Lê os parâmetros do labirinto, dimensões, posição de entrada e posição da espada
    int i,j;//variáveis para loop
    lab->mapa = (int **) malloc(sizeof(int *) * lab->N);//Aloca dinamicamente as lab->N linhas da matriz do mapa do labirinto
	if(lab->mapa == NULL)//As linhas puderam ser alocadas?
	{//Não
		printf("Erro ao alocar memoria para o Labirinto");//Informa o erro ao usuário
		exit(0);//Fim da execução
	}
    for(i = 0; i < lab->N; i++)//loop para alocação das lab->N colunas da matriz
    {
        lab->mapa[i] = (int *) malloc(sizeof(int) * lab->N);//Aloca a coluna i da matriz com lab->N posições
		if(lab->mapa[i] == NULL)//A coluna i pôde ser alocada?
			{//Não
				printf("Erro ao alocar memoria para o Labirinto");//Informa o erro ao usuário
				exit(0);//Fim da execução
			}
    }
    for(i=0; i<lab->N; i++)//laço para percorrer as linhas da matriz mapa
        for(j=0; j<lab->N; j++)//laço para percorrer as colunas da matriz mapa
            fscanf(file, "%d",&lab->mapa[i][j]);//Lê os dados contidos no arquivo txt e grava na posição da matriz mapa
    fclose(file);//Fecha o arquivo txt
    return lab;//Retorna um ponteiro para a estrutura contendo os dados do Labirinto
}
