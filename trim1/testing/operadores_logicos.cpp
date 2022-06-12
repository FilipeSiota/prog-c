/*
Exercício
Usando o último exercício como base, faça um programa para informar o período de renovação
dos exames da carteira de habilitação.
	- Menores de idade não possuem carteira.
	- Até 65 anos, os prazos são de 5 em 5 anos;
	- depois, o exame precisa de renovação a cada 3 anos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int idade;
	
	printf("Informe sua idade: ");
	scanf("%d", &idade);
	
	if ( (idade >= 18) && (idade <= 65) ) {
		
		puts("\nEm relação a sua idade, o exame da carteira de habilitação precisa de renovação de 5 em 5 anos.\n");
		
	} else if (idade > 65) {
		
		puts("\nEm relação a sua idade, o exame da carteira de habilitação precisa de renovação a cada 3 anos.\n");
	
	} else {
		
		puts("\nMenores de idade não possuem carteira.\n");
		
	}
	
	system("pause");
	
	return 0;
}
