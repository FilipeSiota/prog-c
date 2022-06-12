/*
5) Faça um programa que leia uma matriz 4 X 5 de inteiros, calcule e imprima a soma
de todos os seus elementos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int ITAM = 4, JTAM = 5;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int matriz[ITAM][JTAM], soma = 0;
	
	// Ler os elementos da matriz
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			printf("Matriz[%d][%d] = ", i, j);
			scanf("%d", &matriz[i][j]);
			
			soma += matriz[i][j];
			
		}
		
		printf("\n");
	}
	
	system("cls");
	
	// Mostrar a matriz
	printf("Matriz:\n\n");
	
	for (int i = 0; i < ITAM; i++) {
		
		for (int j = 0; j < JTAM; j++) {
			
			if (j != JTAM - 1) {
				
				printf("%d \t", matriz[i][j]);
				
			} else {
				
				printf("%d \n", matriz[i][j]);
				
			}
			
		}
	}
	
	printf("\nA soma de todos os elementos da matriz é %d.\n\n", soma);
	
	system("pause");
	return 0;
}
