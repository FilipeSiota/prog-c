/* 3) Faça um programa que calcule e imprima o fatorial de um número, usando uma
função que receba um valor e retorne o fatorial desse valor. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calculaFatorial(int num);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int valor;
	unsigned long int fatorial;
	
	printf("Você deseja saber o fatorial de qual número? ");
	scanf("%d", &valor);
	
	fatorial = calculaFatorial(valor);
	
	printf("\n%d! = %d\n\n", valor, fatorial);
	
	system("pause");
	return 0;
}

int calculaFatorial(int num)
{
	unsigned long int result = 1;
	int i;
	
	for (i = 2; i <= num; i++)
	{
		result *= i;
	}
	
	return result;
}
