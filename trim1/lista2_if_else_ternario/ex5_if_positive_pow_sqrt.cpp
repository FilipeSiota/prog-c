/*
5. Fa�a um programa que leia um n�mero e, caso ele seja positivo, calcule e
mostre:
	- O n�mero digitado ao quadrado.
	- A raiz quadrada do n�mero digitado
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num, pot;
	float raiz;
	
	printf("Informe um n�mero: ");
	scanf("%d", &num);
	
	if (num > 0) {
		
		pot = pow(num, 2.0);
		raiz = sqrt(num);
		
		printf("\nO quadrado de %d �: %d", num, pot);
		printf("\nA raiz quadrada de %d �: %f\n\n", num, raiz);
		
	} else {
		
		puts("\nO n�mero informado n�o � positivo.\n");
		
	}
	
	system("pause");
	return 0;
}
