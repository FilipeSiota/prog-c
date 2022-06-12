/*
1. Fa�a um programa que leia um n�mero inteiro positivo N e imprima todos os
n�meros naturais de 0 at� N em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador = 0;
	
	do {
		
		printf("Informe um n�mero inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! N�mero inv�lido.");
			
		}
	} while (n <= 0);
	
	printf("\nA seguir, ser� apresentada a sequ�ncia crescente dos n�meros de 0 a %d:\n", n);
	
	while (contador <= n) {
		
		printf("%d\n", contador++);
		
	}
	
	system("pause");
	return 0;
}
