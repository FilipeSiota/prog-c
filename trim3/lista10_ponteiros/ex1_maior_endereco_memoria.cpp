/*
1. Escreva um programa que contenha duas variáveis inteiras. Compare seus
endereços e exiba o maior endereço.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int var1, var2, *p1, *p2;
	
	p1 = &var1;
	p2 = &var2;
	
	printf("Entre %p e %p, qual é o maior endereço de memória?\n\n", p1, p2);
	
	if (p1 > p2)
	{
		printf("O maior endereço de memória é %p.\n\n", p1);
	}
	else
	{
		printf("O maior endereço de memória é %p.\n\n", p2);
	}
	
	system("pause");
	return 0;
}
