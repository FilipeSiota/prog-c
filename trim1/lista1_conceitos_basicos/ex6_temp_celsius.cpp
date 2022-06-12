/*
6. Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e
imprime no vídeo o correspondente em graus Celsius usando as fórmulas que
seguem.
	a) Usar uma variável double para ler o valor em Fahrenheit e a fórmula C=(f-32.0) * (5.0/9.0).
	b) Usar uma variável int para ler o valor em Fahrenheit e a fórmula C=(f-32)*(5/9).
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
	
	temp = plusTemp; // pega somente a parte inteira do valor que está na variável do tipo double
	
	celsius = (temp - 32) * 5 / 9; // divisão de inteiros pega apenas o quociente inteiro, que neste caso é zero, resultando em 0°C sempre, por isso, não colocar entre parenteses
	plusCelsius = (plusTemp - 32.0) * (5.0 / 9.0);
	
	printf("\nTemperatura precisa: %.3lf°C\nTemperatura aproximada: %d°C\n\n", plusCelsius, celsius);
	
	system("pause");
	return 0;
}
