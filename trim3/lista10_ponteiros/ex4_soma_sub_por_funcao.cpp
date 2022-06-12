/*
4. Faça um programa que receba dois valores inteiros, após receber esses dois
valores, uma função deve calcular e retornar para o programa o resultado da
soma e da subtração dos valores. Obs.: Apenas uma função deve realizar esta
operação, desta forma, faça uso de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcula(int n1, int n2, int *soma, int *sub);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int num1, num2, soma, subtracao;
	
	printf("Informe um número inteiro: ");
	scanf("%d", &num1);
	
	printf("Informe outro número inteiro: ");
	scanf("%d", &num2);
	
	calcula(num1, num2, &soma, &subtracao);
	
	printf("\n\t%d + %d = %d\n", num1, num2, soma);
	
	printf("\t%d - %d = %d\n\n", num1, num2, subtracao);
	
	system("pause");
	return 0;
}

void calcula(int n1, int n2, int *soma, int *sub)
{
	*soma = n1 + n2;
	*sub = n1 - n2;
	
	return;
}
