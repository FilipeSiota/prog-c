/*
1) Faça um programa em C que leia os elementos de uma matriz do tipo inteiro com
tamanho 10 X 10. Ao final, imprima todos os elementos.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {
	
	int m[TAM][TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			printf("matriz[%d][%d] = ", i, j);
			scanf("%d", &m[i][j]);
			
		}
		
		printf("\n");
	}
	
	system("cls");
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if (j != TAM - 1) {
				
				printf("%2d \t", m[i][j]);	
				
			} else {
				
				printf("%2d \n", m[i][j]);
				
			}
			
		}
	}
	
	system("pause");
	return 0;
}
