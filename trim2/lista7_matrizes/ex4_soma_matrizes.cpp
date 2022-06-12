/*
4) Crie um programa que leia valores inteiros em uma matriz A[2][2] e em uma matriz
B[2][2]. Gerar e imprimir a matriz SOMA[2][2].
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main() {
	
	int A[TAM][TAM], B[TAM][TAM], SOMA[TAM][TAM];
	
	// Leitura da Matriz A
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			printf("Matriz A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
			
			SOMA[i][j] = A[i][j];
			
		}
		
		printf("\n");
	}
	
	// Leitura da Matriz B
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			printf("Matriz B[%d][%d] = ", i, j);
			scanf("%d", &B[i][j]);
			
			SOMA[i][j] += B[i][j];
			
		}
		
		printf("\n");
	}
	
	system("cls");
	
	// Imprimir Matriz A
	printf("Matriz A\n\n");
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if (j != TAM - 1) {
				
				printf("%2d \t", A[i][j]);
				
			} else {
				
				printf("%2d \n", A[i][j]);
				
			}
			
		}
	}
	
	// Imprimir Matriz B
	printf("\nMatriz B\n\n");
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if (j != TAM - 1) {
				
				printf("%2d \t", B[i][j]);
				
			} else {
				
				printf("%2d \n", B[i][j]);
				
			}
			
		}
	}
	
	// Imprimir Matriz SOMA
	printf("\n============================\n\nMatriz SOMA = A + B\n\n");
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if (j != TAM - 1) {
				
				printf("%2d \t", SOMA[i][j]);
				
			} else {
				
				printf("%2d \n", SOMA[i][j]);
				
			}
			
		}
		
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
