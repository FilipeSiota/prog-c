/*
3. Fa�a um programa que receba tr�s notas, calcule e mostre a m�dia aritm�tica
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
	
	printf("\nM�dia: %.2f\n\n", media);
	
	system("pause");
	return 0;
}
