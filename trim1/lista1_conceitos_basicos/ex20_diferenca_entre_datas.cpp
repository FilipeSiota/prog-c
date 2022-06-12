/*
20. Considerando um calendário hipotético onde os 12 meses do ano possuam
exatamente 30 dias cada um. Escreva um programa que solicite duas datas onde:
o dia da segunda é maior ou igual a primeira, o mês da segunda é maior ou igual a
primeira, o ano da segunda é maior ou igual a primeira; e imprima:
	a) a diferença total de anos entre as duas datas;
	b) a diferença total de meses entre as duas datas;
	c) a diferença total de dias entre as duas datas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int y1, m1, d1, y2, m2, d2, yDif, mDif, dDif;
	float auxY, auxM;
	
	printf("Informe a 1ª data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &d1, &m1, &y1);
	
	do {
		printf("Informe a 2ª data (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &d2, &m2, &y2);
		
		if (d2 < d1 || m2 < m1 || y2 < y1) {
			system("cls"); // limpar a tela do terminal
		
			printf("Data inserida: %.2d/%.2d/%.2d\n", d2, m2, y2);
			printf("\nA 2ª data deve atender aos seguintes requisitos:\n\t- O dia da segunda é maior ou igual a primeira;\n\t- O mês da segunda é maior ou igual a primeira;\n\t- O ano da segunda é maior ou igual a primeira.\n\n");	
			
			printf("Informe a 1ª data (dd/mm/aaaa): %.2d/%.2d/%.2d\n", d1, m1, y1);
		}
	} while (d2 < d1 || m2 < m1 || y2 < y1);
	
	dDif = d2 - d1;
	mDif = m2 - m1;
	yDif = y2 - y1;
	
	printf("\nA diferença entre as datas é de %d anos, %d meses e %d dias.\n", yDif, mDif, dDif);
	
	dDif += mDif * 30 + yDif * 365;
	auxM = dDif / 30.0;
	auxY = dDif / 365.0;
	
	printf("\nAlém disso, foi calculada diferença entre as duas datas em:\nAnos: %.2f\nMeses: %.2f\nDias: %d\n\n", auxY, auxM, dDif);
	
	system("pause");
	return 0;
}
