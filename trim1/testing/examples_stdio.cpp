#include <stdio.h>
#include <conio.h>

int main(void) {
	int num = 8;
	float num2 = 8;
	
	printf ("Valor: %6d!\n", num); // Imprime uma vari�vel inteira com no m�nimo 6 casas, alinhadas a direita
	printf ("Valor: %-6d!\n", num); // Imprime uma vari�vel inteira com no m�nimo 6 casas, alinhadas a esquerda.
	printf ("Valor: %4.2f!\n", num2); // Imprime uma vari�vel float com no m�nimo 4 d�gitos sendo no m�ximo 2 decimais.
	
	getchar();
	//puts("hello world"); // funcao simples de saida de texto, sempre coloca quebra de linha ap�s imprimir
	
	/* <getch and getche>
	// A diferen�a destas fun��es para o getchar � que os caracteres s�o recuperados no momento da digita��o,
	sem a necessidade de se pressionar a teclar ENTER.
	
	char letra = getch(); // n�o mostra na tela
	char vogal = getche(); // mostra na tela
	
	/* <getchar and putchar>
	char letra = getchar();
	
	putchar(65); // <caracter ou codigo ASCII do caracter para impressao>*/
	
	/* <gets>
	char nome[10];
	
	printf("Digite o nome do cliente: ");
	gets(nome);
	
	printf("%s", nome); */
	
	/* <scanf> 
	char nome[10];
	int idade;
	
	scanf("%s %i", nome, &idade);
	
	printf("%s\n%i", nome, idade);*/
}
