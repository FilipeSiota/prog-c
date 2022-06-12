/*
5) Faça um programa que armazene 10 letras em um vetor e imprima uma listagem
numerada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 10;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char letras[TAM];
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe a %d° letra: ", i + 1);
		scanf("%c", &letras[i]);
		
		fflush(stdin); // limpar o buffer do teclado
		
	}
	
	for (int i = 0; i < TAM; i++) {
		
		printf("\n%2d) %c", i + 1, letras[i]);
		
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}
