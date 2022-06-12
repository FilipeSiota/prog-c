#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float base, exp, pot;
	
	printf("Informe a base: ");
	scanf("%f", &base);
	
	printf("Informe o expoente: ");
	scanf("%f", &exp);
	
	pot = pow(base, exp);
	
	printf("\n%.0f elevado a %.0f = %.2f\n\n", base, exp, pot);
	
	system("pause");
	return 0;
}
