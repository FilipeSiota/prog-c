#include <stdio.h>
#include <conio.h>
#include <string.h> // biblioteca de funcoes para manipular strings

int main(void) {
	char str1[15] = "Curso de C";
	char str2[20] = "Curso de Java";
	int retorno;
	
	retorno = strncmp(str1, str2, 5);
	
	//variável do tipo inteiro = strncmp(string1, string2, tamanho);
	// Também faz a comparação do conteúdo de duas strings, porém, deve ser especificado o tamanho a ser comparado;
	// Possíveis valores de retorno:
	// 0: conteúdo das strings são iguais
	// < 0: conteúdo da string1 é menor do que string2
	// > 0: conteúdo da string1 é maior do que string2
	
	printf("retorno = %d\n", retorno);
	
	return 0;
	
	/* char str1[4] = "abc";
	char str2[4] = "abd";
	int retorno;
	
	retorno = strcmp(str1, str2);
	
	// variável do tipo inteiro = strcmp(string1, string2);
	// Compara o conteúdo de duas strings;
	// Possíveis valores de retorno:
	// 0: conteúdo das strings são iguais
	// < 0: conteúdo da string1 é menor do que string2
	// > 0: conteúdo da string1 é maior do que string2
	
	printf("retorno = %d\n", retorno);
	//mostra o retorno da função strcmp
	
	return 0; */
	
	/* char str[10] = "Curso";
	int tamanho;
	
	tamanho = strlen(str);
	// variável do tipo inteiro = strlen(string);
	// Determina o tamanho de uma string.
	
	printf("O tamanho da string %s e %d\n", str, tamanho);
	
	getch();
	return 0; */
	
	/* char str1[17] = "Curso";
	char str2[20] = " de programacao C";
	
	strncat(str1, str2, 15);
	//concatena a string1 com 15 posições da string2
	
	// strncat(string_destino, string_origem, tamanho);
	// Realiza a concatenação do conteúdo de uma variável a outra, porém, deve ser especificado o tamanho a ser concatenado.
	
	printf("str1 = %s\n", str1);
	//Será exibido Curso de Programação
	
	getch();
	return 0; */
	
	/* char str[10] = "Curso";
	
	strcat(str, " de C");
	// Concatena a string " de C" com o conteúdo da string str
	
	// strcat(string_destino, string_origem);
	// Realiza a concatenação do conteúdo de uma variável a outra
	
	printf("str = %s\n", str);
	//Será exibido curso de C
	
	getch();
	return 0; */
	
	/* char str1[8] = "Curso C";
	char str2[5];
	
	strncpy(str2, str1, 5);
	// strncpy(string_destino, string_origem, tamanho);
	// Realiza a cópia do conteúdo de uma variável a outra, porém, deve ser especificado o tamanho a ser copiado.
	
	str2[5] = '\0';
	printf("str2 = %s\n", str2);
	
	getch();
	return 0; */
	
	/* char nome[15];
	
	strcpy(nome, "Fulano de Tal");
	// Realiza a cópia do conteúdo de uma variável a outra.
	// strcpy(string_destino, string_origem);
	// note que a string de destino é nome
	// a string de origem é "Fulano de Tal"
	
	printf("Nome = %s", nome);
	
	getch(); // força o terminal a ficar aberto ao final de um programa
	return 0; */
}
