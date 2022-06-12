#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float num, raiz;
	
	printf("Informe um numero: ");
	scanf("%f", &num);
	
	raiz = sqrt(num);
	
	printf("\nA raiz quadrada desse numero = %.2f\n\n", raiz);
	
	system("pause");
	return 0;
}
