/* 5. Um clube social com 37 associados deseja que você faça um programa para
armazenar os dados cadastrais desses associados. Os dados são: nome, dia, 
mês e ano de nascimento, valor da mensalidade e quantidade de dependentes. 
O programa deverá ler os dados e imprimir depois na tela. Deverá também 
informar o associado (ou os associados) com o maior número de dependentes. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUM_ASSOC 37

typedef struct
{
	int dia;
	int mes;
	int ano;
	
} DataNasc;

typedef struct
{
	char nome[51];
	DataNasc data_nasc;
	float mensalidade;
	int quant_dependentes;
	
} Cadastro;

typedef struct
{
	int num_assoc[NUM_ASSOC];
	int max_dependentes;
	int quant;
	
} Dependentes;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Cadastro associados[NUM_ASSOC];
	Dependentes dependentes;
	int associado;
	
	dependentes.quant = 0;
	
	for (associado = 0; associado < NUM_ASSOC; associado++)
	{
		printf("========== ASSOCIADO %d ==========\n\n", associado + 1);
		
		printf("Nome completo: ");
		fflush(stdin);
		scanf("%50[^\n]", associados[associado].nome);
		
		printf("Data de nascimento (dd/mm/aaaa): ");
		fflush(stdin);
		scanf("%d/%d/%d", &associados[associado].data_nasc.dia, &associados[associado].data_nasc.mes, &associados[associado].data_nasc.ano);
		
		printf("Valor da mensalidade: R$ ");
		fflush(stdin);
		scanf("%f", &associados[associado].mensalidade);
		
		printf("Quantidade de dependentes: ");
		fflush(stdin);
		scanf("%d", &associados[associado].quant_dependentes);
		
		if (!associado)
		{
			dependentes.num_assoc[dependentes.quant] = associado;
			dependentes.max_dependentes = associados[associado].quant_dependentes;
			dependentes.quant++;
		}
		else
		{
			if (associados[associado].quant_dependentes > dependentes.max_dependentes)
			{
				dependentes.quant = 0;
				
				dependentes.num_assoc[dependentes.quant] = associado;
				dependentes.max_dependentes = associados[associado].quant_dependentes;
				dependentes.quant++;
			}
			else if (associados[associado].quant_dependentes == dependentes.max_dependentes)
			{
				dependentes.num_assoc[dependentes.quant] = associado;
				dependentes.quant++;
			}
		}
		
		printf("\n\n");
	}
	
	system("cls");
	
	for (associado = 0; associado < NUM_ASSOC; associado++)
	{
		printf("========== ASSOCIADO %d ==========\n\n", associado + 1);
		
		printf("Nome completo: %s\n", associados[associado].nome);
		
		printf("Data de nascimento: %02d/%02d/%04d\n", associados[associado].data_nasc.dia, associados[associado].data_nasc.mes, associados[associado].data_nasc.ano);
		
		printf("Valor da mensalidade: R$ %.2f\n", associados[associado].mensalidade);
		
		printf("Quantidade de dependentes: %d\n\n\n", associados[associado].quant_dependentes);
	}
	
	printf("========== ASSOCIADO(S) COM MAIS DEPENDENTES ==========\n\n");
	
	printf("Nome(s):\n");
	
	for (associado = 0; associado < dependentes.quant; associado++)
	{
		printf("\t%s\n", associados[dependentes.num_assoc[associado]].nome);
	}
	
	printf("\nNúmero de dependentes: %d\n\n", dependentes.max_dependentes);
	
	system("pause");
	return 0;
}
