/*
6) Receba uma palavra de 7 letras do usuário e escreva ela ao contrário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int TAM = 8; // lembrando que o último espaço na memória é usado para guardar o caracter "/0", terminador da string.

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char word[TAM]; // lembrando que o último espaço na memória é usado para guardar o caracter "/0", terminador da string.
	int numChar;
	
	/*
	Ocorre, que o último caracter de uma string, deve ser sempre o caracter nulo “\0” que serve para indicar o final da string.
	Sendo assim, em nosso exemplo temos 7 caracteres úteis para armazenar o nome, pois o \0 é o terminador da string e ocupa uma posição de armazenamento.
	*/
	
	printf("Informe uma palavra de no máximo %d letras: ", TAM - 1);
	fgets(word, TAM, stdin);
	
	numChar = strlen(word);
	
	printf("\nA palavra \"");
	
	for (int i = 0; i < numChar; i++) { // dessa forma, não obtemos o último caracter "/0", o terminador da string.
		
		if (word[i] != '\n') { // dessa forma, não obtemos o caracter "/n", quebra de linha.
			
			printf("%c", word[i]);
			
		}
		
	}
	
	printf("\" ao contrário é ");
	
	for (int i = numChar - 1; i >= 0; i--) { // dessa forma, não obtemos o último caracter "/0", o terminador da string.
		
		if (word[i] != '\n') { // dessa forma, não obtemos o caracter "/n", quebra de linha.
		
			printf("%c", word[i]);
			
		}
		
	}
	
	printf(".\n\n");
	
	system("pause");
	return 0;
}
