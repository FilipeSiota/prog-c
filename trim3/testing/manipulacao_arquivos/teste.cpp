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
	
	int total_gravado, v[5] = {1, 2, 3, 4, 5};
	
	// ABERTURA DO ARQUIVO
	arq = fopen("numeros.txt", "w");
	
	// verica se ocorreu algum erro
	if (arq == NULL)
	{
		perror("\nO seguinte erro ocorreu: ");
		
		system("pause");
		exit(1);
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
	}
	
	char nome[20] = "Ricardo";
	int idade = 30;
	float altura = 1.74;
	int resultado = fprintf(arq, "Nome: %s\nIdade: %d\nAltura: %f\n", nome, idade, altura);
	if (resultado < 0)
	{
		printf("Erro na escrita.\n");
	}
}
