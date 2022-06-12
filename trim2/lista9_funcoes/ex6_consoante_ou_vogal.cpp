/* 6) Construa um programa em C que leia um caractere (letra) e, por meio de uma função, 
retorne se este caractere é uma consoante ou uma vogal. Ao final imprima o resultado. */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void verificaLetra(char letra);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char alfabeto[52] = {
							'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
							'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
						};
	char letra;
	int letraAlfabeto;
	int verificaCharEspecial;
	
	do
	{
		verificaCharEspecial = 1;
		
		printf("Informe uma letra: ");
		letra = getche();
		
		for (letraAlfabeto = 0; letraAlfabeto < 52; letraAlfabeto++)
		{
			if (letra == alfabeto[letraAlfabeto])
			{
				verificaCharEspecial = 0;
				
				break;
			}
		}
		
		if (verificaCharEspecial)
		{
			printf("\n\nUps! Você informou um caractere especial. Tente uma letra.\n");
		}
		
	} while (verificaCharEspecial);
	
	if (!verificaCharEspecial)
	{
		verificaLetra(letra);
	}
	
	system("pause");
	return 0;
}

void verificaLetra(char letra)
{
	char vogais[10] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u' };
	int vogal, verificaConsoante = 1;
	
	for (vogal = 0; vogal < 10; vogal++)
	{
		if (letra == vogais[vogal])
		{
			verificaConsoante = 0;
			
			break;
		}
	}
	
	if (verificaConsoante == 0)
	{
		printf("\n\nA letra '%c' é uma vogal.\n\n", letra);
		
		return;
	}
	else
	{
		printf("\n\nA letra '%c' é uma consoante.\n\n", letra);
		
		return;
	}
}
