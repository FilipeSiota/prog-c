/*
1. Fazer um programa que solicita um n�mero decimal e imprime o
correspondente em hexa e octal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n;
	
	printf("Digite um n�mero em decimal: ");
	scanf("%d", &n);
	
	printf("\nDecimal: %d\nOctal: %o\nHexadecimal: %X\n\n", n, n, n);
	
	system("pause");
	return 0;
}
