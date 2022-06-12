/*
Exerc�cio
Usando o �ltimo exerc�cio como base, fa�a um programa para informar o per�odo de renova��o
dos exames da carteira de habilita��o.
	- Menores de idade n�o possuem carteira.
	- At� 65 anos, os prazos s�o de 5 em 5 anos;
	- depois, o exame precisa de renova��o a cada 3 anos.
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
		
		puts("\nEm rela��o a sua idade, o exame da carteira de habilita��o precisa de renova��o de 5 em 5 anos.\n");
		
	} else if (idade > 65) {
		
		puts("\nEm rela��o a sua idade, o exame da carteira de habilita��o precisa de renova��o a cada 3 anos.\n");
	
	} else {
		
		puts("\nMenores de idade n�o possuem carteira.\n");
		
	}
	
	system("pause");
	
	return 0;
}
