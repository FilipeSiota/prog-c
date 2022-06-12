/*
1. Escreva um programa que mostre o tamanho em byte que cada tipo de dados
ocupa na memória: char, int, float, double.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Tamanho em byte que cada tipo de dados ocupa na memoria:\n");
	
	printf("\n\tchar = %d", sizeof(char));
	printf("\n\tint = %d", sizeof(int));
	printf("\n\tfloat = %d", sizeof(float));
	printf("\n\tdouble = %d\n\n", sizeof(double));
	
	system("pause");
	return 0;
}
