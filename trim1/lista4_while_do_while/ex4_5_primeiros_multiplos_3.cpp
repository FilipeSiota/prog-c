/*
4. Faça um programa que determine e mostre os cinco primeiros múltiplos de 3
considerando números maiores que 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mult, contador = 1;
	
	puts("Os 5 primeiros números múltiplos de 3, maiores que 0, são:");
	
	while (contador <= 5) {
		
		mult = 3 * contador;
		
		printf("%d\n", mult);
		
		contador++;
	}
	
	system("pause");
	return 0;
}
