/*
2. Fa�a um programa que receba o ano de nascimento de uma pessoa e o ano
atual, calcule e mostre:
	a) a idade desta pessoa;
	b) quantos anos ela ter� em 2050.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int anoFuturo = 2050;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int anoNasc, anoAgr, idade, idade2050;
	
	printf("Digite o ano do seu nascimento: ");
	scanf("%d", &anoNasc);
	
	printf("Digite o ano atual: ");
	scanf("%d", &anoAgr);
	
	idade = anoAgr - anoNasc;
	idade2050 = anoFuturo - anoNasc;
	
	printf("\nVoc� tem %d anos e em 2050 ter� %d anos.\n\n", idade, idade2050);
	
	system("pause");
	return 0;
}
