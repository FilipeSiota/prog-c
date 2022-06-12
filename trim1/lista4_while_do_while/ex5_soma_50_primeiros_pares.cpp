/*
5. Faça um programa que calcule e mostre a soma dos 50 primeiros números
pares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int soma = 0, par = 0, contador = 0;
	
	while (contador < 50) {
		
		soma += par;
		par += 2;
		
		contador++;
		
	}
	
	printf("A soma dos 50 primeiros números pares (incluindo o 0) é: %d.\n\n", soma);
	
	system("pause");
	return 0;
}
