//Faça um programa em C que realize a soma de todos os valores inteiros de 1 a n, sendo que n
//deve ser informado pelo usuário.

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, i = 1, soma = 0;
	
	printf("Informe um numero inteiro: ");
	scanf("%d", &n);
	
	while (i <= n) {
		
		soma += i++;
		
	}
	
	printf("\nA soma dos numeros de 1 a %d = %d\n\n", n, soma);
	
	system("pause");
	return 0;
}
