/*
Uma posição de uma matriz é referenciada por linha e coluna, faça um programa que leia uma matriz 4×4.
O programa deve perguntar o valor de cada posição da matriz, em seguida imprima esta matriz na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int main() {
	int matriz[TAM][TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			printf("matriz[%d][%d] = ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	system("cls");
	
	for (int i = 0; i < TAM; i++) {
		
		for (int j = 0; j < TAM; j++) {
			
			if (j != TAM - 1) {
			
				printf("%2d \t", matriz[i][j]);
			
			} else {
				
				printf("%2d \n", matriz[i][j]);
				
			}
			
		}
	}
	
	system("pause");
	return 0;
}
