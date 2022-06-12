/*
2) Crie um programa que armazene dados inteiros em uma matriz de ordem 5 e
imprima: Todos os elementos que se encontram em posições cuja linha mais
coluna formam um número par.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {
	
	int mat[TAM][TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			printf("matriz[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
			
		}
		
		printf("\n");
	}
	
	system("cls");
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if ( (i + j) % 2 == 0 ) {
				
				printf("matriz[%d][%d] = %d\n", i, j, mat[i][j]);
				
			}
			
		}
		
		printf("\n");
	}
	
	system("pause");
	return 0;
}
