/*
Faça um programa em C que armazene 15 números inteiros em um vetor NUM e
imprima uma listagem dos números lidos.
*/

#include <stdio.h>
#include <stdlib.h>

const int VALOR = 15;

int main() {
	
	int NUM[VALOR];
	
	for (int i = 0; i < VALOR; i++) {
		
		printf("NUM[%d] = ", i);
		scanf("%d", &NUM[i]);
		
	}
	
	system("cls");
	
	printf("Obtendo os valores:\n\n");
	
	for (int i = 0; i < VALOR; i++) {
		
		printf("NUM[%d] = %d\n", i, NUM[i]);
		
	}
	
	system("pause");
	return 0;
}
