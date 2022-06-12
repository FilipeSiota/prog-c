/* Faça um programa em C que calcule a área de um retângulo, para isso o programa deve
ler a altura e a base. O cálculo deve ser feito em uma função. Após calcular o programa
deve imprimir o valor da área do retângulo. */

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
