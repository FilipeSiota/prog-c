/*
3. Fa�a um programa que leia um n�mero inteiro e verifique se esse n�mero � par
ou �mpar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num;
	
	printf("Informe um n�mero: ");
	scanf("%d", &num);
	
	(num % 2) == 0 ? printf("\nO n�mero informado � par.\n\n") : printf("\nO n�mero informado � �mpar.\n\n");
	
	system("pause");
	return 0;
}
