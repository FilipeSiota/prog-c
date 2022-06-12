/*
6) Receba uma palavra de 7 letras do usu�rio e escreva ela ao contr�rio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int TAM = 8; // lembrando que o �ltimo espa�o na mem�ria � usado para guardar o caracter "/0", terminador da string.

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char word[TAM]; // lembrando que o �ltimo espa�o na mem�ria � usado para guardar o caracter "/0", terminador da string.
	int numChar;
	
	/*
	Ocorre, que o �ltimo caracter de uma string, deve ser sempre o caracter nulo �\0� que serve para indicar o final da string.
	Sendo assim, em nosso exemplo temos 7 caracteres �teis para armazenar o nome, pois o \0 � o terminador da string e ocupa uma posi��o de armazenamento.
	*/
	
	printf("Informe uma palavra de no m�ximo %d letras: ", TAM - 1);
	fgets(word, TAM, stdin);
	
	numChar = strlen(word);
	
	printf("\nA palavra \"");
	
	for (int i = 0; i < numChar; i++) { // dessa forma, n�o obtemos o �ltimo caracter "/0", o terminador da string.
		
		if (word[i] != '\n') { // dessa forma, n�o obtemos o caracter "/n", quebra de linha.
			
			printf("%c", word[i]);
			
		}
		
	}
	
	printf("\" ao contr�rio � ");
	
	for (int i = numChar - 1; i >= 0; i--) { // dessa forma, n�o obtemos o �ltimo caracter "/0", o terminador da string.
		
		if (word[i] != '\n') { // dessa forma, n�o obtemos o caracter "/n", quebra de linha.
		
			printf("%c", word[i]);
			
		}
		
	}
	
	printf(".\n\n");
	
	system("pause");
	return 0;
}
