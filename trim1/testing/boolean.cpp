#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // biblioteca para variáveis booleanas

int main() {
	bool a = true, b = false;
	
	if (a) { // se a == true
		
		puts("A eh verdadeiro.\n");
		
	} else {
		
		puts("A eh falso.\n");
		
	}
	
	if (!b) { // se b != true ou b == false ou (nao b)
		
		puts("B eh falso.\n");
		
	} else {
		
		puts("B eh verdadeiro.\n");
		
	}
	
	system("pause");
	return 0;
}
