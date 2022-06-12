/*
12. Escreva programas em C para calcular o IMC (Índice de Massa Corpórea) a
partir da entrada de dados pelo usuário --> IMC = Peso ÷ (Altura × Altura)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const char PROGRAMA[46] = "Calculadora de IMC (Índice de Massa Corpórea)";

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float peso, altura, imc;
	
	printf("%s\n", PROGRAMA);
	
	printf("\nInforme seu peso em quilogramas (kg): ");
	scanf("%f", &peso);
	
	printf("Informe sua altura em metros (m): ");
	scanf("%f", &altura);
	
	imc = peso / (altura * altura);
	
	printf("\nSeu IMC é: %.2f\n\n", imc);
	
	system("pause");
	return 0;
}
