/*
Exercício exemplo 2
Uma agência bancária de uma cidade do interior tem, no máximo, 10 mil clientes. Criar um
programa em C que possa entrar com o número da conta, o nome e o saldo de cada cliente.
Imprimir todas as contas, os respectivos saldos e uma das mensagens: positivo/negativo. A
digitação acaba quando se digita -999 para número da conta ou quando chegar a 10 mil clientes.
Ao final, deverá sair o total de clientes com saldo negativo, o total de clientes da agência e o
saldo da agência. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int conta, totalNeg = 0, totalCl = 0;
	char nome[50];
	float saldo, saldoTotal = 0;
	
	printf("Informe o número da conta ou -999 para encerrar: ");
	scanf("%d", &conta);
	
	while (conta > 0 && totalCl < 10000) {
		
		printf("Nome: ");
		scanf("%s", &nome);
		
		printf("Saldo: R$");
		scanf("%f", &saldo);
		
		saldoTotal += saldo;
		
		if (saldo < 0) {
			
			totalNeg++;
			printf("\nConta: %d\nSaldo: R$%.2f --> negativo\n\n", conta, saldo);
			
		} else {
			
			printf("\nConta: %d\nSaldo: R$%.2f --> positivo\n\n", conta, saldo);
			
		}
		
		totalCl++;
		
		printf("Informe o número da conta ou -999 para encerrar: ");
		scanf("%d", &conta);
	}
	
	printf("\nClientes com saldo negativo: %d", totalNeg);
	printf("\nTotal de clientes na agência: %d", totalCl);
	printf("\nSaldo da agência: R$%.2f\n\n", saldoTotal);
	
	system("pause");
	return 0;
}
