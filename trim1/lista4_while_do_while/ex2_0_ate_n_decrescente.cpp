/*
2. Fa�a um programa que leia um n�mero inteiro positivo N e imprima todos os
n�meros naturais de 0 at� N em ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador;
	
	do {
		
		printf("Informe um n�mero inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! N�mero inv�lido.");
			
		}
	} while (n <= 0);
	
	contador = n;
	
	printf("\nA seguir, ser� apresentada a sequ�ncia decrescente dos n�meros de %d a 0:\n", n);
	
	while (contador >= 0) {
		
		printf("%d\n", contador--);
		
	}
	
	system("pause");
	return 0;
}
