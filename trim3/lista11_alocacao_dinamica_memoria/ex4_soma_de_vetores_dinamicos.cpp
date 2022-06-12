/*
4. Escreva uma função que receba como parâmetro dois vetores, A e B, de
tamanho N cada. A função deve retornar o ponteiro para um vetor C de
tamanho N alocado dinamicamente, em que C[i] = A[i] + B[i].
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// PROTÓTIPO DA FUNÇÃO
int *somaVetores(int *vetA, int *vetB, int tam);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int *vetA, *vetB, *vetC, tamanho;
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
	
	// Alocação de memória para os vetores A e B
	vetA = (int *)(malloc(tamanho * sizeof(int)));
	vetB = (int *)(malloc(tamanho * sizeof(int)));
	
	if (vetA == NULL || vetB == NULL)
	{
		printf("\nErro na alocação de memória!\n");
		
		system("pause");
		exit(1);
	}
	
	printf("\n********** LENDO VETOR A **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("Informe um valor para a %dª posição do vetor A: ", pos + 1);
		scanf("%d", &vetA[pos]);
	}
	
	printf("\n********** LENDO VETOR B **********\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("Informe um valor para a %dª posição do vetor B: ", pos + 1);
		scanf("%d", &vetB[pos]);
	}
	
	// Chama a função para realizar a soma dos vetores
	vetC = somaVetores(vetA, vetB, tamanho);
	
	system("cls");
	
	printf("Vetores A e B:\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("%2d", vetA[pos]);
		
		printf("    ");
		
		printf("%2d\n", vetB[pos]);
	}
	
	printf("\nVetor SOMA:\n\n");
	
	for (pos = 0; pos < tamanho; pos++)
	{
		printf("%2d\n", vetC[pos]);
	}
	
	printf("\n");
	
	// Desocupa os blocos de memória que estavam sendo usados pelos vetores
	free(vetA);
	free(vetB);
	free(vetC);
	
	system("pause");
	return 0;
}

int *somaVetores(int *vetA, int *vetB, int tam)
{
	int *vetSoma;
	int pos;
	
	// Alocação de memória para o vetor de soma
	vetSoma = (int *)(malloc(tam * sizeof(int)));
	
	if (vetSoma == NULL)
	{
		printf("\nErro na alocação de memória!\n");
		
		system("pause");
		exit(1);
	}
	
	// Soma os valores das respectivas posições e armazena na mesma posição do vetor soma
	for (pos = 0; pos < tam; pos++)
	{
		vetSoma[pos] = vetA[pos] + vetB[pos];
	}
	
	return vetSoma;
}
