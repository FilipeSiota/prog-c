/* 4) Fa�a um programa que verifique se um n�mero � primo por meio de uma fun��o. Ao 
final imprima o resultado. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificaNumPrimo(int num);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	
	printf("Qual n�mero voc� deseja saber se � primo? ");
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
		printf("\nO n�mero %d n�o � primo.\n\n", num);
		
		return;
	}
	else
	{
		printf("\nO n�mero %d � primo.\n\n", num);
		
		return;
	}
}
