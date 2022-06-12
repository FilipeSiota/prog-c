#include <stdio.h>

int main() {
	char nome[100];
	int idade;
	float salario;
	
	printf("Digite seu nome: ");
	gets(nome);
	
	printf("Digite sua idade: ");
	scanf("%d", &idade);
	
	printf("Digite seu salario: ");
	scanf("%f", &salario);
	
	printf("Nome: %s\nIdade: %d\nSalario: %.2f", nome, idade, salario);
}
