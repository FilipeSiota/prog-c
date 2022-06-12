/*
7. Fazer um programa em "C" que solicite 2 números e informe:
	a) A soma dos números;
	b) O produto do primeiro número pelo quadrado do segundo;
	c) O quadrado do primeiro número;
	d) A raiz quadrada da soma dos quadrados;
	e) O seno da diferença do primeiro número pelo segundo;
	f) O módulo do primeiro número.
*/

#include <stdio.h>
#include <stdlib.h> // abs() para saber o módulo de um número
#include <locale.h>
#include <math.h> // biblioteca para funções matemáticas - retorna valor do tipo double

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float num1, num2;
	float a, b, c, d, e, f;
	
	printf("Informe dois números separados por espaço: ");
	scanf("%f %f", &num1, &num2);
	
	a = num1 + num2;
	b = num1 * pow(num2, 2);
	c = pow(num1, 2);
	d = sqrt(pow(num1, 2) + pow(num2, 2));
	e = sin(num1 - num2);
	//f = abs(num1); //retorna um valor do tipo inteiro, não atendendo aos números com parte fracionária
	f = num1 < 0.0 ? num1 * -1.0 : num1; //usando operadores ternários <?> e <:>
	
	printf("\na) A soma dos números é %.2f", a);
	printf("\nb) O produto do primeiro número pelo quadrado do segundo é %.2f", b);
	printf("\nc) O quadrado do primeiro número é %.2f", c);
	printf("\nd) A raiz quadrada da soma dos quadrados é %.2f", d);
	printf("\ne) O seno da diferença do primeiro número pelo segundo é %.2f", e);
	printf("\nf) O módulo do primeiro número é %.2f\n\n", f);
	
	system("pause");
	return 0;
}
