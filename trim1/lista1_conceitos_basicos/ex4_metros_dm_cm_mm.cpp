/*
4. Fazer um programa em C que pergunta um valor em metros e imprime o
correspondente em dec�metros, cent�metros e mil�metros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float m, dm, cm, mm;
	
	printf("Informe um valor em metros: ");
	scanf("%f", &m);
	
	dm = m * 10;
	cm = m * 100;
	mm = m * 1000;
	
	printf("\nDec�metros: %.2f dm\nCent�metros: %.2f cm\nMil�metros: %.2f mm\n\n", dm, cm, mm);
	
	system("pause");
	return 0;
}
