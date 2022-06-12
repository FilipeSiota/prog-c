/* 4) Faça um programa que verifique se um número é primo por meio de uma função. Ao 
final imprima o resultado. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificaNumPrimo(int num);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	
	printf("Qual número você deseja saber se é primo? ");
	scanf("%d", &numero);
	
	verificaNumPrimo(numero);
	
	system("pause");
	return 0;
}

void verificaNumPrimo(int num)
{
	int i, verifica = 1;
	
	for (i = 2; i < num; i++)
	{
		if ( (num % i) == 0 )
		{
			verifica = 0;
			
			break;
		}
	}
	
	if (verifica == 0)
	{
		printf("\nO número %d não é primo.\n\n", num);
		
		return;
	}
	else
	{
		printf("\nO número %d é primo.\n\n", num);
		
		return;
	}
}
