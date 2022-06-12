/*
3. Faça um programa que leia um número inteiro e verifique se esse número é par
ou ímpar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num;
	
	printf("Informe um número: ");
	scanf("%d", &num);
	
	(num % 2) == 0 ? printf("\nO número informado é par.\n\n") : printf("\nO número informado é ímpar.\n\n");
	
	system("pause");
	return 0;
}
