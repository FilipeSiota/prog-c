/*
3) Faça um programa que permita entrar com valores em uma matriz A de tamanho
3 X 4. Gerar e imprimir uma matriz B que é o triplo da matriz A.
*/

#include <stdio.h>
#include <stdlib.h>

#define ITAM 3
#define JTAM 4

int main() {
	
	int A[ITAM][JTAM], B[ITAM][JTAM];
	
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			printf("Matriz A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
			
			B[i][j] = A[i][j] * 3;
			
		}
		
		printf("\n");
		
	}
	
	system("cls");
	
	// IMPRIME MATRIZ A
	printf("Matriz A:\n\n");
	
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			if (j != JTAM - 1) {
				
				printf("%2d \t", A[i][j]);
				
			} else {
				
				printf("%2d \n", A[i][j]);
				
			}
			
		}
		
	}
	
	// IMPRIME MATRIZ B
	printf("\nMatriz B = 3 * A\n\n");
	
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			if (j != JTAM - 1) {
				
				printf("%2d \t", B[i][j]);
				
			} else {
				
				printf("%2d \n", B[i][j]);
				
			}
			
		}
		
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
