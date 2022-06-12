/* 1. Implemente um programa em C que leia o nome, a idade e o endereço de uma
pessoa e armazene esses dados em uma estrutura. Em seguida, imprima na tela
os dados da estrutura lida. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
	char rua[51];
	int numero;
	char cidade[51];
	char estado[51];
	int cep;
	
} Endereco;

typedef struct
{
	char nome[51];
	int idade;
	Endereco endereco;
	
} Pessoa;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Pessoa pessoa;
	
	printf("========== ARMAZENA OS DADOS PESSOAIS ==========\n\n");
	
	printf("Nome completo....: ");
	fflush(stdin);
	scanf("%50[^\n]", pessoa.nome);
	
	printf("Idade............: ");
	fflush(stdin);
	scanf("%d", &pessoa.idade);
	
	printf("\n---------- Endereço ----------\n\n");
	
	printf("\tRua....................: ");
	fflush(stdin);
	scanf("%50[^\n]", pessoa.endereco.rua);
	
	printf("\tNúmero.................: ");
	fflush(stdin);
	scanf("%d", &pessoa.endereco.numero);
	
	printf("\tCidade.................: ");
	fflush(stdin);
	scanf("%50[^\n]", pessoa.endereco.cidade);
	
	printf("\tEstado.................: ");
	fflush(stdin);
	scanf("%50[^\n]", pessoa.endereco.estado);
	
	printf("\tCEP (apenas números)...: ");
	fflush(stdin);
	scanf("%d", &pessoa.endereco.cep);
	
	printf("\n\n========== MOSTRA OS DADOS PESSOAIS ==========\n");
	
	printf("\nNome completo....: %s", pessoa.nome);
	printf("\nIdade............: %d", pessoa.idade);
	
	printf("\n\n---------- Endereço ----------\n");
	
	printf("\n\tRua.........: %s", pessoa.endereco.rua);
	printf("\n\tNúmero......: %d", pessoa.endereco.numero);
	printf("\n\tCidade......: %s", pessoa.endereco.cidade);
	printf("\n\tEstado......: %s", pessoa.endereco.estado);
	printf("\n\tCEP.........: %d\n\n", pessoa.endereco.cep);
	
	system("pause");
	return 0;
}
