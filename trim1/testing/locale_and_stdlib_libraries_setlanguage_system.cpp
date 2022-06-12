#include <stdio.h>
#include <stdlib.h> // para limpar a tela <cls> ou pausar a tela do terminal <pause> 
#include <locale.h> // para usar acentos e caracteres especiais

int main (void) {
	setlocale(LC_ALL, "Portuguese");
	
	printf("Utilizando caracteres e acentuação da língua portuguesa.\n\n");
	
	system("pause");
	system("cls");
}
