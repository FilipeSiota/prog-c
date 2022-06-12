/*
1. Escreva um programa que leia vários números inteiros e grave-os num arquivo
texto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// porteiro para o arquivo
	FILE *arq;
	
	int num, status;
	
	// ABERTURA DO ARQUIVO
	arq = fopen("ex1_numeros.txt", "w");
	
	// verica se ocorreu algum erro
	if (arq == NULL)
	{
		perror("\nO seguinte erro ocorreu");
		
		system("pause");
		exit(1);
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
	}
	
	// solicita ao usuário a entrada de dados
	printf("\nInforme um número ou 0 para sair: ");
	scanf("%d", &num);
	
	while (num)
	{
		// escrevendo o número inserido pelo usuário no arquivo
		status = fprintf(arq, "%d\n", num); // os números aparecerão de forma muito estranha quando usei fwrite()
		
		// verica se ocorreu algum erro
		if (status < 0)
		{
			perror("\nO seguinte erro ocorreu");
			
			system("pause");
			exit(1);
		}
		
		printf("\nInforme um número ou 0 para sair: ");
		scanf("%d", &num);
	}
	
	// FECHAMENTO DO ARQUIVO
	status = fclose(arq);
	
	// verica se ocorreu algum erro
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
