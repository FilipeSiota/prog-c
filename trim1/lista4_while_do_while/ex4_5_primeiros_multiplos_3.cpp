/*
4. Fa�a um programa que determine e mostre os cinco primeiros m�ltiplos de 3
considerando n�meros maiores que 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mult, contador = 1;
	
	puts("Os 5 primeiros n�meros m�ltiplos de 3, maiores que 0, s�o:");
	
	while (contador <= 5) {
		
		mult = 3 * contador;
		
		printf("%d\n", mult);
		
		contador++;
	}
	
	system("pause");
	return 0;
}
