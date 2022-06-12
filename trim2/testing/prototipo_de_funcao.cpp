#include <stdio.h>
#include <stdlib.h>

float areaRetangulo(float base, float altura);
float areaTriangulo(float base, float altura);

int main()
{
	float vbase, valtura, vareaRet, vareaTri;
	
	printf("Informe a base do retangulo: ");
	scanf("%f", &vbase);
	
	printf("Informe a altura do retangulo: ");
	scanf("%f", &valtura);
	
	vareaRet = areaRetangulo(vbase, valtura);
	vareaTri = areaTriangulo(vbase, valtura);
	
	printf("\nA area do retangulo e: %.2f\n", vareaRet);
	printf("A area do triangulo e: %.2f\n\n", vareaTri);
	
	system("pause");
	return 0;
}

float areaRetangulo(float base, float altura) {
	float area = base * altura;
	return area;
}

float areaTriangulo(float base, float altura) {
	float area = areaRetangulo(base, altura) / 2;
	return area;
}
