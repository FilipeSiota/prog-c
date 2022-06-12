/*
3. Fa�a um programa que leia um n�mero inteiro N e depois imprima os N
primeiros n�meros naturais �mpares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador = 0, impar = 1;
	
	do {
		
		printf("Informe um n�mero inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! N�mero inv�lido");
			
		}
	} while (n <= 0);
	
	printf("\nOs %d primeiros n�meros naturais �mpares s�o:\n", n);
	
	while (contador < n) {
		
		printf("%d\n", impar);
		
		impar += 2;
		contador++;
	}
	
	system("pause");
	return 0;
}
