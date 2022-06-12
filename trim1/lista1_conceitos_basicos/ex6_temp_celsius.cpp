/*
6. Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e
imprime no v�deo o correspondente em graus Celsius usando as f�rmulas que
seguem.
	a) Usar uma vari�vel double para ler o valor em Fahrenheit e a f�rmula C=(f-32.0) * (5.0/9.0).
	b) Usar uma vari�vel int para ler o valor em Fahrenheit e a f�rmula C=(f-32)*(5/9).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	double plusTemp, plusCelsius;
	int temp, celsius;
	
	printf("Informe a temperatura em graus Fahrenheit: ");
	scanf("%lf", &plusTemp);
	
	temp = plusTemp; // pega somente a parte inteira do valor que est� na vari�vel do tipo double
	
	celsius = (temp - 32) * 5 / 9; // divis�o de inteiros pega apenas o quociente inteiro, que neste caso � zero, resultando em 0�C sempre, por isso, n�o colocar entre parenteses
	plusCelsius = (plusTemp - 32.0) * (5.0 / 9.0);
	
	printf("\nTemperatura precisa: %.3lf�C\nTemperatura aproximada: %d�C\n\n", plusCelsius, celsius);
	
	system("pause");
	return 0;
}
