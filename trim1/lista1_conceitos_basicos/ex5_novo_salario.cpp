/*
5. Faça um programa que recebe o salário de um funcionário e o percentual de
aumento, calcule e mostre o valor do aumento e o novo salário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float salario, percPlus, valPlus;
	
	printf("Informe seu salário atual: R$");
	scanf("%f", &salario);
	
	printf("Informe o percentual de aumento: ");
	scanf("%f", &percPlus);
	
	valPlus = percPlus / 100 * salario;
	salario += valPlus;
	
	printf("\nValor do aumento: R$%.2f\nNovo salário: R$%.2f\n\n", valPlus, salario);
	
	system("pause");
	return 0;
}
