/*
5. O IBOPE realizou uma pesquisa a n�vel nacional. Foi entrevistado um certo
n�mero de pessoas. Cada pessoa respondeu ao seguinte question�rio:
	� Sexo: ( )M ( )F
	� Idade: ____ anos
	� Fumante: ( )S ( )N
Considere um arquivo bin�rio de registros (denominado �resposta.bin�) que
cont�m as respostas de todas as pessoas entrevistadas. Cada registro armazena
a resposta de uma pessoa entrevistada atrav�s dos seguintes campos: sexo (um
caractere, podendo ser �M� ou �F�), idade (valor inteiro), fumante (um caractere,
podendo ser �S� ou �N�). Fa�a um programa que leia este arquivo bin�rio e
responda as seguintes perguntas:
	� Qual � o percentual de fumantes em rela��o ao n�mero total de pessoas
	entrevistadas?
	� Qual � o percentual de homens n�o fumantes abaixo de 40 anos em rela��o
	ao n�mero total de homens entrevistados?
	� Qual � o percentual de mulheres fumantes acima de 40 anos em rela��o ao
	n�mero total de mulheres entrevistadas?
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

// # PROT�TIPOS DE FUN��ES
void menu(int *opcao);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp_add; // esta manter� a posi��o atual do ponteiro no arquivo durante adi��es de entrevistas
	FILE *fp_read;
	int opcao;
	int createFile;
	int status;
	int balanco1, balanco2, balanco3;
	float perc1, perc2, perc3;
	int totalHomens, totalMulheres;
	int totalEntrevistados;
	
	// vari�veis referentes a pesquisa
	char sexo;
	int idade;
	char fumante;
	
	// mostra o menu de op��es
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
				
				// caso n�o consiga / n�o exista
				if (fp_add == NULL)
				{
					// pergunta se o arquivo j� existe no diret�rio do usu�rio
					printf("Voc� j� possui um arquivo tabela_notas.txt neste diret�rio?\n\nInforme 1 para SIM ou 2 para N�O: ");
					scanf("%d", createFile);
					
					// se for
					if (createFile == 2)
					{
						// tenta criar uma novo arquivo
						fp_add = fopen("ex5_respostas.bin", "wb");
						
						// caso ocorra erro mesmo assim
						if (fp_add == NULL)
						{
							printf("Erro na cria��o do arquivo.\n\n");
							
							system("pause");
							exit(1);
						}
						else
						{
							printf("[Arquivo criado com sucesso!]\n\n");
						}
					}
					else // se ele j� existe no diret�rio
					{
						printf("Erro na abertura do arquivo.\n\n");
							
						system("pause");
						exit(1);
					}
				}
				
				// solicita entrada de dados pelo usu�rio
				do
				{
					printf("Sexo [(M) para MASCULINO ou (F) para FEMININO]: ");
					fflush(stdin);
					scanf("%c", &sexo);
					
					sexo = toupper(sexo);
					
					if (sexo != 'M' && sexo != 'F')
					{
						printf("\nRespota inv�lida! Tente novamente.\n");
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
						printf("\nRespota inv�lida! Tente novamente.\n");
					}
				}
				while (idade < 0);
				
				do
				{
					printf("Fumante [(S) para SIM ou (N) para N�O]: ");
					fflush(stdin);
					scanf("%c", &fumante);
					
					fumante = toupper(fumante);
					
					if (fumante != 'S' && fumante != 'N')
					{
						printf("\nRespota inv�lida! Tente novamente.\n");
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
					printf("\n[Grava��o bem sucedida no arquivo] >> Entrevista adicionada.\n\n");
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
				
				printf(">> 2. Mostrar balan�o da pesquisa\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_read = fopen("ex5_respostas.bin", "rb");
				
				// se der erro na abertura, considera que o arquivo n�o existe, logo, n�o h� entrevistas adicionadas ao programa ainda
				if (fp_read == NULL)
				{
					printf("Nenhuma pessoa foi entrevistada ainda.\n\n");
					
					system("pause");
					break;
				}
				
				// reinicializa-se as vari�veis contadoras em zero
				balanco1 = 0;
				balanco2 = 0;
				balanco3 = 0;
				totalHomens = 0;
				totalMulheres = 0;
				
				printf("=========================================\n\n");
				
				// enquanto n�o chegar o final do arquivo	
				while (!feof(fp_read))
				{
					// l� do arquivo os dados
					fscanf(fp_read, "%c %d %c\n", &sexo, &idade, &fumante);
					
					printf("Sexo: %c\nIdade: %d\nFumante: %c\n\n", sexo, idade, fumante);
					
					// condi��es a respeito das perguntas para o balan�o da pesquisa
					
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
							balanco2++; // homens n�o fumantes abaixo de 40 anos
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
				// evita divis�o por 0
				if (totalEntrevistados > 0)
				{
					printf("[Leitura bem sucedida]\n\n");
					
					perc1 = balanco1 * 100.0 / totalEntrevistados; // percentual de fumantes em rela��o ao n�mero total de pessoas entrevistadas
					
					// evita divis�o por 0
					if (totalHomens > 0)
					{
						perc2 = balanco2 * 100.0 / totalHomens; // percentual de homens n�o fumantes abaixo de 40 anos em rela��o ao n�mero total de homens entrevistados
					}
					
					// evita divis�o por 0
					if (totalMulheres > 0)
					{
						perc3 = balanco3 * 100.0 / totalMulheres; // percentual de mulheres fumantes acima de 40 anos em rela��o ao n�mero total de mulheres entrevistadas
					}
					
					printf("=========================================\n\n");
					
					printf("Qual � o percentual de fumantes em rela��o ao n�mero total de pessoas entrevistadas?\n>> %.2f%% (%d/%d)\n\n", perc1, balanco1, totalEntrevistados);
					printf("Qual � o percentual de homens n�o fumantes abaixo de 40 anos em rela��o ao n�mero total de homens entrevistados?\n>> %.2f%% (%d/%d)\n\n", perc2, balanco2, totalHomens);
					printf("Qual � o percentual de mulheres fumantes acima de 40 anos em rela��o ao n�mero total de mulheres entrevistadas?\n>> %.2f%% (%d/%d)\n\n", perc3, balanco3, totalMulheres);
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

// # CORPO DAS FUN��ES
void menu(int *opcao)
{
	system("cls");
	
	printf("########## PESQUISA - IBOPE ##########\n\n");
	
	printf(">> Menu\n\n");
	
	printf("1. Adicionar entrevista\n2. Mostrar balan�o da pesquisa\n\n");
	
	do
	{
		printf("Escolha uma das op��es ou 0 para sair: ");
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 2)
		{
			printf("\nOp��o inv�lida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 2);
}
