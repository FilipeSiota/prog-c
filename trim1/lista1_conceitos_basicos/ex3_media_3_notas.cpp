/*
3. Faça um programa que receba três notas, calcule e mostre a média aritmética
entre elas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float grade[3], media;
	
	for (int i = 0; i < 3; i++) {
		printf("Nota %d: ", i+1);
		scanf("%f", &grade[i]);
		
		media += grade[i];
	}
	
	media /= 3.0;
	
	printf("\nMédia: %.2f\n\n", media);
	
	system("pause");
	return 0;
}
