/* 1) Fa�a um programa em C que leia tr�s n�meros e, para cada um, imprimir o dobro. O 
c�lculo dever� ser realizado por uma fun��o e o resultado impresso ao final do 
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
		printf("Informe o %d� n�mero: ", numero + 1);
		scanf("%f", &numeros[numero]);
	}
	
	for (numero = 0; numero < QUANT; numero++)
	{
		printf("\nO dobro de %.2f � %.2f", numeros[numero], dobro(numeros[numero]) );
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
