/*
2. Elabore um programa que leia do usu�rio o tamanho de um vetor a ser lido. Em
seguida, fa�a a aloca��o din�mica desse vetor. Por fim, leia o vetor do usu�rio e
o imprima.
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
	vet = (int *)(calloc(tamanho, sizeof(int)));
	
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
		printf("Informe um valor para a posi��o %d: ", pos + 1);
		scanf("%d", &vet[pos]);
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
