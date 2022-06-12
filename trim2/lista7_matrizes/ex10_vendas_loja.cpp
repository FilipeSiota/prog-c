/*
10) Construa um programa que carregue uma matriz 12 X 4 com os valores das vendas
de uma loja, em cada linha represente um mês do ano, e cada coluna, uma semana
do mês. Calcule e imprima:
• total vendido em cada mês do ano;
• total vendido em cada semana durante todo o ano;
• total vendido no ano
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int MESES = 12; // linhas
const int SEMANAS = 4; // colunas

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float vendas[MESES][SEMANAS];
	float somaMes, somaSemana, somaTotal = 0;
	
	printf("VENDAS DA LOJA\n");
	
	printf("\n==============================\n");
	
	// ENTRADA DE VALORES NA MATRIZ
	for (int i = 0; i < MESES; i++)
	{
		printf("\nMÊS %d\n\n", i + 1);
		
		for (int j = 0; j < SEMANAS; j++)
		{
			printf("Vendas na semana %d: R$ ", j + 1);
			scanf("%f", &vendas[i][j]);
		}
		
		printf("\n==============================\n");
	}
	
	// Total vendido em cada mês do ano
	for (int i = 0; i < MESES; i++)
	{
		somaMes = 0;
		
		for (int j = 0; j < SEMANAS; j++)
		{
			somaMes += vendas[i][j];
		}
		
		somaTotal += somaMes; // pegando o total de vendas do ano
		
		printf("\nTotal de vendas no MÊS %d: R$ %.2f", i + 1, somaMes);
	}
	
	printf("\n");
	
	// Total vendido em cada semana durante todo o ano
	for (int j = 0; j < SEMANAS; j++)
	{
		somaSemana = 0;
		
		for (int i = 0; i < MESES; i++)
		{
			somaSemana += vendas[i][j];
		}
		
		printf("\nTotal de vendas na SEMANA %d: R$ %.2f", j + 1, somaSemana);
	}
	
	// Total vendido no ano
	printf("\n\nTotal de vendas no ano: R$ %.2f\n\n", somaTotal);
	
	system("pause");
	return 0;
}
