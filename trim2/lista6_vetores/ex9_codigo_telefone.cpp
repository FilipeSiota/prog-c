/*
9) Suponha dois vetores de 30 elementos cada, contendo: código e telefone. Faça um
programa que permita buscar pelo código e imprimir o telefone.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int TAM = 30;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char cod[TAM][50], codigo[50], tel[TAM][15];
	int buscar = 0;

	printf("########## Cadastrando ##########\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("\nCADASTRO %d:\n\n", i + 1);
		
		printf("Informe um código: ");
		gets(cod[i]);
		fflush(stdin);
		
		printf("Informe um telefone: ");
		gets(tel[i]);
		fflush(stdin);
		
	}
	
	printf("\n########## Buscando ##########\n");
	
	printf("\nInforme o número do código que desejas buscar: ");
	gets(codigo);
	fflush(stdin);
	
	for (int i = 0; i < TAM; i++) {
		
		if ( !strcmp(cod[i], codigo) ) {
			
			printf("\nTelefone: %s\n\n", tel[i]);
			
			buscar = 1;
			
			break;
			
		}
		
	}
	
	if (!buscar) {
		
		printf("\nCódigo não encontrado!\n\n");
		
	}
	
	system("pause");
	return 0;
}
