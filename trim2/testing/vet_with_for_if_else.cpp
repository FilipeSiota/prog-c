/*
Faça um programa em C que leia 5 valores inteiros e armazene em um vetor. Após a
leitura o programa deve encontrar e imprimir o maior valor armazenado no vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int vet[5], maior;
	
	for (int i = 0; i < 5; i++) {
		
		printf("vet[%d] = ", i);
		scanf("%d", &vet[i]);
		
		if (!i) {
			
			maior = vet[i];
			
		} else if (vet[i] > maior) {
			
			maior = vet[i];
			
		}
		
	}
	
	printf("\nO maior numero que consta dentro do vetor e %d\n\n", maior);
	
	system("pause");
	return 0;
}
