/* 1) Faça um programa em C que leia três números e, para cada um, imprimir o dobro. O 
cálculo deverá ser realizado por uma função e o resultado impresso ao final do 
programa. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define QUANT 3

float dobro(float num);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float numeros[QUANT];
	int numero;
	
	for (numero = 0; numero < QUANT; numero++)
	{
		printf("Informe o %dº número: ", numero + 1);
		scanf("%f", &numeros[numero]);
	}
	
	for (numero = 0; numero < QUANT; numero++)
	{
		printf("\nO dobro de %.2f é %.2f", numeros[numero], dobro(numeros[numero]) );
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}

float dobro(float num)
{
	float result;
	
	result = num * 2;
	
	return result;
}
