/*
10. Faça um programa que leia um nome e imprima as 4 primeiras letras de um nome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[50], firstFour[4];
	
	printf("Digite seu nome: ");
	gets(nome);
	
	strncpy(firstFour, nome, 4);
	
	printf("\nAs 4 primeiras letras do seu nome são: '%s'\n\n", firstFour);
	
	system("pause");
	return 0;
}
