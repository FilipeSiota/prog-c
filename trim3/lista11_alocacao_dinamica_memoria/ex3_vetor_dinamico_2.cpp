/*
3. Faça um programa que leia um valor inteiro N não negativo. Se o valor de N for
inválido, o usuário deverá digitar outro até que ele seja válido (ou seja,
positivo). Em seguida, leia um vetor V contendo N posições de inteiros, em que
cada valor deverá ser maior ou igual a 2. Esse vetor deverá ser alocado
dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int *vet, tamanho;
	int pos;
	
	do
	{
		printf("Informe o tamanho do vetor: ");
		scanf("%d", &tamanho);
		
		if (tamanho <= 0)
		{
			printf("\nValor inválido! Tente colocar um número maior que 0.\n");
		}
	}
	while (tamanho <= 0);
	
	// Alocação de memória para o vetor
	vet = (int *)(realloc(NULL, tamanho * sizeof(int)));
	
	// Caso de erro na alocação de memória
	if (vet == NULL)
	{
		printf("\nErro na alocação de memória!\n");
		
		system("pause");
		exit(1);
	}
	
	// Lê os valores do vetor
	printf("\n********** LEITURA DO VETOR **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		do
		{
			printf("Informe um valor para a posição %d: ", pos + 1);
			scanf("%d", &vet[pos]);
			
			if (vet[pos] < 2)
			{
				printf("\nValor inválido! Tente colocar um número maior ou igual a 2.\n");
			}
		}
		while (vet[pos] < 2);
	}
	
	// Mostra o vetor
	printf("\n********** MOSTRANDO O VETOR **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("Vetor na %dª posição: %d\n", pos + 1, vet[pos]);
	}
	
	printf("\n");
	
	// Desocupa o bloco de memória que estava sendo usado pelo vetor
	free(vet);
	
	system("pause");
	return 0;
}
