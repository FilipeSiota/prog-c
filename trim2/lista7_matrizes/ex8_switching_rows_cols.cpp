/*
8) Crie um programa que leia e armazene os elementos de uma matriz inteira com
tamanho 5 X 5 e imprimi-la. Troque, a seguir:
• a segunda linha pela quinta;
• a terceira coluna pela quinta;
• a diagonal principal pela diagonal secundária
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 5; // tamanho da matriz
const int LINTROCA1 = 1, LINTROCA2 = 4; // linhas que serão trocadas
const int COLTROCA1 = 2, COLTROCA2 = 4; // colunas que serão trocadas

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mat[TAM][TAM]; // matriz
	
	int auxLin[TAM]; // vetor auxiliar para guardar os valores da primeira linha de troca
	int auxCol[TAM]; // vetor auxiliar para guardar os valores da primeira coluna de troca
	int auxDiag[TAM]; // vetor auxiliar para guardar a diagonal principal
	
	int auxJ; // variáveis auxiliares para pegar a diagonal secundária na matriz
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			printf("Mat[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
		
		printf("\n");
	}
	
	system("cls");
	
	printf("Matriz inicial:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// PARTE 1.1 - pegando a primeira linha de troca e guardando-a no vetor auxiliar
			if (i == LINTROCA1)
			{
				auxLin[j] = mat[i][j];
			}
			
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se não for a última coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabulação após
			}
			else // se for a última coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha após
			}
		}
	}
	
	// PARTE 1.2 - Trocando a segunda linha pela quinta
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// passando os valores da segunda linha de troca para a primeira linha de troca
			if (i == LINTROCA1)
			{
				mat[i][j] = mat[LINTROCA2][j];
			}
			
			// passando os valores da primeira linha de troca (armazenados no vetor auxiliar) para a segunda linha de troca
			if (i == LINTROCA2)
			{
				mat[i][j] = auxLin[j];
			}
		}
	}
	
	printf("\nMatriz após a troca da linha %d pela linha %d:\n", LINTROCA1 + 1, LINTROCA2 + 1);
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// PARTE 2.1 - pegando a primeira coluna de troca e guardando-a no vetor auxiliar
			if (j == COLTROCA1)
			{
				auxCol[i] = mat[i][j];
			}
			
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se não for a última coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabulação após
			}
			else // se for a última coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha após
			}
		}
	}
	
	// PARTE 2.2 - Trocando a terceira coluna pela quinta
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// passando os valores da segunda coluna de troca para a primeira coluna de troca
			if (j == COLTROCA1)
			{
				mat[i][j] = mat[i][COLTROCA2];
			}
			
			// passando os valores da primeira coluna de troca (armazenados no vetor auxiliar) para a segunda coluna de troca
			if (j == COLTROCA2)
			{
				mat[i][j] = auxCol[i];
			}
		}
	}
	
	printf("\nMatriz após a troca da coluna %d pela coluna %d:\n", COLTROCA1 + 1, COLTROCA2 + 1);
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// PARTE 3.1 - pegando a diagonal principal e guardando-a no vetor auxiliar
			if (i == j) // na diagonal principal, as posições da linha e coluna são iguais
			{
				auxDiag[i] = mat[i][j];
			}
			
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se não for a última coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabulação após
			}
			else // se for a última coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha após
			}
		}
	}
	
	// PARTE 3.2 - Trocando a diagonal principal pela diagonal secundária
	auxJ = TAM - 1; // inicializando a variável auxiliar de coluna para o controle da diagonal secundária (motivo explicado adiante)
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			if (i == j)
			{
				// passando os valores da diagonal secundaria para a diagonal principal
				mat[i][j] = mat[i][auxJ];
				
				// passando os valores da diagonal principal (armazenados no vetor auxiliar) para a diagonal secundária
				mat[i][auxJ] = auxDiag[i];
				
				auxJ--; // incrementa uma unidade na variável de coluna para controle da diagonal secundária
				
				/* Na diagonal secundária, a medida que as posições da linhas vão aumentando de 0 até o tamanho da matriz
				(considerando o 0, por isso, até TAM - 1), enquanto as posições das colunas vai diminuindo do tamanho da matriz
				(considerando o 0, por isso, desde TAM - 1) até 0 */
			}
		}
	}
	
	printf("\nMatriz final após a troca da diagonal principal pela diagonal secundária:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se não for a última coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabulação após
			}
			else // se for a última coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha após
			}
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
