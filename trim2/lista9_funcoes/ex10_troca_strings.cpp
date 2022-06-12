/* 10) Escreva uma função que receba duas strings e troque o conteúdo da primeira string com 
o conteúdo da segunda. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void trocaStrings (char *string1, char *string2, int tamanho);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char str1[51], str2[51];
	
	printf("Informe a 1ª string (máx. 50 caracteres): ");
	fflush(stdin);
	scanf("%50[^\n]", str1);
	
	printf("Informe a 2ª string (máx. 50 caracteres): ");
	fflush(stdin);
	scanf("%50[^\n]", str2);
	
	trocaStrings(str1, str2, 51);
	
	printf("\n==============================================");
	printf("\n      O CONTEÚDO DAS STRINGS FOI TROCADO      ");
	printf("\n==============================================");
	
	printf("\n\nString 1:\n\n\t| %s", str1);
	printf("\n\nString 2:\n\n\t| %s\n\n", str2);
	
	system("pause");
	return 0;
}

void trocaStrings (char *string1, char *string2, int tamanho)
{
	char stringAux[tamanho];
	
	strcpy(stringAux, string1);
	strcpy(string1, string2);
	strcpy(string2, stringAux);
	
	return;
}
