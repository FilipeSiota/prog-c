/*
3. Elabore um programa que leia um valor do tipo inteiro e, por meio de função,
atualize todas as posições de um vetor com o número inteiro lido, depois
imprima os valores. Utilize ponteiros para as operações.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void atualizaVetor(int *vetor, int tamanho, int num);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int valor, vet[5];
	
	printf("Informe um valor inteiro: ");
	scanf("%d", &valor);
	
	atualizaVetor(vet, 5, valor);
	
	/*
	printf("\nVetor atualizado:\n\n");
	
	for (int i = 0; i < 5; i++)
	{
		printf("Vetor[%d] = %d\n", i, vet[i]);
	}
	*/
	
	printf("\n");
	
	system("pause");
	return 0;
}

void atualizaVetor(int *vetor, int tamanho, int num)
{
	int i;
	
	for (i = 0; i < tamanho; i++)
	{
		vetor[i] = num;
	}
	
	printf("\nVetor atualizado:\n\n");
	
	for (i = 0; i < tamanho; i++)
	{
		printf("Vetor[%d] = %d\n", i, *(vetor + i));
		// ou printf("Vetor[%d] = %d\n", i, vetor[i]);
	}
	
	return;
}
