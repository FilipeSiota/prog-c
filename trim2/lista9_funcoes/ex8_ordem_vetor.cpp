/* 8) Faça um programa que leia um vetor com tamanho 10 de números inteiros. Após ler, 
uma função deve verificar se o vetor está ordenado, de forma crescente ou decrescente, 
ou se não está ordenado. Imprimir essa resposta no final do programa. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

// # VARIÁVEL GLOBAL
int i;

// # PROTÓTIPO DA FUNÇÃO
void vetOrdem(int vetor[], int tamanho);

// # FUNÇÃO PRINCIPAL
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	
	for (i = 0; i < TAM; i++)
	{
		printf("Informe o %dº número: ", i + 1);
		scanf("%d", &vet[i]);
	}
	
	printf("\nA sequência informada está ");
	
	vetOrdem(vet, TAM);
	
	system("pause");
	return 0;
}

// # DECLARAÇÃO DA FUNÇÃO
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
