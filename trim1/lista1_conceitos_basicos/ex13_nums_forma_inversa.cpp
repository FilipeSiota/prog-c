/*
13. Escreva um programa que leia tr�s n�meros e os imprima na ordem inversa da
que foram digitados.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int nums[3];
	
	for (int i = 0; i < 3; i++) {
		printf("Digite o %d� n�mero inteiro: ", i+1);
		scanf("%d", &nums[i]);
	}
	
	for (int i = 2; i >= 0; i--) {
		printf("\n%d� n�mero digitado: %d", i+1, nums[i]);
	}
	
	getch();
	return 0;
}
