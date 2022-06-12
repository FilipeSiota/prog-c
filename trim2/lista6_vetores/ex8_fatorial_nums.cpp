/*
8) Faça um programa que leia um vetor de 10 elementos e gere um vetor cujos
componentes são os fatoriais dos respectivos componentes de vet.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 10;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	unsigned long int fatorial[TAM] = { };
	
	printf("########## Fatorial de um número ##########\n\n");
	
	printf("*Informe apenas números inteiros positivos!!\n\n");
	
	for (int i = 0; i < TAM; i++) {
		
		do {
			
			printf("Informe o %d° número: ", i + 1);
			scanf("%d", &vet[i]);
			fflush(stdin);
			
			if (vet[i] <= 0) {
				
				printf("\nUps! Valor inválido. Tente digitar um número inteiro maior que 0.\n");
				
			}
			
		} while (vet[i] <= 0);
		
		for (int num = vet[i]; num >= 1; num--) { // já faz fatorial do número informado
			
			if (num == vet[i]) { // se for a primeira repetição, o valor inicial de fatorial[i] vai ser o próprio valor informado pelo usuário
				
				fatorial[i] = num;
				
			} else {
				
				fatorial[i] *= num;
				
			}
			
		}
		
	}
	
	printf("\n########## Resultados ##########\n");
	
	printf("\nNúmero\tFatorial\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("%4d\t%d\n", vet[i], fatorial[i]);
		
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
