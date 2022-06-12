#include <stdio.h>
#include <conio.h>
#include <string.h> // biblioteca de funcoes para manipular strings

int main(void) {
	char str1[15] = "Curso de C";
	char str2[20] = "Curso de Java";
	int retorno;
	
	retorno = strncmp(str1, str2, 5);
	
	//vari�vel do tipo inteiro = strncmp(string1, string2, tamanho);
	// Tamb�m faz a compara��o do conte�do de duas strings, por�m, deve ser especificado o tamanho a ser comparado;
	// Poss�veis valores de retorno:
	// 0: conte�do das strings s�o iguais
	// < 0: conte�do da string1 � menor do que string2
	// > 0: conte�do da string1 � maior do que string2
	
	printf("retorno = %d\n", retorno);
	
	return 0;
	
	/* char str1[4] = "abc";
	char str2[4] = "abd";
	int retorno;
	
	retorno = strcmp(str1, str2);
	
	// vari�vel do tipo inteiro = strcmp(string1, string2);
	// Compara o conte�do de duas strings;
	// Poss�veis valores de retorno:
	// 0: conte�do das strings s�o iguais
	// < 0: conte�do da string1 � menor do que string2
	// > 0: conte�do da string1 � maior do que string2
	
	printf("retorno = %d\n", retorno);
	//mostra o retorno da fun��o strcmp
	
	return 0; */
	
	/* char str[10] = "Curso";
	int tamanho;
	
	tamanho = strlen(str);
	// vari�vel do tipo inteiro = strlen(string);
	// Determina o tamanho de uma string.
	
	printf("O tamanho da string %s e %d\n", str, tamanho);
	
	getch();
	return 0; */
	
	/* char str1[17] = "Curso";
	char str2[20] = " de programacao C";
	
	strncat(str1, str2, 15);
	//concatena a string1 com 15 posi��es da string2
	
	// strncat(string_destino, string_origem, tamanho);
	// Realiza a concatena��o do conte�do de uma vari�vel a outra, por�m, deve ser especificado o tamanho a ser concatenado.
	
	printf("str1 = %s\n", str1);
	//Ser� exibido Curso de Programa��o
	
	getch();
	return 0; */
	
	/* char str[10] = "Curso";
	
	strcat(str, " de C");
	// Concatena a string " de C" com o conte�do da string str
	
	// strcat(string_destino, string_origem);
	// Realiza a concatena��o do conte�do de uma vari�vel a outra
	
	printf("str = %s\n", str);
	//Ser� exibido curso de C
	
	getch();
	return 0; */
	
	/* char str1[8] = "Curso C";
	char str2[5];
	
	strncpy(str2, str1, 5);
	// strncpy(string_destino, string_origem, tamanho);
	// Realiza a c�pia do conte�do de uma vari�vel a outra, por�m, deve ser especificado o tamanho a ser copiado.
	
	str2[5] = '\0';
	printf("str2 = %s\n", str2);
	
	getch();
	return 0; */
	
	/* char nome[15];
	
	strcpy(nome, "Fulano de Tal");
	// Realiza a c�pia do conte�do de uma vari�vel a outra.
	// strcpy(string_destino, string_origem);
	// note que a string de destino � nome
	// a string de origem � "Fulano de Tal"
	
	printf("Nome = %s", nome);
	
	getch(); // for�a o terminal a ficar aberto ao final de um programa
	return 0; */
}
