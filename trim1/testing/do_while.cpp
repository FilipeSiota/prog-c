/* Exerc�cio exemplo 4
Fa�a um programa em linguagem C que permita entrar com n�meros e imprimir o quadrado de
cada n�mero digitado at� entrar um n�mero m�ltiplo de 6 que dever� ter seu quadrado
impresso tamb�m. */

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
