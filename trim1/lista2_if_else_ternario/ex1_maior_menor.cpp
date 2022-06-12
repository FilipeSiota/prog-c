// 1. Faça um programa que leia dois números e mostre qual deles é o maior

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2;
	
	printf("Informe um número: ");
	scanf("%d", &n1);
	
	do {
		
		printf("Informe outro número diferente do anterior: ");
		scanf("%d", &n2);
		
		if (n2 == n1) {
			puts("\nO números devem ser diferentes!");
		}
		
	} while (n2 == n1);
	
	(n1 > n2) ? printf("\nO maior número informado foi %d.\n\n", n1) : printf("\nO maior número informado foi %d.\n\n", n2);
	
	system("pause");
	return 0;
}
