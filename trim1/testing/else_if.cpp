/* Exercício
Faça um programa que leia um número.
	- Diga (mostre na tela) se ele é positivo, negativo ou zero. */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	
	printf("Informe um numero: ");
	scanf("%d", &num);
	
	if (!num) {
		
		puts("\nO numero e zero.\n");
		
	} else if (num > 0) {
		
		puts("\nO numero e positivo.\n");
		
	} else {
		
		puts("\nO numero e negativo.\n");
		
	}
	
	system("pause");
	
	return 0;
}
