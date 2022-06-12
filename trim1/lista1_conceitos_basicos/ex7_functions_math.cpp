/*
7. Fazer um programa em "C" que solicite 2 n�meros e informe:
	a) A soma dos n�meros;
	b) O produto do primeiro n�mero pelo quadrado do segundo;
	c) O quadrado do primeiro n�mero;
	d) A raiz quadrada da soma dos quadrados;
	e) O seno da diferen�a do primeiro n�mero pelo segundo;
	f) O m�dulo do primeiro n�mero.
*/

#include <stdio.h>
#include <stdlib.h> // abs() para saber o m�dulo de um n�mero
#include <locale.h>
#include <math.h> // biblioteca para fun��es matem�ticas - retorna valor do tipo double

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float num1, num2;
	float a, b, c, d, e, f;
	
	printf("Informe dois n�meros separados por espa�o: ");
	scanf("%f %f", &num1, &num2);
	
	a = num1 + num2;
	b = num1 * pow(num2, 2);
	c = pow(num1, 2);
	d = sqrt(pow(num1, 2) + pow(num2, 2));
	e = sin(num1 - num2);
	//f = abs(num1); //retorna um valor do tipo inteiro, n�o atendendo aos n�meros com parte fracion�ria
	f = num1 < 0.0 ? num1 * -1.0 : num1; //usando operadores tern�rios <?> e <:>
	
	printf("\na) A soma dos n�meros � %.2f", a);
	printf("\nb) O produto do primeiro n�mero pelo quadrado do segundo � %.2f", b);
	printf("\nc) O quadrado do primeiro n�mero � %.2f", c);
	printf("\nd) A raiz quadrada da soma dos quadrados � %.2f", d);
	printf("\ne) O seno da diferen�a do primeiro n�mero pelo segundo � %.2f", e);
	printf("\nf) O m�dulo do primeiro n�mero � %.2f\n\n", f);
	
	system("pause");
	return 0;
}
