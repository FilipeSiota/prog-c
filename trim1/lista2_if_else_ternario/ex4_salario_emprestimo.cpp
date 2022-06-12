/*
4. Faça um programa que leia o salário de um trabalhador e o valor da prestação
de um empréstimo. Se a prestação:
	- For maior que 20% do salário, imprima: “Empréstimo não concedido”.
	- Caso contrário, imprima: “Empréstimo concedido”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float salario, prestacao;
	
	printf("Informe seu salário: R$");
	scanf("%f", &salario);
	
	printf("Informe o valor da prestação do seu de empréstimo: R$");
	scanf("%f", &prestacao);
	
	if ( prestacao > (0.2 * salario) ) {
		
		puts("\nEmpréstimo não concedido.\n");
		
	} else {
		
		puts("\nEmpréstimo concedido.\n");
		
	}
	
	system("pause");
}
