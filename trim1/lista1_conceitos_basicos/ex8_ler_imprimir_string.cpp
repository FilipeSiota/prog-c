/*
8. Faça um programa que leia uma string e a imprima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char str[50];
	
	printf("Digite algo: ");
	gets(str);
	
	printf("\nO texto digitado foi:\n'%s'\n\n", str);
	
	system("pause");
	return 0;
}
