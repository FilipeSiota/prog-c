/*
2. Fa�a um programa que leia dois n�meros e mostre o maior deles. Se, por
acaso, os dois n�meros forem iguais, imprima a mensagem �N�meros iguais�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2;
	
	printf("Informe o 1� n�mero: ");
	scanf("%d", &n1);
	
	printf("Informe o 2� n�mero: ");
	scanf("%d", &n2);
	
	if (n1 > n2) {
		
		printf("\nO maior n�mero informado foi %d.\n\n", n1);
		
	} else if (n1 == n2) {
		
		printf("\nN�meros iguais.\n\n");
		
	} else {
		
		printf("\nO maior n�mero informado foi %d.\n\n", n2);
		
	}
	
	system("pause");
	return 0;
}
