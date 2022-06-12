/*
17. Escreva um programa para contar dinheiro que pergunte, dentro de um monte
de dinheiro, qual a quantidade de notas de:
	• 1 real
	• 5 reais
	• 10 reais
	• 50 reais
	• 100 reais
Em seguida, o programa imprime qual o valor total em dinheiro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PROGRAMA "Contador de Dinheiro"

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int cash1, cash5, cash10, cash50, cash100;
	float total;
	
	printf("%s\n\n", PROGRAMA);
	
	puts("Informe as respectivas quantidades de notas de:");
	
	printf("1 real: ");
	scanf("%d", &cash1);
	
	printf("5 reais: ");
	scanf("%d", &cash5);
	
	printf("10 reais: ");
	scanf("%d", &cash10);
	
	printf("50 reais: ");
	scanf("%d", &cash50);
	
	printf("100 reais: ");
	scanf("%d", &cash100);
	
	total = cash1 + 5.0 * cash5 + 10.0 * cash10 + 50.0 * cash50 + 100.0 * cash100;
	
	printf("\nTotal: R$%.2f\n\n", total);
	
	system("pause");
	return 0;
}
