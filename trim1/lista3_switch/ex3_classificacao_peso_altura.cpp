/*
3. Faça um programa que leia a altura e o peso de uma pessoa. De acordo com a
tabela a seguir, verifique e mostre qual a classificação dessa pessoa.

		Altura 								Peso
							Até 60		Acima de 60 e até 90 	Acima de 90
	Menor do que 1,20 		  A					D					G
	1,20-1,70 				  B 				E 					H
	Maior que 1,70 			  C 				F 					I
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int altura, peso;
	
	puts("A respeito de sua altura em metros:\n\n1) Menor do que 1,20\n2) Entre 1,20 e 1,70\n3) Maior que 1,70\n");
	
	printf("Escolha uma opção: ");
	scanf("%d", &altura);
	
	switch (altura) {
		case 1:
			puts("\nE a respeito do seu peso:\n\n1) Até 60kg\n2) Acima de 60kg e até 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma opção: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classificação é: A\n");
					break;
					
				case 2:
					puts("\nA sua classificação é: D\n");
					break;
					
				case 3:
					puts("\nA sua classificação é: G\n");
					break;
					
				default:
					puts("\nUps! Você informou uma opção inválida.\n");
					break;
			}
			break;
			
		case 2:
			puts("\nE a respeito do seu peso:\n\n1) Até 60kg\n2) Acima de 60kg e até 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma opção: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classificação é: B\n");
					break;
					
				case 2:
					puts("\nA sua classificação é: E\n");
					break;
					
				case 3:
					puts("\nA sua classificação é: H\n");
					break;
					
				default:
					puts("\nUps! Você informou uma opção inválida.\n");
					break;
			}
			break;
			
		case 3:
			puts("\nE a respeito do seu peso:\n\n1) Até 60kg\n2) Acima de 60kg e até 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma opção: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classificação é: C\n");
					break;
					
				case 2:
					puts("\nA sua classificação é: F\n");
					break;
					
				case 3:
					puts("\nA sua classificação é: I\n");
					break;
					
				default:
					puts("\nUps! Você informou uma opção inválida.\n");
					break;
			}
			break;
			
		default:
			puts("\nUps! Você informou uma opção inválida.\n");
			break;
	}
	
	system("pause");
	return 0;
}
