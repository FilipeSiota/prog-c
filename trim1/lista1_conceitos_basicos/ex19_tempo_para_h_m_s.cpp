/*
19. Escreva um programa que realize o processo inverso à questão anterior, ou
seja, pergunte qual o tempo transcorrido em um cronômetro medido em
segundos e o transforme em horas, minutos e segundos correspondentes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int h, m, s;
	
	printf("Informe o tempo transcorrido no cronômetro em segundos: ");
	scanf("%d", &s);
	
	h = s / 3600;
	m = (s % 3600) / 60;
	s = (s % 3600) % 60;
	
	printf("\nO tempo informado corresponde a %.2d:%.2d:%.2d\n\n", h, m ,s);
	
	system("pause");
	return 0;
}
