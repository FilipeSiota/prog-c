/*Faça um programa em C que calcule os juros de um determinado saldo com base em
uma taxa, ambos informados pelo usuário. O programa deve utilizar uma função para
calcular os juros e atualizar o saldo atual com base no saldo antigo acrescido dos juros.
Ao final, a aplicação deve imprimir o total de juros e o novo saldo.*/

#include <stdio.h>
#include <stdlib.h>

float calculaJuros(float *saldo, float taxa)
{
	float juros;
	
	juros = *saldo * taxa / 100.0;
	
	*saldo += juros;
	
	return juros;
}

int main()
{
	float saldoAtual, taxa, juros;
	
	printf("Informe seu saldo: ");
	scanf("%f", &saldoAtual);
	
	printf("Informe a taxa de juros (%%): ");
	scanf("%f", &taxa);
	
	juros = calculaJuros(&saldoAtual, taxa);
	
	printf("\nTotal de juros: R$ %.2f\n", juros);
	printf("Novo saldo: R$ %.2f\n\n", saldoAtual);
	
	system("pause");
	return 0;
}
