/*
18. Escreva um programa que pergunte qual o tempo transcorrido em um
cronômetro em horas, minutos e segundos e transforme (e mostre) todo este
tempo em segundos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int h, m, s, totalSec;
	
	printf("Informe o tempo transcorrido em um cronômetro (h:m:s): ");
	scanf("%d:%d:%d", &h, &m, &s);
	
	totalSec = s + 60 * m + 3600 * h;
	
	printf("\nO tempo informado corresponde a %d segundos.\n\n", totalSec);
	
	system("pause");
	return 0;
}
