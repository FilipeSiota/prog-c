/*
3. Faça um programa que leia um número inteiro N e depois imprima os N
primeiros números naturais ímpares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n, contador = 0, impar = 1;
	
	do {
		
		printf("Informe um número inteiro positivo: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			
			puts("\nUps! Número inválido");
			
		}
	} while (n <= 0);
	
	printf("\nOs %d primeiros números naturais ímpares são:\n", n);
	
	while (contador < n) {
		
		printf("%d\n", impar);
		
		impar += 2;
		contador++;
	}
	
	system("pause");
	return 0;
}
