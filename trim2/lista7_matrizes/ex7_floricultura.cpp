/*
7) Uma floricultura conhecedora de sua clientela gostaria de fazer um programa que
pudesse controlar sempre um estoque mínimo de determinadas plantas, pois todo
dia, pela manhã, o dono faz novas aquisições. Criar um algoritmo que deixe
cadastrar 50 plantas, nome, estoque mínimo, estoque atual. Imprimir ao final do
programa uma lista das plantas que devem ser adquiridas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int NUMPLANT = 50, INFOS = 2;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nomePlant[NUMPLANT][50];
	int estoque[NUMPLANT][INFOS];
	
	printf("PROGRAMA - ESTOQUE DA FLORICULTURA (Máx. %d plantas)\n", NUMPLANT);
	
	for (int i = 0; i < NUMPLANT; i++)
	{
		printf("\n==============================================\n");
		
		printf("\nPLANTA %d\n\n", i + 1);
		
		fflush(stdin);
		
		printf("Nome: ");
		fgets(nomePlant[i], 50, stdin);
		
		printf("Estoque mínimo: ");
		scanf("%d", &estoque[i][0]);
		
		printf("Estoque atual: ");
		scanf("%d", &estoque[i][1]);
	}
	
	system("cls");
	
	printf("LISTA DE PLANTAS QUE DEVEM SER ADQUIRIDAS\n\n");
	
	printf("==============================================\n");
	
	for (int i = 0; i < NUMPLANT; i++)
	{
		if (estoque[i][1] < estoque[i][0])
		{	
			printf("\nNome: %s\n", nomePlant[i]);
			
			printf("==============================================\n");
		}
	}
	
	system("pause");
	return 0;
}
