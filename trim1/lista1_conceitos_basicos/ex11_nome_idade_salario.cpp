/*
11. Crie um programa que leia o nome, idade e salário de uma pessoa e logo após
mostre na tela os 3 valores na mesma linha, no formato “Nome: …, Idade: …,
Salário: ...”
	• Antes, informe ao usuário que ele precisará digitar essas 3 informações
	• A idade deve ser mostrada com pelo menos 2 dígitos, completados com 0
	• O salário deve ser mostrado com 2 casas decimais e pelo menos 1 dígito
	à esquerda completado com zero
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[50];
	int idade;
	float salario;
	
	puts("Informe as seguintes informações:");
	
	printf("Nome: ");
	gets(nome);
	
	printf("Idade: ");
	scanf("%d", &idade);
	
	printf("Salário: R$");
	scanf("%f", &salario);
	
	puts("\nInformações do usuário:");
	
	printf("Nome: %s, Idade: %.2d, Salário: R$%.2f\n\n", nome, idade, salario);
	
	system("pause");
	return 0;
}
