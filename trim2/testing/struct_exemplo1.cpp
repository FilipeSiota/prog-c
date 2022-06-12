#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct departamento {
	int cod;
	char descricao[30];
} Departamento;

typedef struct cargo {
	int cod;
	char descricao[30];
} Cargo;

typedef struct funcionario {
	int cod;
	char nome[30];
	float salario;
	Departamento depto;
	Cargo cargo;
} Funcionario;
*/

struct funcionario {
	int cod;
	char nome[30];
	float salario;
	int depto;
	int cargo;
};

typedef struct funcionario Funcionario; // define o tipo de dado Funcionario a partir da estrutura de dados criada (funcionario)

int main()
{
	// struct funcionario func1, func2;
	Funcionario func1, func2;
	
	//atribuindo dados a func1
	func1.cod = 1;
	strcpy(func1.nome, "Joao");
	func1.salario = 1200;
	
	//imprimindo os dados de func1
	printf("Codigo: %d \n", func1.cod);
	printf("Nome: %s \n", func1.nome);
	printf("Salario: %.2f \n", func1.salario);
	
	//atribuindo valores a func2 com o uso do scanf
	printf("\nInforme o codigo: ");
	scanf("%d", &func2.cod);
	
	printf("Informe o nome: ");
	scanf("%s", &func2.nome);
	
	printf("Informe o salario: ");
	scanf("%f", &func2.salario);
	
	//imprimindo os dados de func2
	printf("\nCodigo: %d \n", func2.cod);
	printf("Nome: %s \n", func2.nome);
	printf("Salario: %.2f \n", func2.salario);
}

