/* 3. Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma
pessoa. Faça uso de estruturas aninhadas e definição de novo tipo de dado. 
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba 
os nomes da pessoa mais nova e da mais velha. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUM_PESSOAS 6

typedef struct
{
	int dia;
	int mes;
	int ano;
	
} DataNasc;

typedef struct
{
	char nome[51];
	DataNasc data_nascimento;
	
} Pessoa;

typedef struct
{
	int num_mais_nova;
	int dias_nova;
	int num_mais_velha;
	int dias_velha;
	
} Calculo;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Pessoa pessoas[NUM_PESSOAS];
	Calculo calc;
	int pessoa, calc_dias;
	
	for (pessoa = 0; pessoa < NUM_PESSOAS; pessoa++)
	{
		printf("---------- PESSOA %d ----------\n\n", pessoa + 1);
		printf("Nome completo: ");
		fflush(stdin);
		scanf("%[^\n]", pessoas[pessoa].nome);
		
		printf("Data de nascimento (dd/mm/aaaa): ");
		fflush(stdin);
		scanf("%d/%d/%d", &pessoas[pessoa].data_nascimento.dia, &pessoas[pessoa].data_nascimento.mes, &pessoas[pessoa].data_nascimento.ano);
		
		// Calcula a quantidade de dias da data de nascimento até 01/01/1900 (a menor quantidade é a pessoa mais velha, enquanto a maior é a mais nova)
		calc_dias = (pessoas[pessoa].data_nascimento.ano - 1900) * 365 + pessoas[pessoa].data_nascimento.mes * 30 + pessoas[pessoa].data_nascimento.dia;
		
		if (!pessoa)
		{
			calc.num_mais_nova = pessoa;
			calc.dias_nova = calc_dias;
			
			calc.num_mais_velha = pessoa;
			calc.dias_velha = calc_dias;
		}
		else if (calc_dias > calc.dias_nova)
		{
			calc.num_mais_nova = pessoa;
			calc.dias_nova = calc_dias;
		}
		else if (calc_dias < calc.dias_velha)
		{
			calc.num_mais_velha = pessoa;
			calc.dias_velha = calc_dias;
		}
		
		printf("\n\n");
	}
	
	printf("========== SOBRE AS IDADES =========\n\n");
	
	printf(">> O nome da pessoa mais nova é %s, nasceu em %02d/%02d/%04d\n\n", pessoas[calc.num_mais_nova].nome, pessoas[calc.num_mais_nova].data_nascimento.dia, pessoas[calc.num_mais_nova].data_nascimento.mes, pessoas[calc.num_mais_nova].data_nascimento.ano);

	printf(">> O nome da pessoa mais velha é %s, nasceu em %02d/%02d/%04d\n\n", pessoas[calc.num_mais_velha].nome, pessoas[calc.num_mais_velha].data_nascimento.dia, pessoas[calc.num_mais_velha].data_nascimento.mes, pessoas[calc.num_mais_velha].data_nascimento.ano);	
	
	system("pause");
	return 0;
}
