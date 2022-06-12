/*
2) Construa um programa em C que armazene 15 n�meros em um vetor e imprima
uma listagem numerada contendo o n�mero e uma das mensagens: par ou �mpar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 15; // trocar o tamanho do vetor de forma mais pr�tica

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe o %d� n�mero: ", i + 1);
		scanf("%d", &vet[i]);
		
	}
	
	for (int i = 0; i < TAM; i++) {
		
		printf("\n%d�) %d --> ", i + 1, vet[i]);
		
		if (vet[i] % 2 == 0) {
			
			printf("par");
			
		} else {
			
			printf("�mpar");
			
		}
		
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}
