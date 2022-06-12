/*
4. Fa�a um programa que leia o sal�rio de um trabalhador e o valor da presta��o
de um empr�stimo. Se a presta��o:
	- For maior que 20% do sal�rio, imprima: �Empr�stimo n�o concedido�.
	- Caso contr�rio, imprima: �Empr�stimo concedido�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float salario, prestacao;
	
	printf("Informe seu sal�rio: R$");
	scanf("%f", &salario);
	
	printf("Informe o valor da presta��o do seu de empr�stimo: R$");
	scanf("%f", &prestacao);
	
	if ( prestacao > (0.2 * salario) ) {
		
		puts("\nEmpr�stimo n�o concedido.\n");
		
	} else {
		
		puts("\nEmpr�stimo concedido.\n");
		
	}
	
	system("pause");
}
