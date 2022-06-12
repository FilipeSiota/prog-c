/*
3. Fa�a um programa que leia um valor inteiro N n�o negativo. Se o valor de N for
inv�lido, o usu�rio dever� digitar outro at� que ele seja v�lido (ou seja,
positivo). Em seguida, leia um vetor V contendo N posi��es de inteiros, em que
cada valor dever� ser maior ou igual a 2. Esse vetor dever� ser alocado
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
			printf("\nValor inv�lido! Tente colocar um n�mero maior que 0.\n");
		}
	}
	while (tamanho <= 0);
	
	// Aloca��o de mem�ria para o vetor
	vet = (int *)(realloc(NULL, tamanho * sizeof(int)));
	
	// Caso de erro na aloca��o de mem�ria
	if (vet == NULL)
	{
		printf("\nErro na aloca��o de mem�ria!\n");
		
		system("pause");
		exit(1);
	}
	
	// L� os valores do vetor
	printf("\n********** LEITURA DO VETOR **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		do
		{
			printf("Informe um valor para a posi��o %d: ", pos + 1);
			scanf("%d", &vet[pos]);
			
			if (vet[pos] < 2)
			{
				printf("\nValor inv�lido! Tente colocar um n�mero maior ou igual a 2.\n");
			}
		}
		while (vet[pos] < 2);
	}
	
	// Mostra o vetor
	printf("\n********** MOSTRANDO O VETOR **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("Vetor na %d� posi��o: %d\n", pos + 1, vet[pos]);
	}
	
	printf("\n");
	
	// Desocupa o bloco de mem�ria que estava sendo usado pelo vetor
	free(vet);
	
	system("pause");
	return 0;
}
