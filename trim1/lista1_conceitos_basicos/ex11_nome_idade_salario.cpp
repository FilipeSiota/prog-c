/*
11. Crie um programa que leia o nome, idade e sal�rio de uma pessoa e logo ap�s
mostre na tela os 3 valores na mesma linha, no formato �Nome: �, Idade: �,
Sal�rio: ...�
	� Antes, informe ao usu�rio que ele precisar� digitar essas 3 informa��es
	� A idade deve ser mostrada com pelo menos 2 d�gitos, completados com 0
	� O sal�rio deve ser mostrado com 2 casas decimais e pelo menos 1 d�gito
	� esquerda completado com zero
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[50];
	int idade;
	float salario;
	
	puts("Informe as seguintes informa��es:");
	
	printf("Nome: ");
	gets(nome);
	
	printf("Idade: ");
	scanf("%d", &idade);
	
	printf("Sal�rio: R$");
	scanf("%f", &salario);
	
	puts("\nInforma��es do usu�rio:");
	
	printf("Nome: %s, Idade: %.2d, Sal�rio: R$%.2f\n\n", nome, idade, salario);
	
	system("pause");
	return 0;
}
