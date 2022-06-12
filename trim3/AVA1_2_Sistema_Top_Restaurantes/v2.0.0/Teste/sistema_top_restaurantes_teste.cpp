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
	
	TRABALHO FINAL
	
	O maior desafio das empresas de desenvolvimento de software � criar sistemas robustos,
	no menor tempo poss�vel e com baixo custo. Para que isso aconte�a, � imprescind�vel a
	ado��o de boas pr�ticas durante a programa��o.

	A �ltima atividade da disciplina, vai ser fazer uma atualiza��o no primeiro trabalho
	(Sistema de Restaurantes), providenciando as seguintes adapta��es:
	
	� A op��o de: Inserir, Ler e Excluir os dados deve ser realizada utilizando arquivos.
	� Fazer uso correto de endenta��o do c�digo.
	� Documentar o c�digo, com coment�rios explicando cada bloco.
	� Fazer ajustes que julgue necess�rio para que seu c�digo fique claro: nomes de vari�veis,
	fun��es e estruturas que fa�am sentido ao seu contexto.
	� Reavalie a sua l�gica e a estrutura do seu c�digo. Se achar que algo pode ser melhorado,
	melhore!
	
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
#include <stdbool.h>

// DEFINE CONSTANTES
#define MAX 100

// =========================================================================================

// ESTRUTURA DE DADOS PARA ARMAZENAR A AVALIA��O DE CADA RESTAURANTE

struct cadastro
{
	int id; // identificador do restaurante que ser� usado para exclus�o, caso necess�rio
	char nome[MAX];
	char bairro[MAX];
	char cidade[MAX];
	char tipoComida[MAX];
	float nota;
};

typedef struct cadastro CADASTRO; // transforma o STRUCT em um tipo de dado

// =========================================================================================

// PROT�TIPOS DE FUN��ES

void getBackup(int *cod, int *quantRestaurantes);
void maiuscula(char *string, int quantRestaurantes);
void cabecalho(int quantRestaurantes);
void menu(int *opcao);
void adicionar(int *quantRestaurantes, int *cod);
void listar(int quantRestaurantes);
void excluir(int *quantRestaurantes);

// =========================================================================================

// FUN��O PRINCIPAL

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int quantRest = 0; // quantidade de restaurantes
	int cod = 0; // usado para atribuir IDs aos restaurantes
	int opcao;
	
	// =====================================================================
	
	// PEGAR OS VALORES DE cod E quantRest BASEANDO-SE NO ARQUIVO
	getBackup(&cod, &quantRest);
	
	// MOSTRA O CABE�ALHO
	cabecalho(quantRest);
		
	printf("Seja bem-vind@ ao nosso sistema!\n\n");
	
	// MOSTRA O MENU
	menu(&opcao);
	
	// ENQUANTO O USU�RIO N�O DIGITAR PARA SAIR...
	while (opcao != 4)
	{
		switch (opcao)
		{
			case 1:
				// ADICIONA UM RESTAURANTE
				adicionar(&quantRest, &cod);
				
				break;
				
			case 2:
				// LISTA OS RESTAURANTES
				listar(quantRest);
				
				break;
				
			case 3:
				// EXCLUI UM RESTAURANTE
				excluir(&quantRest);
				
				break;
		}
		
		system("cls");
		
		// MOSTRA CABE�ALHO
		cabecalho(quantRest);
		
		// MOSTRA MENU
		menu(&opcao);
	}
	
	system("cls");
	
	// MENSAGEM DE ENCERRAMENTO DO PROGRAMA
	
	// MOSTRA CABE�ALHO
	cabecalho(quantRest);
	
	printf("Agradecemos a sua prefer�ncia pelo SISTEMA TOP RESTAURANTES!\n");
	printf("\tDesenvolvido por: Filipe Mallmann Siota - DS2\n\n");
	
	system("pause");
	return 0;
}

// =========================================================================================

// FUN��O PARA PEGAR OS VALORES DE cod E quantRestaurantes BASEANDO NO ARQUIVO (CHECK)
void getBackup(int *cod, int *quantRestaurantes)
{
	FILE *arquivo;
	
	CADASTRO restaurante;
	int status;
	
	// ABERTURA DO ARQUIVO
	arquivo = fopen("lista_restaurantes_teste.txt", "r");
	
	// CASO OCORRA ALGUM ERRO
	if (arquivo == NULL)
	{
		perror("O seguinte erro ocorreu ");
		
		system("pause");
		exit(1);
	}
	
	// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
	while (fread(&restaurante, sizeof(CADASTRO), 1, arquivo) == 1)
	{
		// ARMAZENA O MAIOR C�DIGO ENTRE OS ATUAIS REGISTROS
		if (!quantRestaurantes)
		{
			*cod = restaurante.id;
		}
		else if (restaurante.id > *cod)
		{
			*cod = restaurante.id;
		}
		
		// CONTADOR DO N�MERO DE RESTAURANTES CADASTRADOS
		*quantRestaurantes = *quantRestaurantes + 1;
	}
	
	// FECHAMENTO DO ARQUIVO
	status = fclose(arquivo);
	
	// CASO OCORRA ALGUM ERRO
	if (status)
	{
		perror("O seguinte erro ocorreu ");
	}
}

