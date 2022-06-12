#include <stdio.h>
#include <string.h>
#include <conio.h>

main() { // main sem ser inteiro
	char nome[22];
	int tam;
	
	fgets(nome, 22, stdin); // usando fgets para pegar o valor da string
	
	tam = strlen(nome);
	
	printf("A string -> %s\nPossui um tamanho de %d\n", nome, tam);
	
	getch();
	return 0;
}
