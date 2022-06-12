/*
1. Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador = 0;
	
	do {
		
		printf("Informe um número inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! Número inválido.");
			
		}
	} while (n <= 0);
	
	printf("\nA seguir, será apresentada a sequência crescente dos números de 0 a %d:\n", n);
	
	while (contador <= n) {
		
		printf("%d\n", contador++);
		
	}
	
	system("pause");
	return 0;
}
