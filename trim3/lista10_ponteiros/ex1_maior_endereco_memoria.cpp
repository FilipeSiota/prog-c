/*
1. Escreva um programa que contenha duas vari�veis inteiras. Compare seus
endere�os e exiba o maior endere�o.
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
	
	printf("Entre %p e %p, qual � o maior endere�o de mem�ria?\n\n", p1, p2);
	
	if (p1 > p2)
	{
		printf("O maior endere�o de mem�ria � %p.\n\n", p1);
	}
	else
	{
		printf("O maior endere�o de mem�ria � %p.\n\n", p2);
	}
	
	system("pause");
	return 0;
}
