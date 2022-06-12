/*
8) Crie um programa que leia e armazene os elementos de uma matriz inteira com
tamanho 5 X 5 e imprimi-la. Troque, a seguir:
� a segunda linha pela quinta;
� a terceira coluna pela quinta;
� a diagonal principal pela diagonal secund�ria
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 5; // tamanho da matriz
const int LINTROCA1 = 1, LINTROCA2 = 4; // linhas que ser�o trocadas
const int COLTROCA1 = 2, COLTROCA2 = 4; // colunas que ser�o trocadas

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mat[TAM][TAM]; // matriz
	
	int auxLin[TAM]; // vetor auxiliar para guardar os valores da primeira linha de troca
	int auxCol[TAM]; // vetor auxiliar para guardar os valores da primeira coluna de troca
	int auxDiag[TAM]; // vetor auxiliar para guardar a diagonal principal
	
	int auxJ; // vari�veis auxiliares para pegar a diagonal secund�ria na matriz
	
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
			if (j != TAM - 1) // se n�o for a �ltima coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabula��o ap�s
			}
			else // se for a �ltima coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha ap�s
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
	
	printf("\nMatriz ap�s a troca da linha %d pela linha %d:\n", LINTROCA1 + 1, LINTROCA2 + 1);
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
			if (j != TAM - 1) // se n�o for a �ltima coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabula��o ap�s
			}
			else // se for a �ltima coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha ap�s
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
	
	printf("\nMatriz ap�s a troca da coluna %d pela coluna %d:\n", COLTROCA1 + 1, COLTROCA2 + 1);
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// PARTE 3.1 - pegando a diagonal principal e guardando-a no vetor auxiliar
			if (i == j) // na diagonal principal, as posi��es da linha e coluna s�o iguais
			{
				auxDiag[i] = mat[i][j];
			}
			
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se n�o for a �ltima coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabula��o ap�s
			}
			else // se for a �ltima coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha ap�s
			}
		}
	}
	
	// PARTE 3.2 - Trocando a diagonal principal pela diagonal secund�ria
	auxJ = TAM - 1; // inicializando a vari�vel auxiliar de coluna para o controle da diagonal secund�ria (motivo explicado adiante)
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			if (i == j)
			{
				// passando os valores da diagonal secundaria para a diagonal principal
				mat[i][j] = mat[i][auxJ];
				
				// passando os valores da diagonal principal (armazenados no vetor auxiliar) para a diagonal secund�ria
				mat[i][auxJ] = auxDiag[i];
				
				auxJ--; // incrementa uma unidade na vari�vel de coluna para controle da diagonal secund�ria
				
				/* Na diagonal secund�ria, a medida que as posi��es da linhas v�o aumentando de 0 at� o tamanho da matriz
				(considerando o 0, por isso, at� TAM - 1), enquanto as posi��es das colunas vai diminuindo do tamanho da matriz
				(considerando o 0, por isso, desde TAM - 1) at� 0 */
			}
		}
	}
	
	printf("\nMatriz final ap�s a troca da diagonal principal pela diagonal secund�ria:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			// IMPRIMINDO OS VALORES NA TELA
			if (j != TAM - 1) // se n�o for a �ltima coluna
			{
				printf("%2d \t", mat[i][j]); // imprime o valor com uma tabula��o ap�s
			}
			else // se for a �ltima coluna
			{
				printf("%2d \n", mat[i][j]); // imprime o valor com uma quebra de linha ap�s
			}
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
