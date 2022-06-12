/* Exercício exemplo 4
Faça um programa em linguagem C que permita entrar com números e imprimir o quadrado de
cada número digitado até entrar um número múltiplo de 6 que deverá ter seu quadrado
impresso também. */

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int num;
	
	do {
		
		printf("Informe um numero qualquer ou um multiplo de 6 para encerrar o programa: ");
		scanf("%d", &num);
		
		printf("\n%d ao quadrado = %d.\n\n", num, num*num);
		
	} while (num % 6 != 0);
	
	system("pause");
	return 0;
}
