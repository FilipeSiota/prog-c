/* Fa�a um programa em C que calcule a �rea de um ret�ngulo, para isso o programa deve
ler a altura e a base. O c�lculo deve ser feito em uma fun��o. Ap�s calcular o programa
deve imprimir o valor da �rea do ret�ngulo. */

#include <stdio.h>
#include <stdlib.h>

float areaRect(float base, float altura)
{
	float area = base * altura;
	
	return area;
}

int main()
{
	float vbase, valtura, varea;
	
	printf("Informe o valor da base do retangulo: ");
	scanf("%f", &vbase);
	
	printf("Informe o valor da altura do retangulo: ");
	scanf("%f", &valtura);
	
	varea = areaRect(vbase, valtura);
	
	printf("\nArea do retangulo = %.2f\n\n", varea);
	
	system("pause");
	return 0;
}
