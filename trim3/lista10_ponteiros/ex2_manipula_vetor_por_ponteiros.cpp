/*
2. Crie um programa que contenha um vetor de inteiros com tamanho 5.
Utilizando apenas ponteiros, leia valores e armazene neste vetor e após isso,
imprima o dobro de cada valor lido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUM 5

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int vet[NUM], *ponteiro, i;
	
	ponteiro = vet;
	
	for (i = 0; i < NUM; i++)
	{
		printf("Vetor[%d]: ", i);
		scanf("%d", ponteiro + i);
		// ou scanf("%d", &ponteiro[i]);

	}
	
	printf("\n============================================\n\n");
	
	for (i = 0; i < NUM; i++)
	{
		ponteiro[i] *= 2;
		
		printf("Vetor[%d] = %d\n", i, *(ponteiro + i));
		// ou printf("Vetor[%d] = %d\n", i, ponteiro[i]);
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
