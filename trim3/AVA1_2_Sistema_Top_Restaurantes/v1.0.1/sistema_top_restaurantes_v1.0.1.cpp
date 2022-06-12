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

// DEFINE CONSTANTES
#define MAX 100
#define MAX_RESTAURANTE 1000

// =========================================================================================

// ESTRUTURA DE DADOS PARA ARMAZENAR A AVALIA��O DE CADA RESTAURANTE

struct avaliacao
{
	int id; // identificador do restaurante que ser� usado para exclus�o, caso necess�rio
	char nome[MAX];
	char bairro[MAX];
	char cidade[MAX];
	char tipoComida[MAX];
	float nota;
};

typedef struct avaliacao Avaliacao; // transforma o STRUCT em um tipo de dado

// =========================================================================================

// PROT�TIPOS DE FUN��ES

void mostraCabecalho(int numRestaurantes);
void mostraOpcoes(int *opcao);
void maiuscula(char *string, int tam);
void adicionaRestaurante(Avaliacao *dados, int *quantRestaurantes, int *cod);
void listaRestaurantes(Avaliacao *restaurantes, int quantRestaurantes);
void excluiRestaurante(Avaliacao *restaurantes, int *quantRestaurantes, int idExclusao);
void filtroNota(Avaliacao *restaurantes, int quantRestaurantes, float minNota);
void filtroTipoComida(Avaliacao *restaurantes, int quantRestaurantes, char *tipoComida);

// =========================================================================================

