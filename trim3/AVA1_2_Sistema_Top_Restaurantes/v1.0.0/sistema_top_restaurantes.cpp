/*
	SISTEMA TOP RESTAURANTES

	Crie um sistema para armazenar a classifica��o dos restaurantes de uma regi�o.

	O sistema deve armazenar:
	
	� Nome do restaurante
	� Bairro
	� Cidade
	� Tipo de comida (brasileira, chinesa, francesa, italiana, japonesa, etc)
	� Nota para a cozinha (entre 0 e 5)
	
	O programa deve ter as seguintes op��es:
	
	a) Inserir um novo restaurante na lista;
	b) Listar todos os restaurantes na tela;
	c) Excluir um restaurante da lista;
	d) Liste os restaurantes com cozinha com nota superior a um determinado valor,
	determinado pelo usu�rio;
	e) Liste todos os restaurantes com determinado tipo de comida, determinado pelo
	usu�rio.
	
	TRABALHO
	
	� O trabalho pode ser desenvolvido individualmente, em duplas ou trios.
	� Caso fa�am em dupla ou trio, enviar apenas um arquivo por dupla e informar no envio
	os nomes de todos os componentes.
	� Enviar arquivo fonte.
	� Use sua l�gica e tudo que voc� sabe para encontrar a melhor solu��o para este
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

// ESTRUTURA DE DADOS PARA ARMAZENAR A AVALIA��O DE CADA RESTAURANTE

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

// PROT�TIPOS DE FUN��ES

void mostraCabecalho(int numRestaurantes);
void mostraOpcoes(int *opcao);
void maiuscula(char *string, int tam);
void adicionaRestaurante(Avaliacao *dados, int *tam, int *cod);
void listaRestaurantes(Avaliacao *restaurantes, int tam);
void excluiRestaurante(Avaliacao *restaurantes, int *tam, int codExclusao);
void filtroNota(Avaliacao *restaurantes, int tam, float nota);
void filtroTipoComida(Avaliacao *restaurantes, int tam, char *tipoComida);

// =========================================================================================

// FUN��O PRINCIPAL

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// VARI�VEIS PARA O CASO 1 - ADICIONAR RESTAURANTE A LISTA
	Avaliacao restaurante[MAX_RESTAURANTE];
	int quantRest = 0;
	int cod = 0;
	
	// VARI�VEIS PARA O CASO 3 - EXCLUIR RESTAURANTE DA LISTA
	int codExclusao;
	int confirmaExclusao;
	
	// VARI�VEIS PARA O CASO 4 - LISTAR COM FILTRO DE NOTA
	float minNota;
	
	// VARI�VEIS PARA O CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
	char tipoComida[MAX];
	
	// VARI�VEIS AUXILIARES
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
					printf("N�o h� restaurantes cadastrados ainda!\n\n");
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
				
					printf("Para excluir um restaurante da lista, voc� precisa ter o c�digo de cadastro.\nCaso voc� n�o saiba o c�digo, siga as seguintes instru��es:\n\n");
					
					printf("\t1� Digite no campo abaixo o valor 0;\n");
					printf("\t2� No menu de op��es, escolha a op��o (2) para listar todos os restaurantes;\n");
					printf("\t3� Verifique o c�digo do respectivo restaurante;\n");
					printf("\t4� Copie o c�digo e volte ao menu de op��es;\n");
					printf("\t5� Escolha a op��o (3) para excluir um restaurante da lista;\n");
					printf("\t6� Cole o c�digo no campo abaixo.\n\n");
					
					printf("Informe o c�digo do restaurante que desejas excluir ou 0 para retornar ao menu de op��es: ");
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
								printf("C�digo: %d\n", restaurante[i].codigo);
								printf("Nome do restaurante: %s", restaurante[i].nome);
								printf("Bairro: %s", restaurante[i].bairro);
								printf("Cidade: %s", restaurante[i].cidade);
								printf("Tipo de comida: %s", restaurante[i].tipoComida);
								printf("Nota para a cozinha: %.1f\n", restaurante[i].nota);
								printf("\n=========================================================\n\n");
								
								do
								{
									printf("Voc� deseja realmente excluir este restaurante da lista?\n\nDigite (1) SIM ou (2) N�O: ");
									scanf("%d", &confirmaExclusao);
									
									if (confirmaExclusao < 1 || confirmaExclusao > 2)
									{
										printf("\nOp��o inv�lida! Tente novamente.\n");
									}
								}
								while (confirmaExclusao < 1 || confirmaExclusao > 2);
								
								if (confirmaExclusao == 1)
								{
									excluiRestaurante(restaurante, &quantRest, codExclusao);
								}
								else
								{
									printf("\nOpera��o cancelada!\n\n");
								}
							}
							else if (i == quantRest - 1 && !confirmaExclusao)
							{
								printf("Nenhum restaurante com este c�digo foi encontrado!\n\n");
							}
						}
						
						system("pause");
					}
				}
				else
				{
					printf("N�o h� restaurantes cadastrados ainda!\n\n");
					
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
					printf("Listar restaurantes cuja nota para a cozinha � superior a: ");
					fflush(stdin);
					scanf("%f", &minNota);
					
					printf("\n=========================================================\n\n");
					
					filtroNota(restaurante, quantRest, minNota);
				}
				else
				{
					printf("=========================================================\n\n");
					
					printf("N�o h� restaurantes cadastrados ainda!\n\n");
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
					printf("Listar restaurantes cujo tipo de comida �: ");
					fflush(stdin);
					fgets(tipoComida, MAX, stdin);
					
					printf("\n=========================================================\n\n");
					
					maiuscula(tipoComida, strlen(tipoComida));
					
					filtroTipoComida(restaurante, quantRest, tipoComida);
				}
				else
				{
					printf("=========================================================\n\n");
					
					printf("N�o h� restaurantes cadastrados ainda!\n\n");
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
	
	printf("\nAgradecemos a sua prefer�ncia pelo SISTEMA TOP RESTAURANTES!\n");
	printf("\tDesenvolvido por: Filipe Mallmann Siota - DS2\n\n");
	
	system("pause");
	return 0;
}

// =========================================================================================

// FUN��O QUE MOSTRA O CABE�ALHO
void mostraCabecalho(int numRestaurantes)
{
	printf("################# SISTEMA TOP RESTAURANTES #################\n\n");
	
	printf("N�mero de restaurantes cadastrados: %d/%d\n\n", numRestaurantes, MAX_RESTAURANTE);
	
	return;
}

// FUN��O QUE MOSTRA AS OP��ES
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
		printf("Informe uma das op��es acima: ");
		fflush(stdin);
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 6)
		{
			printf("\nOp��o inv�lida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 6);
	
	return;
}

// FUN��O QUE TRANSFORMA UMA STRING EM MAI�SCULA
void maiuscula(char *string, int tam)
{
	for (int letra = 0; letra < tam; letra++)
	{
		string[letra] = toupper(string[letra]);
	}
	
	return;
}

// FUN��O CASO 1 - ADICIONAR UM RESTAURANTE A LISTA
void adicionaRestaurante(Avaliacao *dados, int *tam, int *cod)
{
	printf("Complete os campos com as informa��es referentes ao restaurante:\n\n");
				
	printf("Nome (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].nome, MAX, stdin);
	
	printf("Bairro (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].bairro, MAX, stdin);
	
	printf("Cidade (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].cidade, MAX, stdin);
	
	printf("Tipo de comida (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*tam].tipoComida, MAX, stdin);
	
	maiuscula(dados[*tam].tipoComida, strlen(dados[*tam].tipoComida));
	
	do
	{
		printf("Nota para a cozinha de 0 (p�ssima) a 5 (�tima): ");
		fflush(stdin);
		scanf("%f", &dados[*tam].nota);
		
		if (dados[*tam].nota < 0 || dados[*tam].nota > 5)
		{
			printf("\nValor inv�lido! Tente colocar um n�mero de 0 a 5.\n");
		}
	}
	while (dados[*tam].nota < 0 || dados[*tam].nota > 5);
	
	*cod = *cod + 1;
	
	dados[*tam].codigo = *cod;
	
	*tam = *tam + 1;
	
	printf("\nRestaurante adicionado a lista com sucesso!\n\n");
	
	return;
}

// FUN��O CASO 2 - LISTAR TODOS OS RESTAURANTES
void listaRestaurantes(Avaliacao *restaurantes, int tam)
{
	for (int rest = 0; rest < tam; rest++)
	{
		printf("C�digo: %d\n", restaurantes[rest].codigo);
		printf("Nome do restaurante: %s", restaurantes[rest].nome);
		printf("Bairro: %s", restaurantes[rest].bairro);
		printf("Cidade: %s", restaurantes[rest].cidade);
		printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
		printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
		printf("\n=========================================================\n\n");
	}
	
	return;
}

// FUN��O CASO 3 - EXCLUIR UM RESTAURANTE DA LISTA
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
			
			printf("\n\tRestaurante: %s\tC�digo: %d\n\tFoi exclu�do com sucesso!\n\n", nomeRest, codExclusao);
		}
	}
	
	return;
}

// FUN��O CASO 4 - LISTAR COM FILTRO DE NOTA
void filtroNota(Avaliacao *restaurantes, int tam, float nota)
{
	int encontrado = 0;
	
	for (int rest = 0; rest < tam; rest++)
	{
		if (restaurantes[rest].nota > nota)
		{
			printf("C�digo: %d\n", restaurantes[rest].codigo);
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

// FUN��O CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
void filtroTipoComida(Avaliacao *restaurantes, int tam, char *tipoComida)
{
	int encontrado = 0;
	
	for (int rest = 0; rest < tam; rest++)
	{
		if (!strcmp(restaurantes[rest].tipoComida, tipoComida))
		{
			printf("C�digo: %d\n", restaurantes[rest].codigo);
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
