/*
2. Escreva um programa que:
	a. Crie/abra um arquivo texto de nome �arq.txt�.
	b. Permita que o usu�rio grave diversos caracteres nesse arquivo, at� que o
	usu�rio entre com o caractere �0�.
	c. Feche o arquivo
	Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os
	caracteres armazenados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// ponteiro para arquivo
	FILE *arq;
	char c;
	int status;
	
	// ABERTURA DO ARQUIVO
	arq = fopen("ex2_arq.txt", "w");
	
	// caso ocorra algum erro
	if (arq == NULL)
	{
		printf("Erro na cria��o/abertura do arquivo.\n");
		
		system("pause");
		exit(1);
	}
	
	// solicita a entrada de dados ao usu�rio
	printf("Informe um caractere qualquer ou 0 para sair: ");
	scanf("%c", &c);
	
	while (c != '0')
	{
		// grava no arquivo o caractere informado pelo usu�rio
		status = fputc(c, arq);
		
		// caso ocorra algum erro
		if (status == EOF)
		{
			printf("Erro na escrita.\n");
			
			system("pause");
			exit(1);
		}
		else
		{
			printf("\nCaractere foi inserido no arquivo!\n");
		}
		
		printf("\nInforme um caractere qualquer ou 0 para sair: ");
		fflush(stdin);
		scanf("%c", &c);
	}
	
	// FECHAMENTO DO ARQUIVO
	status = fclose(arq);
	
	// caso ocorra algum erro
	if (status)
	{
		perror("\nO seguinte erro ocorreu");
			
		system("pause");
		exit(1);
	}
	else
	{
		printf("\nArquivo fechado com sucesso!\n");
	}
	
	//==================================================================
	
	// ABERTURA DO ARQUIVO
	arq = fopen("ex2_arq.txt", "r");
	
	// caso ocorra algum erro
	if (arq == NULL)
	{
		printf("Erro na abertura do arquivo.\n");
		
		system("pause");
		exit(1);
	}
	
	printf("\nOs caracteres armazenados foram:\n\n");
	
	while (!feof(arq))
	{	
		c = fgetc(arq);
		
		if (feof(arq))
		{
			break;
		}
		
		printf("%c\n", c);
	}
	
	// FECHAMENTO DO ARQUIVO
	status = fclose(arq);
	
	// caso ocorra algum erro
	if (status)
	{
		perror("\nO seguinte erro ocorreu");
			
		system("pause");
		exit(1);
	}
	else
	{
		printf("\nArquivo fechado com sucesso!\n");
	}
	
	system("pause");
	return 0;
}
