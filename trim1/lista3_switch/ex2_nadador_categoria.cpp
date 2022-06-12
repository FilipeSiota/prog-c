/*
2. Escreva um programa que, dada a idade de um nadador, o classifique em uma
das seguintes categorias:
	Categoria 		Idade
	Infantil A 		5-7
	Infantil B 		8-10
	Juvenil A 		11-13
	Juvenil B 		14-17
	S�nior 			Maiores de 18 anos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int idade;
	
	puts("Ol�! Ent�o � voc� o(a) futuro(a) medalhista Ol�mpico(a) da nata��o!\n\nPreciso que me informe a op��o na qual sua idade est� contida, assim posso te classificar em uma das categorias.\n");
	
	puts("1) 5 a 7 anos\n2) 8 a 10 anos\n3) 11 a 13 anos\n4) 14 a 17 anos\n5) Maior de 18 anos\n");
	
	printf("Op��o: ");
	scanf("%d", &idade);
	
	switch (idade) {
		case 1:
			puts("\nMuito bem nadador(a)! Identifiquei que voc� � da categoria: Infantil A\n");
			break;
			
		case 2:
			puts("\nMuito bem nadador(a)! Identifiquei que voc� � da categoria: Infantil B\n");
			break;
			
		case 3:
			puts("\nMuito bem nadador(a)! Identifiquei que voc� � da categoria: Juvenil A\n");
			break;
		
		case 4:
			puts("\nMuito bem nadador(a)! Identifiquei que voc� � da categoria: Juvenil B\n");
			break;
			
		case 5:
			puts("\nMuito bem nadador(a)! Identifiquei que voc� � da categoria: Senior\n");
			break;
			
		default:
			puts("\nUps! Voc� informou uma op��o inv�lida.\n");
	}
	
	system("pause");
	return 0;
}
