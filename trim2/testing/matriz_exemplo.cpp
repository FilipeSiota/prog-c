/*
Faça um programa em C que armazene as 3 notas de 4 alunos. Após a leitura o programa
deve calcular a nota final com o somatório das três notas. Ao final deve imprimir as
notas e a nota final para cada aluno.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	float notas[4][4];
	
	for (int l = 0; l < 4; l++) {
		
		printf("Aluno %d\n\n", l + 1);
		
		notas[l][3] = 0; // inicializa o somatório de notas do aluno (linha)
		
		for (int c = 0; c < 3; c++) {
			
			printf("Nota %d: ", c + 1);
			scanf("%f", &notas[l][c]);
			
			notas[l][3] += notas[l][c]; // faz o somatório de notas do aluno (linha) na última coluna
			
		}
		
		printf("\n");
		
	}
	
	printf("============================\n\n");
	
	for (int l = 0; l < 4; l++) {
		
		printf("Aluno %d\n", l + 1);
		
		for (int c = 0; c < 3; c++) {
			
			printf("\nNota %d: %.2f", c + 1, notas[l][c]);
			
		}
		
		printf("\nNota final: %.2f\n\n", notas[l][3]);
				
	}
	
	system("pause");
	return 0;
}
