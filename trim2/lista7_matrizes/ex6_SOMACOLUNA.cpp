/*
6) Construa um programa em C que leia valores inteiros para a matriz A (3 x 5). Gerar e
imprimir a matriz SOMACOLUNA, em que cada elemento é a soma dos elementos
de uma coluna da matriz A. Faça o trecho que gera a matriz separado da entrada e
da saída.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int ITAM = 3, JTAM = 5;

int main() {
	int A[ITAM][JTAM], SOMACOLUNA[ITAM] = { };
	
	// Leitura dos elementos da matriz A
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			printf("Matriz A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
			
		}
		
		printf("\n");
	}
	
	system("cls");
	
	// Gerando os resultados para o vetor SOMACOLUNA
	for (int j = 0; j < JTAM; j++) {
		
		for (int i = 0; i < ITAM; i++) {
			
			SOMACOLUNA[j] += A[i][j];
			
		}
	}
	
	// Mostrando a matriz A
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			if (j != JTAM - 1) {
				
				printf("%2d \t", A[i][j]);
				
			} else {
				
				printf("%2d \n", A[i][j]);
				
			}
			
		}
	}
	
	// Mostrando o vetor SOMACOLUNA
	printf("\nSoma das colunas da matriz A:\n\n");
	
	for (int j = 0; j < JTAM; j++) {
		
		if (j != JTAM - 1) {
			
			printf("%2d \t", SOMACOLUNA[j]);
			
		} else {
			
			printf("%2d \n", SOMACOLUNA[j]);
			
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
