/* 5) Fa�a um programa que leia o saldo e o % de reajuste de uma aplica��o financeira e 
imprimir o novo saldo ap�s o reajuste. O c�lculo deve ser feito por uma fun��o. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float reajustaSaldo(float saldoAtual, float percentReajuste);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float saldo_atual, perc_reajuste, novo_saldo;
	
	printf("Informe o saldo atual: R$ ");
	scanf("%f", &saldo_atual);
	
	printf("Informe o valor do reajuste (em %%): ");
	scanf("%f", &perc_reajuste);
	
	novo_saldo = reajustaSaldo(saldo_atual, perc_reajuste);
	
	printf("\nO saldo ap�s o reajuste de %.2f %% ficou em R$ %.2f\n\n.", perc_reajuste, novo_saldo);
	
	system("pause");
	return 0;
}

float reajustaSaldo(float saldoAtual, float percentReajuste)
{
	float novoSaldo;
	
	novoSaldo = saldoAtual + (percentReajuste / 100.0 * saldoAtual);
	
	return novoSaldo;
}