// FUN��O QUE TRANSFORMA UMA STRING EM MAI�SCULA (CHECK)
void maiuscula(char *string, int quantRestaurantes)
{
	for (int letra = 0; letra < quantRestaurantes; letra++)
	{
		// toupper() � uma fun��o da biblioteca ctype.h, que transforma uma letra em mai�scula
		string[letra] = toupper(string[letra]);
	}
	
	return;
}

// FUN��O QUE MOSTRA O CABE�ALHO (CHECK)
void cabecalho(int quantRestaurantes)
{
	printf("################# SISTEMA TOP RESTAURANTES #################\n\n");
	
	printf("N�mero de restaurantes cadastrados: %d\n\n", quantRestaurantes);
	
	return;
}

// FUN��O QUE MOSTRA AS OP��ES (CHECK)
void menu(int *opcao)
{	
	printf("1. Adicionar um novo restaurante na lista\n");
	printf("2. Listar restaurantes\n");
	printf("3. Excluir um restaurante da lista\n");
	printf("4. Sair\n\n");
	
	// EVITA A INSER��O DE OP��ES INV�LIDAS
	do
	{
		printf("Informe uma das op��es acima: ");
		fflush(stdin);
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 4)
		{
			printf("\nOp��o inv�lida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 4);
	
	return;
}

// FUN��O CASO 1 - ADICIONAR UM RESTAURANTE A LISTA (CHECK)
void adicionar(int *quantRestaurantes, int *cod)
{
	FILE *lista;
	
	CADASTRO restaurante;
	int status;
	
	system("cls");
				
	cabecalho(*quantRestaurantes);
				
	printf("=========================================================\n\n");
					
	// SOLICITA AS INFORMA��ES SOBRE O RESTAURANTE
	printf("Complete os campos com as informa��es referentes ao restaurante:\n\n");
				
	printf("Nome (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	gets(restaurante.nome);
	
	printf("Bairro (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	gets(restaurante.bairro);
	
	printf("Cidade (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	gets(restaurante.cidade);
	
	printf("Tipo de comida (m�x. %d caracteres): ", MAX);
	fflush(stdin);
	gets(restaurante.tipoComida);
	
	// TRANSFORMA A STRING INTEIRA EM MAI�SCULA, PARA FACILITAR NA COMPARA��O DE STRINGS
	maiuscula(restaurante.tipoComida, strlen(restaurante.tipoComida));
	
	do
	{
		printf("Nota para a cozinha de 0 (p�ssima) a 5 (�tima): ");
		fflush(stdin);
		scanf("%f", &restaurante.nota);
		
		if (restaurante.nota < 0 || restaurante.nota > 5)
		{
			printf("\nValor inv�lido! Tente colocar um n�mero de 0 a 5.\n");
		}
	}
	while (restaurante.nota < 0 || restaurante.nota > 5);
	
	// INCREMENTA UM AO CONTADOR RESPONS�VEL PELOS IDs DOS RESTAURANTES
	*cod = *cod + 1;
	
	// ATRIBUI UM ID AO RESTAURANTE
	restaurante.id = *cod;
	
	// INCREMENTA UM AO N�MERO TOTAL DE RESTAURANTES CADASTRADOS
	*quantRestaurantes = *quantRestaurantes + 1;
	
	// ABERTURA DO ARQUIVO
	lista = fopen("lista_restaurantes_teste.txt", "a");
	
	// CASO OCORRA ALGUM ERRO
	if (lista == NULL)
	{
		printf("Erro na abertura do arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// GRAVA NO ARQUIVO OS DADOS
	status = fwrite(&restaurante, sizeof(CADASTRO), 1, lista);
	
	// CASO OCORRA ALGUM ERRO
	if (status < 1)
	{
		printf("Erro de grava��o no arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	else
	{
		printf("\nRestaurante adicionado a lista com sucesso!\n\n");
	}
	
	// FECHAMENTO DO ARQUIVO
	status = fclose(lista);
	
	// CASO OCORRA ALGUM ERRO
	if (status)
	{
		perror("O seguinte erro ocorreu ");
		
		system("pause");
		exit(1);
	}
	
	system("pause");
	
	system("cls");
	
	return;
}

// FUN��O CASO 2 - LISTAR RESTAURANTES (CHECK)
void listar(int quantRestaurantes)
{
	FILE *lista;
	
	CADASTRO restaurante;
	int opcao;
	float minNota;
	bool achou;
	char tipoComida[MAX];
	int status;
	
	system("cls");
				
	cabecalho(quantRestaurantes);
				
	printf("=========================================================\n\n");
	
	// SE A QUANTIDADE DE RESTAURANTES NO SISTEMA FOR MAIOR QUE 0...
	if (quantRestaurantes > 0)
	{	
		printf("1. Listar todos os restaurantes\n");
		printf("2. Listar restaurantes por filtro de nota\n");
		printf("3. Listar restaurantes por filtro de tipo de comida\n");
		printf("4. Voltar\n\n");
		
		// SOLICITA A OP��O
		do
		{
			printf("Escolha uma op��o: ");
			scanf("%d", &opcao);
			
			if (opcao < 1 || opcao > 4)
			{
				printf("\nOp��o inv�lida! Tente novamente.\n");
			}
		}
		while (opcao < 1 || opcao > 4);
		
		// SE N�O FOR A OP��O DE SAIR
		if (opcao != 4)
		{
			system("cls");
				
			cabecalho(quantRestaurantes);
						
			printf("=========================================================\n\n");
			
			// ABERTURA DO ARQUIVO
			lista = fopen("lista_restaurantes_teste.txt", "r");
			
			// CASO OCORRA ALGUM ERRO
			if (lista == NULL)
			{
				perror("O seguinte erro ocorreu ");
				
				system("pause");
				exit(1);
			}
			
			switch (opcao)
			{
				case 1: // Listar todos os restaurantes
				
					// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
					while (fread(&restaurante, sizeof(CADASTRO), 1, lista) == 1)
					{
						printf("ID: %d\n", restaurante.id);
						printf("Nome do restaurante: %s\n", restaurante.nome);
						printf("Bairro: %s\n", restaurante.bairro);
						printf("Cidade: %s\n", restaurante.cidade);
						printf("Tipo de comida: %s\n", restaurante.tipoComida);
						printf("Nota para a cozinha: %.1f\n", restaurante.nota);
						printf("\n=========================================================\n\n");
					}
					
					printf("[Leitura do arquivo bem sucedida]\n\n");
					
					system("pause");
					
					break;
				
				case 2: // Listar restaurantes por filtro de nota
				
					// SOLICITA A ENTRADA DE DADOS
					do
					{
						printf("Listar restaurantes cuja nota para a cozinha � superior ou igual a [informe n�meros de 0 (p�ssima) a 5 (�tima)]: ");
						scanf("%f", &minNota);
						
						if (minNota < 0 || minNota > 5)
						{
							printf("\nValor inv�lido! Tente colocar um n�mero de 0 a 5.\n");
						}
					}
					while (minNota < 0 || minNota > 5);
					
					printf("\n=========================================================\n\n");
					
					achou = false;
					
					// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
					while (fread(&restaurante, sizeof(CADASTRO), 1, lista) == 1)
					{
						// SE A NOTA FOR MAIOR OU IGUAL A M�NIMA...
						if (restaurante.nota >= minNota)
						{
							printf("ID: %d\n", restaurante.id);
							printf("Nome do restaurante: %s\n", restaurante.nome);
							printf("Bairro: %s\n", restaurante.bairro);
							printf("Cidade: %s\n", restaurante.cidade);
							printf("Tipo de comida: %s\n", restaurante.tipoComida);
							printf("Nota para a cozinha: %.1f\n", restaurante.nota);
							printf("\n=========================================================\n\n");
							
							achou = true;
						}
					}
					
					// SE N�O ACHOU
					if (!achou)
					{
						printf("Nenhum restaurante foi encontrado!\n\n");
					}
					
					system("pause");
					
					break;
					
				case 3: // Listar restaurantes por filtro de tipo de comida
				
					// SOLICITA ENTRADA DE DADOS
					printf("Listar restaurantes cujo tipo de comida �: ");
					fflush(stdin);
					gets(tipoComida);
					
					printf("\n=========================================================\n\n");
					
					// TRANSFORMA A STRING INTEIRA EM MAI�SCULA, PARA FACILITAR NA COMPARA��O DE STRINGS
					maiuscula(tipoComida, strlen(tipoComida));
					
					achou = false;
					
					// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
					while (fread(&restaurante, sizeof(CADASTRO), 1, lista) == 1)
					{
						// SE O TIPO DE COMIDA DA PESQUISA FOR IGUAL A DA RESPECTIVA LEITURA DOS DADOS DO ARQUIVO
						if (!strcmp(restaurante.tipoComida, tipoComida))
						{
							printf("ID: %d\n", restaurante.id);
							printf("Nome do restaurante: %s\n", restaurante.nome);
							printf("Bairro: %s\n", restaurante.bairro);
							printf("Cidade: %s\n", restaurante.cidade);
							printf("Tipo de comida: %s\n", restaurante.tipoComida);
							printf("Nota para a cozinha: %.1f\n", restaurante.nota);
							printf("\n=========================================================\n\n");
							
							achou = true;
						}
					}
					
					// SE N�O ACHOU
					if (!achou)
					{
						printf("Nenhum restaurante foi encontrado!\n\n");
					}
					
					system("pause");
					
					break;
			}
			
			// FECHAMENTO DO ARQUIVO
			status = fclose(lista);
			
			// CASO OCORRA ALGUM ERRO
			if (status)
			{
				perror("O seguinte erro ocorreu ");
				
				system("pause");
				exit(1);
			}
		}
	}
	else // SE O N�MERO DE RESTAURANTES CADASTRADOS FOR 0...
	{
		printf("Nenhum restaurante foi adicionado ainda!\n\n");
		
		system("pause");
	}
	
	return;
}

// FUN��O CASO 3 - EXCLUIR UM RESTAURANTE (DANDO ERRO NO MOMENTO DE RENOMEAR E REMOVER ARQUIVOS)
void excluir(int *quantRestaurantes)
{
	FILE *lista;
	FILE *arq_saida;
	
	CADASTRO restaurante;
	int idExclusao;
	int confirmaExclusao;
	bool achou, error;
	int status;
	
	system("cls");
				
	cabecalho(*quantRestaurantes);
				
	printf("=========================================================\n\n");
	
	// SE A QUANTIDADE DE RESTAURANTES NO SISTEMA FOR MAIOR QUE 0...
	if (*quantRestaurantes > 0)
	{
		// INSTRU��ES
		printf("Para excluir um restaurante da lista, voc� precisa ter o ID do mesmo.\nCaso voc� n�o saiba o ID, siga as seguintes instru��es:\n\n");
		
		printf("\t1� Digite no campo abaixo o valor 0;\n");
		printf("\t2� No menu de op��es, escolha a op��o (2) e depois a op��o (1) para listar todos os restaurantes;\n");
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
			// ABERTURA DOS ARQUIVOS
			lista = fopen("lista_restaurantes_teste.txt", "r");
			arq_saida = fopen("lista_restaurantes_nova_teste.txt", "w");
			
			// CASO OCORRA ALGUM ERRO
			if (lista == NULL || arq_saida == NULL)
			{
				printf("Erro na abertura do arquivo.\n\n");
				
				system("pause");
				exit(1);
			}
		
			confirmaExclusao = 0;
			
			achou = false;
			
			// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
			while (fread(&restaurante, sizeof(CADASTRO), 1, lista) == 1)
			{
				// SE O ID DA PESQUISA CORRESPONDER AO ID OBTIDO PELA LEITURA NO ARQUIVO
				if (idExclusao == restaurante.id)
				{
					achou = true;
					
					printf("\nRestaurante encontrado...\n\n");
					
					printf("ID: %d\n", restaurante.id);
					printf("Nome do restaurante: %s\n", restaurante.nome);
					printf("Bairro: %s\n", restaurante.bairro);
					printf("Cidade: %s\n", restaurante.cidade);
					printf("Tipo de comida: %s\n", restaurante.tipoComida);
					printf("Nota para a cozinha: %.1f\n", restaurante.nota);
					printf("\n=========================================================\n\n");
					
					// CONFIRMA��O DE EXCLUS�O
					do
					{
						printf("Voc� deseja realmente excluir este restaurante da lista?\n\nDigite (1) para SIM ou (2) para N�O: ");
						scanf("%d", &confirmaExclusao);
						
						if (confirmaExclusao < 1 || confirmaExclusao > 2)
						{
							printf("\nOp��o inv�lida! Tente novamente.\n");
						}
					}
					while (confirmaExclusao < 1 || confirmaExclusao > 2);
					
					// CASO SEJA CONFIRMADO, EXECUTA A EXCLUS�O DO RESTAURANTE
					if (confirmaExclusao == 1)
					{
						printf("\n=========================================================\n");
						
						// VOLTA PARA O IN�CIO DO ARQUIVO
						rewind(lista);
						
						// EXECUTA OS COMANDOS ENQUANTO A LEITURA OCORRER, OU SEJA, ENQUANTO RETORNAR O TOTAL PR�-ESTABELECIDO DE UNIDADES DE DADOS QUE DEVEM SER LIDAS
						while (fread(&restaurante, sizeof(CADASTRO), 1, lista) == 1)
						{
							// SE O ID DA PESQUISA CORRESPONDER AO ID OBTIDO PELA LEITURA NO ARQUIVO
							if (idExclusao == restaurante.id)
							{								
				                printf("\nID: %d | Restaurante: %s\n", restaurante.id, restaurante.nome);
				                
				                // GRAVA OS DADOS REFERENTES AO ID DE EXCLUS�O COMO NULL NO ARQUIVO NOVO
                				fwrite(NULL, sizeof(CADASTRO), 1, arq_saida);
							}
							else
							{
								// SE FOR O FINAL DO ARQUIVO, SAI DO BLOCO WHILE
							    if (feof(lista))
								{
									break;
								}
								
								// GRAVA OS OUTROS DADOS NO ARQUIVO NOVO
				                fwrite(&restaurante, sizeof(CADASTRO), 1, arq_saida);
				            }
						}
					}
					else // SEN�O, CANCELA A OPERA��O
					{
						printf("\nOpera��o cancelada!\n\n");
					}
					
					break;
				}
			}
			
			// FECHAMENTO DO ARQUIVO 1
			status = fclose(lista);
			
			// CASO OCORRA ALGUM ERRO
			if (status)
			{
				perror("O seguinte erro ocorreu ");
				
				system("pause");
				exit(1);
			}
			
			// FECHAMENTO DO ARQUIVO 2
			status = fclose(arq_saida);
			
			// CASO OCORRA ALGUM ERRO
			if (status)
			{
				perror("O seguinte erro ocorreu ");
				
				system("pause");
				exit(1);
			}
			
			// SE A EXCLUS�O TIVER SIDO CONFIRMADA
			if (confirmaExclusao == 1)
			{
				error = false;
			
				// REMOVE O BACKUP ANTIGO
				status = remove("lista_restaurantes_backup_teste.txt");
				
				// CASO OCORRA ALGUM ERRO
				if (!status)
				{
					printf("\nArquivo lista_restaurantes_backup_teste.txt deletado com sucesso!\n");
				}
				else
				{
					perror("\nO seguinte erro ocorreu ");
				}
				
				// RENOMEIA A LISTA ATUAL COMO BACKUP
				status = rename("lista_restaurantes_teste.txt", "lista_restaurantes_backup_teste.txt");
				
				// CASO OCORRA ALGUM ERRO
				if (!status)
				{
					printf("\nArquivo lista_restaurantes_teste.txt renomeado para lista_restaurantes_backup_teste.txt com sucesso!\n");
				}
				else
				{
					perror("\nO seguinte erro ocorreu ");
					
					error = true;
				}
				
				// RENOMEIA A NOVA LISTA COMO LISTA ATUAL
				status = rename("lista_restaurantes_nova_teste.txt", "lista_restaurantes_teste.txt");
				
				// CASO OCORRA ALGUM ERRO
				if (!status)
				{
					printf("\nArquivo lista_restaurantes_nova_teste.txt renomeado para lista_restaurantes_teste.txt com sucesso!\n");
				}
				else
				{
					perror("\nO seguinte erro ocorreu ");
					
					error = true;
				}
				
				printf("\n=========================================================\n");
				
				// CASO OCORRA ALGUM ERRO NO MOMENTO DE RENOMEAR
				if (error)
				{
					printf("\nERRO detectado! Opera��o cancelada.\n\n");
				}
				else
				{
					// DECRESCE UM DO N�MERO DE RESTAURANTES
					*quantRestaurantes = *quantRestaurantes - 1;
					
					// MOSTRA UMA MENSAGEM DE SUCESSO
					printf("\nRestaurante exclu�do com sucesso!\n\n");
				}
			}
			
			// SE N�O ACHOU
			if (!achou)
			{
				printf("\nNenhum restaurante com este ID foi encontrado!\n\n");
			}
		}
		
		system("pause");
	}
	else // SE O N�MERO DE RESTAURANTES CADASTRADOS FOR 0...
	{
		printf("N�o h� restaurantes cadastrados ainda!\n\n");
		
		system("pause");
	}
	
	return;
}
