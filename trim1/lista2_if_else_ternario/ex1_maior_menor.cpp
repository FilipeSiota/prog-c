// 1. Fa�a um programa que leia dois n�meros e mostre qual deles � o maior

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2;
	
	printf("Informe um n�mero: ");
	scanf("%d", &n1);
	
	do {
		
		printf("Informe outro n�mero diferente do anterior: ");
		scanf("%d", &n2);
		
		if (n2 == n1) {
			puts("\nO n�meros devem ser diferentes!");
		}
		
	} while (n2 == n1);
	
	(n1 > n2) ? printf("\nO maior n�mero informado foi %d.\n\n", n1) : printf("\nO maior n�mero informado foi %d.\n\n", n2);
	
	system("pause");
	return 0;
}
