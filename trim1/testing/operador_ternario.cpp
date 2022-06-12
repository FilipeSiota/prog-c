/*
Faça um programa que leia um número e:
	- Se o número for maior ou igual a 0, incrementa número.
	- Se o número for menor que 0, decrementa o número.
*/

#include <stdio.h>
#include <conio.h>

int main() {
	int num;
	
	printf("Informe um numero: ");
	scanf("%d", &num);
	
	(num >= 0) ? num++ : num--;
	
	printf("\nNum apos a operacao ternaria: %d\n\n", num);
	
	getch();
	
	return 0;
}
