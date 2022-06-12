/*
5. Escreva um programa que aloque dinamicamente uma matriz de inteiros. As
dimensões da matriz deverão ser lidas do usuário. Em seguida, escreva uma
função que receba um valor e retorne 1, caso o valor esteja na matriz, ou
retorne 0, no caso contrário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int verificaMatriz(int valor, int **matriz, int rows, int cols);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int **matriz, rows, cols;
	int row, col;
	int valor, response;
	
	do
	{
		printf("Informe o número de linhas da matriz: ");
		scanf("%d", &rows);
		printf("Informe o número de colunas da matriz: ");
		scanf("%d", &cols);
		
		if (rows <= 0 || cols <= 0)
		{
			printf("\nUps! Matriz inválida. Tente colocar um número maior que 0 em ambos os campos.\n");
		}
	}
	while (rows <= 0 || cols <= 0);
	
	// Alocação de memória para a matriz
	matriz = (int **)(malloc(rows * sizeof(int *)));
	
	if (matriz == NULL)
	{
		printf("\nErro na alocação de memória!\n");
		
		system("pause");
		exit(1);
	}
	
	for (row = 0; row < rows; row++)
	{
		matriz[row] = (int *)(malloc(cols * sizeof(int)));
		
		if (matriz[row] == NULL)
		{
			printf("\nErro na alocação de memória!\n");
			
			system("pause");
			exit(1);
		}
	}
	
	// Lendo valores para a matriz
	printf("\n********** LENDO A MATRIZ **********\n\n");
	
	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			printf("Matriz[%d][%d] = ", row, col);
			scanf("%d", &matriz[row][col]);
		}
	}
	
	system("cls");
	
	// Recebe um valor para vericar se está contido na matriz
	printf("Informe um valor e verificaremos se ele consta na matriz: ");
	scanf("%d", &valor);
	
	response = verificaMatriz(valor, matriz, rows, cols);
	
	if (!response)
	{
		printf("\nO valor %d não consta na matriz!\n\n", valor);
	}
	else
	{
		printf("\nO valor %d consta na matriz!\n\n", valor);
	}
	
	printf("****** MATRIZ ******\n");
	
	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			printf("%2d ", matriz[row][col]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	// Desocupa o bloco de memória que estava sendo usado pela matriz
	for (row = 0; row < rows; row++)
	{
		free(matriz[row]);
	}
	
	free(matriz);
	
	system("pause");
	return 0;
}

int verificaMatriz(int valor, int **matriz, int rows, int cols)
{
	int row, col;
	
	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			if (matriz[row][col] == valor)
			{
				return 1;
			}
		}
	}
	
	return 0;
}
