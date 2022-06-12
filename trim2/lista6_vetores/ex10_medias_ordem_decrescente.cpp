/*
10) Faça um programa que leia a matrícula e a média de 100 alunos. Ordene da maior
para a menor nota e imprima uma relação contendo todas as matrículas e médias.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 100

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char matricula[TAM][50], auxMatricula[50];
	float media[TAM], auxMedia;
	
	printf("########## Cadastrando médias ##########\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("\nALUNO %d:\n\n", i + 1);
		
		printf("Informe a matrícula: ");
		gets(matricula[i]);
		fflush(stdin);
		
		printf("Informe a média: ");
		scanf("%f", &media[i]);
		fflush(stdin);
	}
	
	// Bubble Sort (organizando em ordem decrescente)
	
	for (int rep = 0; rep < TAM - 1; rep++) {
		
		for (int i = 0; i < TAM - rep; i++) {
			
			if (media[i] < media [i + 1]) {
				
				// media
				auxMedia = media[i];
				media[i] = media[i + 1];
				media[i + 1] = auxMedia;
				
				// matricula
				strcpy(auxMatricula, matricula[i]);
				strcpy(matricula[i], matricula[i + 1]);
				strcpy(matricula[i + 1], auxMatricula);
				
			}
			
		}
		
	}
	
	printf("\n\n########## Relatório das médias ##########\n\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Matrícula: %s", matricula[i]);
		
		printf("\nMédia: %.2f\n", media[i]);
		
		printf("\n========================================\n\n");
		
	}
	
	system("pause");
	return 0;
}
