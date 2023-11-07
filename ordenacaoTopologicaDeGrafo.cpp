#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////////////////////////////////////////////////////
// Programa que implementa a ordenação topológica //
///////////////////////////////////////////////////

///////////////////////////////
// Declaração de constantes //
/////////////////////////////

const int QTDVERTICES = 6;

//////////////////////////////
// Função que cria o grafo //
////////////////////////////

void criar(int grafo[QTDVERTICES][QTDVERTICES], int aleatorio) {
	
	int conexao = 0;
	int i = 0;
	int j = 0;
	
	for (i = 0; i < QTDVERTICES; i++) {
		
		for (j = 0; j < QTDVERTICES; j++) {
			
			grafo[i][j] = 0;
			
			if (aleatorio) {
				
				conexao = (rand() % 2);
				
			} else {
				
				printf("Digite <1> se %d se conecta a %d: ", i, j);
				scanf("%d", &conexao);
				
			}
			
			grafo[i][j] = conexao;
			
		}
		
	}
	
}

///////////////////////////////////////////////
// Função recursiva de ordenação topológica //
/////////////////////////////////////////////

void ordenarTopologicoRecursivo(int grafo[QTDVERTICES][QTDVERTICES], 
								int visitado[QTDVERTICES],
								int vertice) {
									
	int i;
	
	visitado[vertice] = 1;
	
	for (i = 0; i < QTDVERTICES; i++) {
		
		if ((grafo[vertice][i]) && (!visitado[i])) {
			
			ordenarTopologicoRecursivo(grafo, visitado, i);
			
		}
				
	}									
																
	printf("%d\t", vertice);
									
}

void ordenarTopologico(int grafo[QTDVERTICES][QTDVERTICES]) {
	
	int vertice;
	int i; 
	int visitado[QTDVERTICES];
	
	for (vertice = 0; vertice < QTDVERTICES; vertice++) {
		
		visitado[vertice] = 0;
		
	}
	
	for (vertice = 0; vertice < QTDVERTICES; vertice++) {
		
		if(!visitado[vertice]) {
			
			ordenarTopologicoRecursivo(grafo, visitado, vertice);
			
		}
		
	}
	
	printf("\n");
	
}

int main () {
	
	int grafo[QTDVERTICES][QTDVERTICES];
	
	time_t t;
	srand((unsigned) time(&t));
	
	criar(grafo, 0);
	
	ordenarTopologico(grafo);
	
	
}