// FUN��O PRINCIPAL

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// VARI�VEIS PARA O CASO 1 - ADICIONAR RESTAURANTE A LISTA
	Avaliacao restaurantes[MAX_RESTAURANTE];
	int quantRest = 0; // quantidade de restaurantes
	int cod = 0; // usado para atribuir IDs aos restaurantes
	
	// VARI�VEIS PARA O CASO 3 - EXCLUIR RESTAURANTE DA LISTA
	int idExclusao; // ID que ser� usado para exclus�o
	int confirmaExclusao;
	
	// VARI�VEIS PARA O CASO 4 - LISTAR COM FILTRO DE NOTA
	float minNota; // nota m�nima atribu�da pelo usu�rio para usar no filtro
	
	// VARI�VEIS PARA O CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
	char tipoComida[MAX]; // tipo de comida, tamb�m atribu�do pelo usu�rio, usada no filtro
	
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
				
				// IMPEDE A INSER��O DE NOVOS RESTAURANTES CASO O N�MERO M�XIMO DE CADASTROS TENHA SIDO ATINGIDO
				if (quantRest < MAX_RESTAURANTE)
				{
					adicionaRestaurante(restaurantes, &quantRest, &cod);
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
				
				// LISTA APENAS SE TIVER ALGUM RESTAURANTE CADASTRADO
				if (quantRest > 0)
				{
					listaRestaurantes(restaurantes, quantRest);
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
				
				// A FUN��O DE EXCLUS�O ESTAR� DISPON�VEL APENAS SE HOUVER ALGUM RESTAURANTE CADASTRADO
				if (quantRest > 0)
				{
					// INSTRU��ES
					printf("Para excluir um restaurante da lista, voc� precisa ter o ID do mesmo.\nCaso voc� n�o saiba o ID, siga as seguintes instru��es:\n\n");
					
					printf("\t1� Digite no campo abaixo o valor 0;\n");
					printf("\t2� No menu de op��es, escolha a op��o (2) para listar todos os restaurantes;\n");
					printf("\t3� Verifique o ID do respectivo restaurante;\n");
					printf("\t4� Copie o ID e volte ao menu de op��es;\n");
					printf("\t5� Escolha a op��o (3) para excluir um restaurante da lista;\n");
					printf("\t6� Cole o ID no campo abaixo.\n\n");
					
					// SOLICITA O ID DO RESTAURANTE QUE SE DESEJA EXCLUIR
					do
					{
						printf("Informe o ID do restaurante que desejas excluir ou 0 para retornar ao menu de op��es: ");
						fflush(stdin);
						scanf("%d", &idExclusao);
						
						if (idExclusao < 0)
						{
							printf("\nID inv�lido! Tente novamente.\n");
						}
					}
					while (idExclusao < 0);
					
					// CASO SEJA UM ID V�LIDO, OU SEJA, MAIOR QUE ZERO...
					if (idExclusao > 0)
					{
						confirmaExclusao = 0;
						
						// PERCORRE O VETOR DOS RESTAURANTES PROCURANDO O RESPECTIVO ID
						for (int i = 0; i < quantRest; i++)
						{
							// CASO ESTE SEJA ENCONTRADO, MOSTRA AS INFORMA��ES DO RESTAURANTE AO USU�RIO, PARA A CONFIRMA��O DE QUE � REALMENTE AQUELE RESTAURANTE O QUAL ELE DESEJA EXCLUIR
							if (restaurantes[i].id == idExclusao)
							{
								printf("\nRestaurante encontrado...\n\n");
								printf("ID: %d\n", restaurantes[i].id);
								printf("Nome do restaurante: %s", restaurantes[i].nome);
								printf("Bairro: %s", restaurantes[i].bairro);
								printf("Cidade: %s", restaurantes[i].cidade);
								printf("Tipo de comida: %s", restaurantes[i].tipoComida);
								printf("Nota para a cozinha: %.1f\n", restaurantes[i].nota);
								printf("\n=========================================================\n\n");
								
								// CONFIRMA��O DE EXCLUS�O
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
								
								// CASO SEJA CONFIRMADO, EXECUTA A FUN��O DE EXCLUS�O
								if (confirmaExclusao == 1)
								{
									excluiRestaurante(restaurantes, &quantRest, idExclusao);
								}
								else // SEN�O, CANCELA A OPERA��O
								{
									printf("\nOpera��o cancelada!\n\n");
								}
							}
							else if (i == quantRest - 1 && !confirmaExclusao)
							{
								printf("\nNenhum restaurante com este ID foi encontrado!\n\n");
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
				
				// ESTA FUN��O ESTAR� DISPON�VEL APENAS SE HOUVER ALGUM RESTAURANTE CADASTRADO
				if (quantRest > 0)
				{
					do
					{
						printf("Listar restaurantes cuja nota para a cozinha � superior a [informe n�meros de 0 (p�ssima) a 5 (�tima)]: ");
						fflush(stdin);
						scanf("%f", &minNota);
						
						if (minNota < 0 || minNota > 5)
						{
							printf("\nValor inv�lido! Tente colocar um n�mero de 0 a 5.\n");
						}
					}
					while (minNota < 0 || minNota > 5);
					
					printf("\n=========================================================\n\n");
					
					// APLICA O FILTRO COM BASE NA NOTA M�NIMA INFORMADA PELO USU�RIO
					filtroNota(restaurantes, quantRest, minNota);
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
				
				// ESTA FUN��O ESTAR� DISPON�VEL APENAS SE HOUVER ALGUM RESTAURANTE CADASTRADO
				if (quantRest > 0)
				{
					printf("Listar restaurantes cujo tipo de comida �: ");
					fflush(stdin);
					fgets(tipoComida, MAX - 1, stdin);
					
					printf("\n=========================================================\n\n");
					
					// TRANSFORMA A STRING INTEIRA EM MAI�SCULA, PARA FACILITAR NA COMPARA��O DE STRINGS
					maiuscula(tipoComida, strlen(tipoComida));
					
					// APLICA O FILTRO COM BASE NO TIPO DE COMIDA INFORMADO PELO USU�RIO
					filtroTipoComida(restaurantes, quantRest, tipoComida);
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
	
	// MENSAGEM DE ENCERRAMENTO DO PROGRAMA
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
	
	// EVITA A INSER��O DE OP��ES INV�LIDAS
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
void maiuscula(char *string, int quantRestaurantes)
{
	for (int letra = 0; letra < quantRestaurantes; letra++)
	{
		// toupper() � uma fun��o da biblioteca ctype.h, que transforma uma letra em mai�scula
		string[letra] = toupper(string[letra]);
	}
	
	return;
}

// FUN��O CASO 1 - ADICIONAR UM RESTAURANTE A LISTA
void adicionaRestaurante(Avaliacao *dados, int *quantRestaurantes, int *cod)
{
	// SOLICITA AS INFORMA��ES SOBRE O RESTAURANTE
	printf("Complete os campos com as informa��es referentes ao restaurante:\n\n");
				
	printf("Nome (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*quantRestaurantes].nome, MAX, stdin);
	
	printf("Bairro (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*quantRestaurantes].bairro, MAX, stdin);
	
	printf("Cidade (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*quantRestaurantes].cidade, MAX, stdin);
	
	printf("Tipo de comida (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	fgets(dados[*quantRestaurantes].tipoComida, MAX, stdin);
	
	// TRANSFORMA A STRING INTEIRA EM MAI�SCULA, PARA FACILITAR NA COMPARA��O DE STRINGS
	maiuscula(dados[*quantRestaurantes].tipoComida, strlen(dados[*quantRestaurantes].tipoComida));
	
	do
	{
		printf("Nota para a cozinha de 0 (p�ssima) a 5 (�tima): ");
		fflush(stdin);
		scanf("%f", &dados[*quantRestaurantes].nota);
		
		if (dados[*quantRestaurantes].nota < 0 || dados[*quantRestaurantes].nota > 5)
		{
			printf("\nValor inv�lido! Tente colocar um n�mero de 0 a 5.\n");
		}
	}
	while (dados[*quantRestaurantes].nota < 0 || dados[*quantRestaurantes].nota > 5);
	
	// INCREMENTA UM AO CONTADOR RESPONS�VEL PELOS IDs DOS RESTAURANTES
	*cod = *cod + 1;
	
	// ATRIBUI UM ID AO RESTAURANTE
	dados[*quantRestaurantes].id = *cod;
	
	// INCREMENTA UM AO N�MERO TOTAL DE RESTAURANTES CADASTRADOS
	*quantRestaurantes = *quantRestaurantes + 1;
	
	printf("\nRestaurante adicionado a lista com sucesso!\n\n");
	
	return;
}

// FUN��O CASO 2 - LISTAR TODOS OS RESTAURANTES
void listaRestaurantes(Avaliacao *restaurantes, int quantRestaurantes)
{
	// PERCORRE TODO O VETOR DOS RESTAURANTES, LISTANDO-OS
	for (int rest = 0; rest < quantRestaurantes; rest++)
	{
		printf("ID: %d\n", restaurantes[rest].id);
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
void excluiRestaurante(Avaliacao *restaurantes, int *quantRestaurantes, int idExclusao)
{
	char nomeRest[MAX]; // ARMAZENA  O NOME DO RESTAURANTE A SER EXCLU�DO PARA APRESENT�-LO, AP�S A EXCLUS�O, PARA O USU�RIO
	
	// PERCORRE O VETOR DOS RESTAURANTES
	for (int rest = 0; rest < *quantRestaurantes; rest++)
	{
		// QUANDO ACHAR O ID CORRESPONDENTE AO DE EXCLUS�O
		if (restaurantes[rest].id == idExclusao)
		{
			// ARMAZENA O NOME DO RESTAURANTE PARA MOSTRAR AO USU�RIO DEPOIS
			strcpy(nomeRest, restaurantes[rest].nome);
			
			// REORGANIZA O VETOR, PASSANDO TODOS OS DADOS, A PARTIR DA PRIMEIRA POSI��O AP�S A DOS QUE FORAM EXCLU�DOS, PARA UMA POSI��O IMEDIATEMENTE INFERIOR
			for (int org = rest + 1; org < *quantRestaurantes; org++)
			{
				restaurantes[org - 1].id = restaurantes[org].id;
				strcpy(restaurantes[org - 1].nome, restaurantes[org].nome);
				strcpy(restaurantes[org - 1].bairro, restaurantes[org].bairro);
				strcpy(restaurantes[org - 1].cidade, restaurantes[org].cidade);
				strcpy(restaurantes[org - 1].tipoComida, restaurantes[org].tipoComida);
				restaurantes[org - 1].nota = restaurantes[org].nota;
			}
			
			// DECRESCE UM DO N�MERO DE RESTAURANTES
			*quantRestaurantes = *quantRestaurantes - 1;
			
			// MOSTRA UMA MENSAGEM DE SUCESSO
			printf("\n\tRestaurante: %s\tID: %d\n\tFoi exclu�do com sucesso!\n\n", nomeRest, idExclusao);
		}
	}
	
	return;
}

// FUN��O CASO 4 - LISTAR COM FILTRO DE NOTA
void filtroNota(Avaliacao *restaurantes, int quantRestaurantes, float minNota)
{
	int encontrado = 0; // PARA VERIFICAR ALGO FOI ENCONTRADO NA CONSULTA
	
	for (int rest = 0; rest < quantRestaurantes; rest++)
	{
		// SE A NOTA FOR MAIOR QUE A NOTA M�NIMA INFORMADA PELO USU�RIO...
		if (restaurantes[rest].nota > minNota)
		{
			printf("ID: %d\n", restaurantes[rest].id);
			printf("Nome do restaurante: %s", restaurantes[rest].nome);
			printf("Bairro: %s", restaurantes[rest].bairro);
			printf("Cidade: %s", restaurantes[rest].cidade);
			printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
			printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
			printf("\n=========================================================\n\n");
			
			encontrado = 1; // SIGNIFICA QUE ALGO FOI ENCONTRADO
		}
		else if (rest == quantRestaurantes - 1 && !encontrado)
		{
			printf("Nenhum restaurante foi encontrado!\n\n");
		}
	}
	
	return;
}

// FUN��O CASO 5 - LISTAR COM FILTRO DE TIPO DE COMIDA
void filtroTipoComida(Avaliacao *restaurantes, int quantRestaurantes, char *tipoComida)
{
	int encontrado = 0; // PARA VERIFICAR ALGO FOI ENCONTRADO NA CONSULTA
	
	for (int rest = 0; rest < quantRestaurantes; rest++)
	{
		// SE OS TIPOS DE COMIDA FOREM IGUAIS...
		if (!strcmp(restaurantes[rest].tipoComida, tipoComida))
		{
			printf("ID: %d\n", restaurantes[rest].id);
			printf("Nome do restaurante: %s", restaurantes[rest].nome);
			printf("Bairro: %s", restaurantes[rest].bairro);
			printf("Cidade: %s", restaurantes[rest].cidade);
			printf("Tipo de comida: %s", restaurantes[rest].tipoComida);
			printf("Nota para a cozinha: %.1f\n", restaurantes[rest].nota);
			printf("\n=========================================================\n\n");
			
			encontrado = 1; // SIGNIFICA QUE ALGO FOI ENCONTRADO
		}
		else if (rest == quantRestaurantes - 1 && !encontrado)
		{
			printf("Nenhum restaurante foi encontrado!\n\n");
		}
	}
	
	return;
}
