/*
2. Fa�a um programa que imprima todos os n�meros pares de 100 at� 1.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	for (int i = 100; i >= 1; i--) {
		
		if (i % 2 == 0) {
			
			printf("%d\n", i);
			
		}
		
	}
	
	system("pause");
	return 0;
}
