/*
Fa�a um programa que leia um n�mero e:
	- Se o n�mero for maior ou igual a 0, incrementa n�mero.
	- Se o n�mero for menor que 0, decrementa o n�mero.
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
