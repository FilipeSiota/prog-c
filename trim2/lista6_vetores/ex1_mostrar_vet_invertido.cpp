/*
1) Receba um vetor de 6 posições com números inteiros e mostre esse vetor ao
contrário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 6; // consigo trocar o tamanho do vetor de forma mais prática

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe um valor inteiro para vet[%d]: ", i);
		scanf("%d", &vet[i]);
		
	}
	
	printf("\nO vetor invertido:\n\n");
	
	for (int i = TAM - 1; i >= 0; i--) {
		
		printf("vet[%d] = %d\n", i, vet[i]);
		
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}
