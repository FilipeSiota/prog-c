/* 8) Fa�a um programa que leia um vetor com tamanho 10 de n�meros inteiros. Ap�s ler, 
uma fun��o deve verificar se o vetor est� ordenado, de forma crescente ou decrescente, 
ou se n�o est� ordenado. Imprimir essa resposta no final do programa. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

// # VARI�VEL GLOBAL
int i;

// # PROT�TIPO DA FUN��O
void vetOrdem(int vetor[], int tamanho);

// # FUN��O PRINCIPAL
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (i = 0; i < TAM; i++)
	{
		printf("Informe o %d� n�mero: ", i + 1);
		scanf("%d", &vet[i]);
	}
	
	printf("\nA sequ�ncia informada est� ");
	
	vetOrdem(vet, TAM);
	
	system("pause");
	return 0;
}

// # DECLARA��O DA FUN��O
void vetOrdem(int vetor[], int tamanho)
{
	int crescente = 0, decrescente = 0;
	
	for (i = 0; i < tamanho - 1; i++)
	{
		if (vetor[i] < vetor[i + 1])
		{
			crescente++;
		}
		else if (vetor[i] > vetor[i + 1])
		{
			decrescente++;
		}
	}
	
	if (crescente == tamanho - 1)
	{
		printf("em ORDEM CRESCENTE.\n\n");
	}
	else if (decrescente == tamanho - 1)
	{
		printf("em ORDEM DECRESCENTE.\n\n");
	}
	else
	{
		printf("DESORDENADA.\n\n");
	}
	
	return;
}
