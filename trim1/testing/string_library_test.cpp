#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nomeCompleto[22] = "Filipe Mallmann Siota";
	char nome[7];
	
	strncpy(nome, nomeCompleto, 6);
	
	printf("Nome completo: %s\nNome: %s\n\n", nomeCompleto, nome);
	
	system("pause");
	return 0;
}
