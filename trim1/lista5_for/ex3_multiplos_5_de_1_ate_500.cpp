/*
3. Fa�a um programa que imprima os m�ltiplos de 5, no intervalo de 1 at� 500.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	for (int i = 1; i <= 500; i++) {
		
		if (i % 5 == 0) {
			
			printf("%d\n", i);
		}
	}
	
	system("pause");
	return 0;
}
