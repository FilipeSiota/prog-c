/*
9. Crie um programa que calcula o comprimento de uma string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char str[50];
	int length;
	
	printf("Digite algo: ");
	gets(str);
	
	length = strlen(str);
	
	printf("\nO tamanho da string informada é %d.\n\n", length);
	
	system("pause");
	return 0;
}
