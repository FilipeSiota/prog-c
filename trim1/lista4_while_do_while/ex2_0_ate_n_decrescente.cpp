/*
2. Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador;
	
	do {
		
		printf("Informe um número inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! Número inválido.");
			
		}
	} while (n <= 0);
	
	contador = n;
	
	printf("\nA seguir, será apresentada a sequência decrescente dos números de %d a 0:\n", n);
	
	while (contador >= 0) {
		
		printf("%d\n", contador--);
		
	}
	
	system("pause");
	return 0;
}
