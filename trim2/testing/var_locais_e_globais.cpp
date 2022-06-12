#include <stdio.h>
#include <stdlib.h>

float vbase, valtura;

float areaRetangulo();
float areaTriangulo();

int main()
{
	float vareaRet, vareaTri;
	
	printf("Informe a base do retangulo: ");
	scanf("%f", &vbase);
	
	printf("Informe a altura do retangulo: ");
	scanf("%f", &valtura);
	
	vareaRet = areaRetangulo();
	vareaTri = areaTriangulo();
	
	printf("\nA area do retangulo e: %.2f\n", vareaRet);
	printf("A area do triangulo e: %.2f\n\n", vareaTri);
	
	system("pause");
	return 0;
}

float areaRetangulo() {
	float area = vbase * valtura;
	return area;
}

float areaTriangulo() {
	float area = areaRetangulo() / 2;
	return area;
}

