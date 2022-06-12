/*
2) Construa um programa em C que armazene 15 números em um vetor e imprima
uma listagem numerada contendo o número e uma das mensagens: par ou ímpar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 15; // trocar o tamanho do vetor de forma mais prática

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe o %d° número: ", i + 1);
		scanf("%d", &vet[i]);
		
	}
	
	for (int i = 0; i < TAM; i++) {
		
		printf("\n%d°) %d --> ", i + 1, vet[i]);
		
		if (vet[i] % 2 == 0) {
			
			printf("par");
			
		} else {
			
			printf("ímpar");
			
		}
		
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}
