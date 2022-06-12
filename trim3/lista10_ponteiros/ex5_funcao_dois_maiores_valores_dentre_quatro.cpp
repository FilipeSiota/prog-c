/*
Construa uma fun��o que, recebendo como par�metros quatro n�meros inteiros,
devolva ao m�dulo que o chamou os dois maiores n�meros dentre os quatro recebidos.
Fa�a um programa que leia tantos conjuntos de quatro valores quantos o usu�rio deseje
e que acione a fun��o para cada conjunto de valores, apresentando a cada vez os dois
maiores n�meros. Se preferir, utilize vetor para armazenar o conjunto de valores.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void maiorValor(int *conjunto, int tamanho, int *maior1, int *maior2);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int quantConjuntos, conjunto[4], maior1, maior2;
	int conj, num;
	
	printf("Digite a quantidade de conjuntos que voc� deseja informar durante o programa: ");
	scanf("%d", &quantConjuntos);
	
	for (conj = 0; conj < quantConjuntos; conj++)
	{
		printf("\nConjunto %d:\n\n", conj + 1);
		
		for (num = 0; num < 4; num++)
		{
			printf("Informe o %d� valor: ", num + 1);
			scanf("%d", &conjunto[num]);
		}
		
		maiorValor(conjunto, 4, &maior1, &maior2);
		
		printf("\nOs dois maiores valores dentre os informados para este conjunto foram, respectivamente, %d e %d.\n", maior1, maior2);
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}

void maiorValor(int *conjunto, int tamanho, int *maior1, int *maior2)
{
	int i, num, aux;
	
	// Implementa o algoritmo Bubble Sort para deixar os dois maiores valores nas duas primeiras posi��es do vetor
	
	for (i = 0; i < tamanho - 1; i++)
	{
		for (num = 0; num < tamanho - i; num++)
		{
			if (num != tamanho - i - 1)
			{
				if (conjunto[num] < conjunto[num + 1])
				{
					aux = conjunto[num];
					conjunto[num] = conjunto[num + 1];
					conjunto[num + 1] = aux;
				}
			}
		}
	}
	
	*maior1 = conjunto[0];
	*maior2 = conjunto[1];
	
	return;
}
