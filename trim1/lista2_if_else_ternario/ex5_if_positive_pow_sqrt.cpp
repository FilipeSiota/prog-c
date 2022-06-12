/*
5. Faça um programa que leia um número e, caso ele seja positivo, calcule e
mostre:
	- O número digitado ao quadrado.
	- A raiz quadrada do número digitado
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num, pot;
	float raiz;
	
	printf("Informe um número: ");
	scanf("%d", &num);
	
	if (num > 0) {
		
		pot = pow(num, 2.0);
		raiz = sqrt(num);
		
		printf("\nO quadrado de %d é: %d", num, pot);
		printf("\nA raiz quadrada de %d é: %f\n\n", num, raiz);
		
	} else {
		
		puts("\nO número informado não é positivo.\n");
		
	}
	
	system("pause");
	return 0;
}
