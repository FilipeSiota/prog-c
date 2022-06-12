/*
3. Escreva um programa que gerencie uma tabela de notas. Ao executar, o usu�rio
ter� as seguintes op��es:
	1. Adicionar mais um aluno (RA e nota);
	2. Exibir todas as notas;
	3. Calcular a m�dia. O programa deve usar um arquivo texto para
	armazenar e consultar as informa��es.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// # PROT�TIPOS DE FUN��ES
void menu(int *opcao);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp_add; // esta manter� a posi��o atual do ponteiro no arquivo durante adi��es de alunos
	FILE *fp_read;
	int opcao;
	int createFile;
	int status;
	float somaNotas = 0;
	int totalAlunos = 0;
	float mediaNotas;
	
	// Vari�veis para cadastro da nota de um novo aluno
	char registroAluno[100];
	float nota;
	
	// mostra o menu de op��es
	menu(&opcao);
	
	while (opcao)
	{
		switch (opcao)
		{
			case 1:
				system("cls");
				
				printf("########## GERENCIAMENTO DE NOTAS ##########\n\n");
				
				printf(">> 1. Adicionar um aluno\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_add = fopen("ex3_tabela_notas.txt", "a");
				
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
						fp_add = fopen("ex3_tabela_notas.txt", "w");
						
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
				printf("Registro de aluno: ");
				scanf("%s", &registroAluno);
				fflush(stdin);
				
				printf("Nota: ");
				scanf("%f", &nota);
				fflush(stdin);
				
				// grava os dados no arquivo
				status = fprintf(fp_add, " %s %.2f ", registroAluno, nota);
				
				// caso ocorra algum erro
				if (status < 0)
				{
					printf("Erro na escrita.\n");
					
					system("pause");
					exit(1);
				}
				else
				{
					printf("\n[Grava��o bem sucedida no arquivo] >> Aluno(a) adicionado(a).\n\n");
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
				
				printf("########## GERENCIAMENTO DE NOTAS ##########\n\n");
				
				printf(">> 2. Exibir todas as notas\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_read = fopen("ex3_tabela_notas.txt", "r");
				
				// se der erro na abertura, considera que o arquivo n�o existe, logo, n�o h� notas cadastradas
				if (fp_read == NULL)
				{
					printf("Ainda n�o h� notas cadastradas.\n\n");
					
					system("pause");
					break;
				}
							
				// enquanto n�o chegar o final do arquivo		
				while (!feof(fp_read))
				{
					// l� do arquivo os dados
					fscanf(fp_read, "%s %f", registroAluno, &nota);
					
					// caso seja o final do arquivo, sai
					if (feof(fp_read))
					{
						break;
					}
					
					// mostra em tela os dados lidos do arquivo
					printf("Registro de aluno: %s\n", registroAluno);
					printf("Nota: %.2f\n\n", nota);
				}
				
				printf("[Leitura bem sucedida]\n\n");
				
				// FECHAMENTO DO ARQUIVO
				status = fclose(fp_read);
			
				// caso ocorra algum erro
				if (status)
				{
					printf("\nErro ao fechar o arquivo.\n");
						
					system("pause");
					exit(1);
				}
				
				system("pause");
				
				break;
				
			case 3:
				system("cls");
				
				printf("########## GERENCIAMENTO DE NOTAS ##########\n\n");
				
				printf(">> 3. Calcular a m�dia\n\n");
				
				// ABERTURA DO ARQUIVO
				fp_read = fopen("ex3_tabela_notas.txt", "r");
				
				// se der erro na abertura, considera que o arquivo n�o existe, logo, n�o h� notas cadastradas
				if (fp_read == NULL)
				{
					printf("Ainda n�o h� notas cadastradas.\n\n");
					
					system("pause");
					break;
				}
				
				// reinicializa-se as vari�veis contadoras em zero
				somaNotas = 0;
				totalAlunos = 0;
				
				// enquanto n�o chegar o final do arquivo	
				while (!feof(fp_read))
				{
					// l� do arquivo os dados
					fscanf(fp_read, "%s %f", registroAluno, &nota);
					
					// caso seja o final do arquivo, sai
					if (feof(fp_read))
					{
						break;
					}
					
					// vai somando as notas
					somaNotas += nota;
					
					// conta a quantidade de alunos cadastrados
					totalAlunos++;
				}
				
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
				if (totalAlunos > 0)
				{
					printf("[Leitura bem sucedida]\n\n");
					
					mediaNotas = somaNotas / totalAlunos;
				
					printf("A m�dia de notas, considerando as notas dos %d alunos cadastradas, �: %.2f\n\n", totalAlunos, mediaNotas);
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
	
	printf("########## GERENCIAMENTO DE NOTAS ##########\n\n");
	
	printf(">> Menu\n\n");
	
	printf("1. Adicionar um aluno\n2. Exibir todas as notas\n3. Calcular a m�dia\n\n");
	
	do
	{
		printf("Escolha uma das op��es ou 0 para sair: ");
		scanf("%d", opcao);
		
		if (*opcao < 1 || *opcao > 3)
		{
			printf("\nOp��o inv�lida! Tente novamente.\n");
		}
	}
	while (*opcao < 1 || *opcao > 3);
}
