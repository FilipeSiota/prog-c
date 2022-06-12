/*
16. Fa�a um programa que calcule a quantidade necess�ria de latas de tinta para
pintar uma parede. O programa pergunta a medidas de largura e altura da
parede em metros e imprime o resultado (em latas de tinta).
	- Considere que o consumo de tinta � de 300 ml por metro quadrado e a
	quantidade de tinta por lata � de 2 litros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float height, width, area, ink;
	int cans;
	
	puts("Dimens�es da parede:\n");
	
	printf("Altura em metros (m): ");
	scanf("%f", &height);
	
	printf("Largura em metros (m): ");
	scanf("%f", &width);
	
	area = height * width;
	ink = 0.3 * area; // quantidade de tinta que ser� usada
	cans = ink / 2.0 > abs(ink / 2.0) ? ink / 2.0 + 1.0 : ink / 2.0;
	// Se a quantidade de latas (float) for maior que o m�dulo do seu n�mero (int), ent�o quantidade + 1, sen�o quantidade
	
	printf("\nQuantidade de tinta utilizada: %.2f litros", ink);
	printf("\nTotal de latas de tinta necess�rios: %d\n\n", cans);
	
	system("pause");
	return 0;
}
