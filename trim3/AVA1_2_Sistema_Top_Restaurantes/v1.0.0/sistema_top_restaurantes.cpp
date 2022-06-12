/*
	SISTEMA TOP RESTAURANTES

	Crie um sistema para armazenar a classificação dos restaurantes de uma região.

	O sistema deve armazenar:
	
	• Nome do restaurante
	• Bairro
	• Cidade
	• Tipo de comida (brasileira, chinesa, francesa, italiana, japonesa, etc)
	• Nota para a cozinha (entre 0 e 5)
	
	O programa deve ter as seguintes opções:
	
	a) Inserir um novo restaurante na lista;
	b) Listar todos os restaurantes na tela;
	c) Excluir um restaurante da lista;
	d) Liste os restaurantes com cozinha com nota superior a um determinado valor,
	determinado pelo usuário;
	e) Liste todos os restaurantes com determinado tipo de comida, determinado pelo
	usuário.
	
	TRABALHO
	
	• O trabalho pode ser desenvolvido individualmente, em duplas ou trios.
	• Caso façam em dupla ou trio, enviar apenas um arquivo por dupla e informar no envio
	os nomes de todos os componentes.
	• Enviar arquivo fonte.
	• Use sua lógica e tudo que você sabe para encontrar a melhor solução para este
	problema.
	
	=======================================================================================
	NOME: Filipe Mallmann Siota
	TURMA: DS2
	=======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_RESTAURANTE 1000

// =========================================================================================

// ESTRUTURA DE DADOS PARA ARMAZENAR A AVALIAÇÃO DE CADA RESTAURANTE

struct avaliacao
{
	int codigo;
	char nome[MAX];
	char bairro[MAX];
	char cidade[MAX];
	char tipoComida[MAX];
	float nota;
};

typedef struct avaliacao Avaliacao;

// =========================================================================================

// PROTÓTIPOS DE FUNÇÕES

void mostraCabecalho(int numRestaurantes);
void mostraOpcoes(int *opcao);
void maiuscula(char *string, int tam);
void adicionaRestaurante(Avaliacao *dados, int *tam, int *cod);
void listaRestaurantes(Avaliacao *restaurantes, int tam);
void excluiRestaurante(Avaliacao *restaurantes, int *tam, int codExclusao);
void filtroNota(Avaliacao *restaurantes, int tam, float nota);
void filtroTipoComida(Avaliacao *restaurantes, int tam, char *tipoComida);

// =========================================================================================

// FUNÇÃO PRINCIPAL

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// VARIÁVEIS PARA O CASO 1 - ADICIONAR RESTAURANTE A LISTA
	Avaliacao restaurante[MAX_RESTAURANTE];
	int quantRest = 0;
	int cod = 0;
	
	// VARIÁVEIS PARA O CASO 3 - EXCLUIR RESTAURANTE DA LISTA
	int codExclusao;
	int confirmaExclusao;
	
	// VARIÁVEIS PARA O CASO 4 - LISTAR COM FILTRO DE NOTA
	float minNota;
	
	// VARIÁVEIS PARA O CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
	char tipoComida[MAX];
	
	// VARIÁVEIS AUXILIARES
	int opcao;
	
	// =====================================================================
	
	mostraCabecalho(quantRest);
		
	printf("Seja bem-vind@ ao nosso sistema!\n\n");
	
	mostraOpcoes(&opcao);
	
	while (opcao != 6)
	{
		switch (opcao)
		{
			case 1:
				system("cls");
				
				mostraCabecalho(quantRest);
				
				printf("1. Inserir um novo restaurante na lista\n\n");
				
				printf("=========================================================\n\n");
				
				if (quantRest < MAX_RESTAURANTE)
				{
					adicionaRestaurante(restaurante, &quantRest, &cod);
				}
				else
				{
					printf("O limite de %d cadastrados de restaurantes foi atingido!\n\n", MAX_RESTAURANTE);
				}
				
				system("pause");
				
				system("cls");
				
				break;
				
			case 2:
				system("cls");
				
				mostraCabecalho(quantRest);
				
				printf("2. Listar todos os restaurantes\n\n");
				
				printf("=========================================================\n\n");
				
				if (quantRest > 0)
				{
					listaRestaurantes(restaurante, quantRest);
				}
				else
				{
					printf("Não há restaurantes cadastrados ainda!\n\n");
				}
				
				system("pause");
				
				system("cls");
				
				break;
				
			case 3:
				system("cls");
				
				mostraCabecalho(quantRest);
				
				printf("3. Excluir um restaurante da lista\n\n");
				
				printf("=========================================================\n\n");
				
				if (quantRest > 0)
				{
				
					printf("Para excluir um restaurante da lista, você precisa ter o código de cadastro.\nCaso você não saiba o código, siga as seguintes instruções:\n\n");
					
					printf("\t1º Digite no campo abaixo o valor 0;\n");
					printf("\t2º No menu de opções, escolha a opção (2) para listar todos os restaurantes;\n");
					printf("\t3º Verifique o código do respectivo restaurante;\n");
					printf("\t4º Copie o código e volte ao menu de opções;\n");
					printf("\t5º Escolha a opção (3) para excluir um restaurante da lista;\n");
					printf("\t6º Cole o código no campo abaixo.\n\n");
					
					printf("Informe o código do restaurante que desejas excluir ou 0 para retornar ao menu de opções: ");
					fflush(stdin);
					scanf("%d", &codExclusao);
					
					if (codExclusao > 0)
					{
						confirmaExclusao = 0;
						
						for (int i = 0; i < quantRest; i++)
						{
							if (restaurante[i].codigo == codExclusao)
							{
								printf("\nRestaurante encontrado...\n\n");
								printf("Código: %d\n", restaurante[i].codigo);
								printf("Nome do restaurante: %s", restaurante[i].nome);
								printf("Bairro: %s", restaurante[i].bairro);
								printf("Cidade: %s", restaurante[i].cidade);
								printf("Tipo de comida: %s", restaurante[i].tipoComida);
								printf("Nota para a cozinha: %.1f\n", restaurante[i].nota);
								printf("\n=========================================================\n\n");
								
								do
								{
									printf("Você deseja realmente excluir este restaurante da lista?\n\nDigite (1) SIM ou (2) NÃO: ");
									scanf("%d", &confirmaExclusao);
									
									if (confirmaExclusao < 1 || confirmaExclusao > 2)
									{
										printf("\nOpção inválida! Tente novamente.\n");
									}
								}
								while (confirmaExclusao < 1 || confirmaExclusao > 2);
								
								if (confirmaExclusao == 1)
								{
									excluiRestaurante(restaurante, &quantRest, codExclusao);
								}
								else
								{
									printf("\nOperação cancelada!\n\n");
								}
							}
							else if (i == quantRest - 1 && !confirmaExclusao)
							{
								printf("Nenhum restaurante com este código foi encontrado!\n\n");
							}
						}
						
						system("pause");
					}
				}
				else
				{
					printf("Não há restaurantes cadastrados ainda!\n\n");
					
					system("pause");
				}
					
				system("cls");
				
				break;
				
			case 4:
				system("cls");
				
				mostraCabecalho(quantRest);
				
				printf("4. Listar restaurantes com filtro de nota\n\n");
				
				if (quantRest > 0)
				{
					printf("Listar restaurantes cuja nota para a cozinha é superior a: ");
					fflush(stdin);
					scanf("%f", &minNota);
					
					printf("\n=========================================================\n\n");
					
					filtroNota(restaurante, quantRest, minNota);
				}
				else
				{
					printf("=========================================================\n\n");
					
					printf("Não há restaurantes cadastrados ainda!\n\n");
				}
				
				system("pause");
				
				system("cls");
				
				break;
				
			case 5:
				system("cls");
				
				mostraCabecalho(quantRest);
				
				printf("5. Listar restaurantes com filtro de tipo de comida\n\n");
				
				if (quantRest > 0)
				{
					printf("Listar restaurantes cujo tipo de comida é: ");
					fflush(stdin);
					fgets(tipoComida, MAX, stdin);
					
					printf("\n=========================================================\n\n");
					
					maiuscula(tipoComida, strlen(tipoComida));
					
					filtroTipoComida(restaurante, quantRest, tipoComida);
				}
				else
				{
					printf("=========================================================\n\n");
					
					printf("Não há restaurantes cadastrados ainda!\n\n");
				}
				
				system("pause");
				
				system("cls");
				
				break;
		}
		
		mostraCabecalho(quantRest);
		
		mostraOpcoes(&opcao);
	}
	
	system("cls");
	
	printf("################# SISTEMA TOP RESTAURANTES #################\n");
	
	printf("\nAgradecemos a sua preferência pelo SISTEMA TOP RESTAURANTES!\n");
	printf("\tDesenvolvido por: Filipe Mallmann Siota - DS2\n\n");
	
	system("pause");
	return 0;
}

// =========================================================================================

// FUNÇÃO QUE MOSTRA O CABEÇALHO
void mostraCabecalho(int numRestaurantes)
{
	printf("################# SISTEMA TOP RESTAURANTES #################\n\n");
	
	printf("Número de restaurantes cadastrados: %d/%d\n\n", numRestaurantes, MAX_RESTAURANTE);
	
	return;
}

// FUNÇÃO QUE MOSTRA AS OPÇÕES
void mostraOpcoes(int *opcao)
{
	printf("1. Inserir um novo restaurante na lista\n");
	printf("2. Listar todos os restaurantes\n");
	printf("3. Excluir um restaurante da lista\n");
	printf("4. Listar restaurantes com filtro de nota\n");
	printf("5. Listar restaurantes com filtro de tipo de comida\n");
	printf("6. Sair\n\n");
	
	do
	{
		printf("Informe uma das opções acima: ");
		fflush(stdin);
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 6)
		{
			printf("\nOpção inválida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 6);
	
	return;
}

// FUNÇÃO QUE TRANSFORMA UMA STRING EM MAIÚSCULA
void maiuscula(char *string, int tam)
{
	for (int letra = 0; letra < tam; letra++)
	{
		string[letra] = toupper(string[letra]);
	}
	
	return;
}

// FUNÇÃO CASO 1 - ADICIONAR UM RESTAURANTE A LISTA
void adicionaRestaurante(Avaliacao *dados, int *tam, int *cod)
{
	printf("Complete os campos com as informações referentes ao restaurante:\n\n");
				
	printf("Nome (máx. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].nome, MAX, stdin);
	
	printf("Bairro (máx. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].bairro, MAX, stdin);
	
	printf("Cidade (máx. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].cidade, MAX, stdin);
	
	printf("Tipo de comida (máx. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].tipoComida, MAX, stdin);
	
	maiuscula(dados[*tam].tipoComida, strlen(dados[*tam].tipoComida));
	
	do
	{
		printf("Nota para a cozinha de 0 (péssima) a 5 (ótima): ");
		fflush(stdin);
		scanf("%f", &dados[*tam].nota);
		
		if (dados[*tam].nota < 0 || dados[*tam].nota > 5)
		{
			printf("\nValor inválido! Tente colocar um número de 0 a 5.\n");
		}
	}
	while (dados[*tam].nota < 0 || dados[*tam].nota > 5);
	
	*cod = *cod + 1;
	
	dados[*tam].codigo = *cod;
	
	*tam = *tam + 1;
	
	printf("\nRestaurante adicionado a lista com sucesso!\n\n");
	
	return;
}

// FUNÇÃO CASO 2 - LISTAR TODOS OS RESTAURANTES
void listaRestaurantes(Avaliacao *restaurantes, int tam)
{
	for (int rest = 0; rest < tam; rest++)
	{
		printf("Código: %d\n", restaurantes[rest].codigo);
		printf("Nome do restaurante: %s", restaurantes[rest].nome);
		printf("Bairro: %s", restaurantes[rest].bairro);
		printf("Cidade: %s", restaurantes[rest].cidade);
		printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
		printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
		printf("\n=========================================================\n\n");
	}
	
	return;
}

// FUNÇÃO CASO 3 - EXCLUIR UM RESTAURANTE DA LISTA
void excluiRestaurante(Avaliacao *restaurantes, int *tam, int codExclusao)
{
	char nomeRest[MAX];
	
	for (int rest = 0; rest < *tam; rest++)
	{
		if (restaurantes[rest].codigo == codExclusao)
		{
			strcpy(nomeRest, restaurantes[rest].nome);
			
			restaurantes[*tam].codigo = restaurantes[rest].codigo;
			strcpy(restaurantes[*tam].nome, restaurantes[rest].nome);
			strcpy(restaurantes[*tam].bairro, restaurantes[rest].bairro);
			strcpy(restaurantes[*tam].cidade, restaurantes[rest].cidade);
			strcpy(restaurantes[*tam].tipoComida, restaurantes[rest].tipoComida);
			restaurantes[*tam].nota = restaurantes[rest].nota;
			
			for (int org = rest + 1; org < *tam; org++)
			{
				restaurantes[org - 1].codigo = restaurantes[org].codigo;
				strcpy(restaurantes[org - 1].nome, restaurantes[org].nome);
				strcpy(restaurantes[org - 1].bairro, restaurantes[org].bairro);
				strcpy(restaurantes[org - 1].cidade, restaurantes[org].cidade);
				strcpy(restaurantes[org - 1].tipoComida, restaurantes[org].tipoComida);
				restaurantes[org - 1].nota = restaurantes[org].nota;
			}
			
			*tam = *tam - 1;
			
			printf("\n\tRestaurante: %s\tCódigo: %d\n\tFoi excluído com sucesso!\n\n", nomeRest, codExclusao);
		}
	}
	
	return;
}

// FUNÇÃO CASO 4 - LISTAR COM FILTRO DE NOTA
void filtroNota(Avaliacao *restaurantes, int tam, float nota)
{
	int encontrado = 0;
	
	for (int rest = 0; rest < tam; rest++)
	{
		if (restaurantes[rest].nota > nota)
		{
			printf("Código: %d\n", restaurantes[rest].codigo);
			printf("Nome do restaurante: %s", restaurantes[rest].nome);
			printf("Bairro: %s", restaurantes[rest].bairro);
			printf("Cidade: %s", restaurantes[rest].cidade);
			printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
			printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
			printf("\n=========================================================\n\n");
			
			encontrado = 1;
		}
		else if (rest == tam - 1 && !encontrado)
		{
			printf("Nenhum restaurante foi encontrado!\n\n");
		}
	}
	
	return;
}

// FUNÇÃO CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
void filtroTipoComida(Avaliacao *restaurantes, int tam, char *tipoComida)
{
	int encontrado = 0;
	
	for (int rest = 0; rest < tam; rest++)
	{
		if (!strcmp(restaurantes[rest].tipoComida, tipoComida))
		{
			printf("Código: %d\n", restaurantes[rest].codigo);
			printf("Nome do restaurante: %s", restaurantes[rest].nome);
			printf("Bairro: %s", restaurantes[rest].bairro);
			printf("Cidade: %s", restaurantes[rest].cidade);
			printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
			printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
			printf("\n=========================================================\n\n");
			
			encontrado = 1;
		}
		else if (rest == tam - 1 && !encontrado)
		{
			printf("Nenhum restaurante foi encontrado!\n\n");
		}
	}
	
	return;
}
