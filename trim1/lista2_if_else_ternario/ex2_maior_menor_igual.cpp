/*
2. Faça um programa que leia dois números e mostre o maior deles. Se, por
acaso, os dois números forem iguais, imprima a mensagem “Números iguais”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2;
	
	printf("Informe o 1° número: ");
	scanf("%d", &n1);
	
	printf("Informe o 2° número: ");
	scanf("%d", &n2);
	
	if (n1 > n2) {
		
		printf("\nO maior número informado foi %d.\n\n", n1);
		
	} else if (n1 == n2) {
		
		printf("\nNúmeros iguais.\n\n");
		
	} else {
		
		printf("\nO maior número informado foi %d.\n\n", n2);
		
	}
	
	system("pause");
	return 0;
}
