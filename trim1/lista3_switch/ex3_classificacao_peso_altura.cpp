/*
3. Fa�a um programa que leia a altura e o peso de uma pessoa. De acordo com a
tabela a seguir, verifique e mostre qual a classifica��o dessa pessoa.

		Altura 								Peso
							At� 60		Acima de 60 e at� 90 	Acima de 90
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
	
	printf("Escolha uma op��o: ");
	scanf("%d", &altura);
	
	switch (altura) {
		case 1:
			puts("\nE a respeito do seu peso:\n\n1) At� 60kg\n2) Acima de 60kg e at� 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma op��o: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classifica��o �: A\n");
					break;
					
				case 2:
					puts("\nA sua classifica��o �: D\n");
					break;
					
				case 3:
					puts("\nA sua classifica��o �: G\n");
					break;
					
				default:
					puts("\nUps! Voc� informou uma op��o inv�lida.\n");
					break;
			}
			break;
			
		case 2:
			puts("\nE a respeito do seu peso:\n\n1) At� 60kg\n2) Acima de 60kg e at� 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma op��o: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classifica��o �: B\n");
					break;
					
				case 2:
					puts("\nA sua classifica��o �: E\n");
					break;
					
				case 3:
					puts("\nA sua classifica��o �: H\n");
					break;
					
				default:
					puts("\nUps! Voc� informou uma op��o inv�lida.\n");
					break;
			}
			break;
			
		case 3:
			puts("\nE a respeito do seu peso:\n\n1) At� 60kg\n2) Acima de 60kg e at� 90kg\n3) Acima de 90kg\n");
			
			printf("Escolha uma op��o: ");
			scanf("%d", &peso);
			
			switch (peso) {
				case 1:
					puts("\nA sua classifica��o �: C\n");
					break;
					
				case 2:
					puts("\nA sua classifica��o �: F\n");
					break;
					
				case 3:
					puts("\nA sua classifica��o �: I\n");
					break;
					
				default:
					puts("\nUps! Voc� informou uma op��o inv�lida.\n");
					break;
			}
			break;
			
		default:
			puts("\nUps! Voc� informou uma op��o inv�lida.\n");
			break;
	}
	
	system("pause");
	return 0;
}
