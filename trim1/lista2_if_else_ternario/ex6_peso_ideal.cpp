/*
6. Fa�a um programa que receba a altura e o sexo de uma pessoa e calcule e
mostre seu peso ideal, utilizando as seguintes f�rmulas (em que �h�
corresponde � altura):
	- Homens: (72,7 * h) � 58
	- Mulheres: (62,1 * h) � 44,7
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
		
		printf("\n\nO seu peso ideal � %.2f kg\n\n", peso_ideal);
		
	} else if (sexo == 'M' || sexo == 'm') {
		
		peso_ideal = (62.1 * altura) - 44.7;
		
		printf("\n\nO seu peso ideal � %.2f kg\n\n", peso_ideal);
		
	}
	
	puts("\n\nUps! Voc� informou um caracter inv�lido.\n");
	
	system("pause");
	return 0;
}
