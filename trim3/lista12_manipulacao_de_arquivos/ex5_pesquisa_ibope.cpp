/*
5. O IBOPE realizou uma pesquisa a nível nacional. Foi entrevistado um certo
número de pessoas. Cada pessoa respondeu ao seguinte questionário:
	• Sexo: ( )M ( )F
	• Idade: ____ anos
	• Fumante: ( )S ( )N
Considere um arquivo binário de registros (denominado “resposta.bin”) que
contém as respostas de todas as pessoas entrevistadas. Cada registro armazena
a resposta de uma pessoa entrevistada através dos seguintes campos: sexo (um
caractere, podendo ser ‘M’ ou ‘F’), idade (valor inteiro), fumante (um caractere,
podendo ser ‘S’ ou ‘N’). Faça um programa que leia este arquivo binário e
responda as seguintes perguntas:
	• Qual é o percentual de fumantes em relação ao número total de pessoas
	entrevistadas?
	• Qual é o percentual de homens não fumantes abaixo de 40 anos em relação
	ao número total de homens entrevistados?
	• Qual é o percentual de mulheres fumantes acima de 40 anos em relação ao
	número total de mulheres entrevistadas?
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

// # PROTÓTIPOS DE FUNÇÕES
void menu(int *opcao);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp_add; // esta manterá a posição atual do ponteiro no arquivo durante adições de entrevistas
	FILE *fp_read;
	int opcao;
	int createFile;
	int status;
	int balanco1, balanco2, balanco3;
	float perc1, perc2, perc3;
	int totalHomens, totalMulheres;
	int totalEntrevistados;
	
	// variáveis referentes a pesquisa
	char sexo;
	int idade;
	char fumante;
	
	// mostra o menu de opções
	menu(&opcao);
	
	while (opcao)
	{
		switch (opcao)
		{
			case 1:
				system("cls");
				
				printf("########## PESQUISA - IBOPE ##########\n\n");
				
				printf(">> 1. Adicionar entrevista\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_add = fopen("ex5_respostas.bin", "ab");
				
				// caso não consiga / não exista
				if (fp_add == NULL)
				{
					// pergunta se o arquivo já existe no diretório do usuário
					printf("Você já possui um arquivo tabela_notas.txt neste diretório?\n\nInforme 1 para SIM ou 2 para NÃO: ");
					scanf("%d", createFile);
					
					// se for
					if (createFile == 2)
					{
						// tenta criar uma novo arquivo
						fp_add = fopen("ex5_respostas.bin", "wb");
						
						// caso ocorra erro mesmo assim
						if (fp_add == NULL)
						{
							printf("Erro na criação do arquivo.\n\n");
							
							system("pause");
							exit(1);
						}
						else
						{
							printf("[Arquivo criado com sucesso!]\n\n");
						}
					}
					else // se ele já existe no diretório
					{
						printf("Erro na abertura do arquivo.\n\n");
							
						system("pause");
						exit(1);
					}
				}
				
				// solicita entrada de dados pelo usuário
				do
				{
					printf("Sexo [(M) para MASCULINO ou (F) para FEMININO]: ");
					fflush(stdin);
					scanf("%c", &sexo);
					
					sexo = toupper(sexo);
					
					if (sexo != 'M' && sexo != 'F')
					{
						printf("\nRespota inválida! Tente novamente.\n");
					}
				}
				while (sexo != 'M' && sexo != 'F');
				
				do
				{
					printf("Idade: ");
					fflush(stdin);
					scanf("%d", &idade);
					
					if (idade < 0)
					{
						printf("\nRespota inválida! Tente novamente.\n");
					}
				}
				while (idade < 0);
				
				do
				{
					printf("Fumante [(S) para SIM ou (N) para NÃO]: ");
					fflush(stdin);
					scanf("%c", &fumante);
					
					fumante = toupper(fumante);
					
					if (fumante != 'S' && fumante != 'N')
					{
						printf("\nRespota inválida! Tente novamente.\n");
					}
				}
				while (fumante != 'S' && fumante != 'N');
				
				// grava os dados no arquivo
				status = fprintf(fp_add, "%c %d %c\n", sexo, idade, fumante);
				
				// caso ocorra algum erro
				if (status < 0)
				{
					printf("Erro na escrita.\n");
					
					system("pause");
					exit(1);
				}
				else
				{
					printf("\n[Gravação bem sucedida no arquivo] >> Entrevista adicionada.\n\n");
				}
				
				// FECHAMENTO DO ARQUIVO
				status = fclose(fp_add);
				
				// se houver algum erro
				if (status)
				{
					printf("\nErro ao fechar o arquivo.\n");
						
					system("pause");
					exit(1);
				}
				
				system("pause");
				
				break;
			
			case 2:
				system("cls");
				
				printf("########## PESQUISA - IBOPE ##########\n\n");
				
				printf(">> 2. Mostrar balanço da pesquisa\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_read = fopen("ex5_respostas.bin", "rb");
				
				// se der erro na abertura, considera que o arquivo não existe, logo, não há entrevistas adicionadas ao programa ainda
				if (fp_read == NULL)
				{
					printf("Nenhuma pessoa foi entrevistada ainda.\n\n");
					
					system("pause");
					break;
				}
				
				// reinicializa-se as variáveis contadoras em zero
				balanco1 = 0;
				balanco2 = 0;
				balanco3 = 0;
				totalHomens = 0;
				totalMulheres = 0;
				
				printf("=========================================\n\n");
				
				// enquanto não chegar o final do arquivo	
				while (!feof(fp_read))
				{
					// lê do arquivo os dados
					fscanf(fp_read, "%c %d %c\n", &sexo, &idade, &fumante);
					
					printf("Sexo: %c\nIdade: %d\nFumante: %c\n\n", sexo, idade, fumante);
					
					// condições a respeito das perguntas para o balanço da pesquisa
					
					if (fumante == 'S')
					{
						balanco1++; // fumantes
						
						if (sexo == 'F' && idade > 40)
						{
							balanco3++; // mulheres fumantes acima de 40 anos
						}
					}
					else
					{
						if (sexo == 'M' && idade < 40)
						{
							balanco2++; // homens não fumantes abaixo de 40 anos
						}
					}
					
					if (sexo == 'M')
					{
						totalHomens++;
					}
					else
					{
						totalMulheres++;
					}
				}
				
				totalEntrevistados = totalHomens + totalMulheres;
				
				// FECHAMENTO DO ARQUIVO
				status = fclose(fp_read);
			
				// caso ocorra algum erro
				if (status)
				{
					printf("\nErro ao fechar o arquivo.\n");
						
					system("pause");
					exit(1);
				}
				
				// se houverem alunos com suas notas cadastradas
				// evita divisão por 0
				if (totalEntrevistados > 0)
				{
					printf("[Leitura bem sucedida]\n\n");
					
					perc1 = balanco1 * 100.0 / totalEntrevistados; // percentual de fumantes em relação ao número total de pessoas entrevistadas
					
					// evita divisão por 0
					if (totalHomens > 0)
					{
						perc2 = balanco2 * 100.0 / totalHomens; // percentual de homens não fumantes abaixo de 40 anos em relação ao número total de homens entrevistados
					}
					
					// evita divisão por 0
					if (totalMulheres > 0)
					{
						perc3 = balanco3 * 100.0 / totalMulheres; // percentual de mulheres fumantes acima de 40 anos em relação ao número total de mulheres entrevistadas
					}
					
					printf("=========================================\n\n");
					
					printf("Qual é o percentual de fumantes em relação ao número total de pessoas entrevistadas?\n>> %.2f%% (%d/%d)\n\n", perc1, balanco1, totalEntrevistados);
					printf("Qual é o percentual de homens não fumantes abaixo de 40 anos em relação ao número total de homens entrevistados?\n>> %.2f%% (%d/%d)\n\n", perc2, balanco2, totalHomens);
					printf("Qual é o percentual de mulheres fumantes acima de 40 anos em relação ao número total de mulheres entrevistadas?\n>> %.2f%% (%d/%d)\n\n", perc3, balanco3, totalMulheres);
				}
				
				system("pause");
				
				break;
		}
		
		menu(&opcao);
	}
	
	printf("\nSaindo do programa...\n\n");
	
	system("pause");
	return 0;
}

// # CORPO DAS FUNÇÕES
void menu(int *opcao)
{
	system("cls");
	
	printf("########## PESQUISA - IBOPE ##########\n\n");
	
	printf(">> Menu\n\n");
	
	printf("1. Adicionar entrevista\n2. Mostrar balanço da pesquisa\n\n");
	
	do
	{
		printf("Escolha uma das opções ou 0 para sair: ");
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 2)
		{
			printf("\nOpção inválida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 2);
}
