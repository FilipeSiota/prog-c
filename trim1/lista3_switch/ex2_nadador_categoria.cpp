/*
2. Escreva um programa que, dada a idade de um nadador, o classifique em uma
das seguintes categorias:
	Categoria 		Idade
	Infantil A 		5-7
	Infantil B 		8-10
	Juvenil A 		11-13
	Juvenil B 		14-17
	Sênior 			Maiores de 18 anos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int idade;
	
	puts("Olá! Então é você o(a) futuro(a) medalhista Olímpico(a) da natação!\n\nPreciso que me informe a opção na qual sua idade está contida, assim posso te classificar em uma das categorias.\n");
	
	puts("1) 5 a 7 anos\n2) 8 a 10 anos\n3) 11 a 13 anos\n4) 14 a 17 anos\n5) Maior de 18 anos\n");
	
	printf("Opção: ");
	scanf("%d", &idade);
	
	switch (idade) {
		case 1:
			puts("\nMuito bem nadador(a)! Identifiquei que você é da categoria: Infantil A\n");
			break;
			
		case 2:
			puts("\nMuito bem nadador(a)! Identifiquei que você é da categoria: Infantil B\n");
			break;
			
		case 3:
			puts("\nMuito bem nadador(a)! Identifiquei que você é da categoria: Juvenil A\n");
			break;
		
		case 4:
			puts("\nMuito bem nadador(a)! Identifiquei que você é da categoria: Juvenil B\n");
			break;
			
		case 5:
			puts("\nMuito bem nadador(a)! Identifiquei que você é da categoria: Senior\n");
			break;
			
		default:
			puts("\nUps! Você informou uma opção inválida.\n");
	}
	
	system("pause");
	return 0;
}
