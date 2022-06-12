/* 9) Fa�a um programa que leia os catetos (dois catetos) de um tri�ngulo ret�ngulo e
imprima a hipotenusa. Para fazer o c�lculo, implemente uma fun��o. Utilize a f�rmula a 
seguir:
	hipotenusa = raiz(cateto1^2 + cateto2^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float calculaHipotenusa(float cateto1, float cateto2);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float hipo, cat1, cat2;
	
	printf("========================================\n");
	printf("          CALCULA A HIPOTENUSA          \n");
	printf("========================================\n");
	
	printf("\nInforme o cateto 1: ");
	scanf("%f", &cat1);
	
	printf("Informe o cateto 2: ");
	scanf("%f", &cat2);
	
	hipo = calculaHipotenusa(cat1, cat2);
	
	printf("\nA hipotenusa � igual a %.2f.\n\n", hipo);
	
	system("pause");
	return 0;
}

float calculaHipotenusa(float cateto1, float cateto2)
{
	float hipotenusa;
	
	hipotenusa = sqrt( pow(cateto1, 2) + pow(cateto2, 2) );
	
	return hipotenusa;
}
