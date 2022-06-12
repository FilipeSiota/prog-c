#include <stdio.h>
#include <conio.h>

int main(void) {
	int num = 8;
	float num2 = 8;
	
	printf ("Valor: %6d!\n", num); // Imprime uma variável inteira com no mínimo 6 casas, alinhadas a direita
	printf ("Valor: %-6d!\n", num); // Imprime uma variável inteira com no mínimo 6 casas, alinhadas a esquerda.
	printf ("Valor: %4.2f!\n", num2); // Imprime uma variável float com no mínimo 4 dígitos sendo no máximo 2 decimais.
	
	getchar();
	//puts("hello world"); // funcao simples de saida de texto, sempre coloca quebra de linha após imprimir
	
	/* <getch and getche>
	// A diferença destas funções para o getchar é que os caracteres são recuperados no momento da digitação,
	sem a necessidade de se pressionar a teclar ENTER.
	
	char letra = getch(); // não mostra na tela
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
