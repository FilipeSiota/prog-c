/*
3) Faça um programa que leia um conjunto de 30 valores inteiros, armazene-os em
um vetor e os imprima ao contrário da ordem de leitura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 30;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		printf("vet[%d] = ", i);
		scanf("%d", &vet[i]);
		
	}
	
	printf("\nO vetor invertido:\n");
	
	for (int i = TAM - 1; i >= 0; i--) {
		
		printf("\nvet[%d] = %d", i, vet[i]);
		
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}
