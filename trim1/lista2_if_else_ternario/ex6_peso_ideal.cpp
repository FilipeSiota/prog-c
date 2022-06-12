/*
6. Faça um programa que receba a altura e o sexo de uma pessoa e calcule e
mostre seu peso ideal, utilizando as seguintes fórmulas (em que “h”
corresponde à altura):
	- Homens: (72,7 * h) – 58
	- Mulheres: (62,1 * h) – 44,7
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float altura, peso_ideal;
	char sexo;
	
	printf("Informe sua altura em metros: ");
	scanf("%f", &altura);
	
	printf("Informe seu sexo (H para Homem ou M para Mulher): ");
	sexo = getche();
	
	if (sexo == 'H' || sexo == 'h') {
		
		peso_ideal = (72.7 * altura) - 58.0;
		
		printf("\n\nO seu peso ideal é %.2f kg\n\n", peso_ideal);
		
	} else if (sexo == 'M' || sexo == 'm') {
		
		peso_ideal = (62.1 * altura) - 44.7;
		
		printf("\n\nO seu peso ideal é %.2f kg\n\n", peso_ideal);
		
	}
	
	puts("\n\nUps! Você informou um caracter inválido.\n");
	
	system("pause");
	return 0;
}
