/*
5. Crie um programa em linguagem C que permita entrar com o nome, a nota da
prova 1 e da prova 2 de 15 alunos. Ao final, imprimir uma listagem, contendo:
nome, nota da prova 1, nota da prova 2, e média das notas de cada aluno. Ao
final, imprimir a média geral da turma.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int ALUNOS = 4;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[ALUNOS][100];
	float nota1[ALUNOS], nota2[ALUNOS], media[ALUNOS], somaTot = 0, mediaTot;
	
	for (int i = 0; i < ALUNOS; i++) {
		
		printf("Nome: ");
		fflush(stdin); // limpar o BUFFER do teclado
		fgets(nome[i], 100, stdin);
		
		printf("Nota 1: ");
		scanf("%f", &nota1[i]);
		
		printf("Nota 2: ");
		scanf("%f", &nota2[i]);
		
		media[i] = (nota1[i] + nota2[i]) / 2.0;
		
		somaTot += media[i];
		
		printf("\n=======================================\n\n");
	}
	
	system("cls");
	
	for (int i = 0; i < ALUNOS; i++) {
		
		printf("=============== Aluno %d ===============\n\n", i + 1);
		
		printf("Nome: %s\nNota 1: %.2f\nNota 2: %.2f\n\nMédia: %.2f\n\n", nome[i], nota1[i], nota2[i], media[i]);
		
	}
	
	mediaTot = somaTot / ALUNOS;
	
	printf("=======================================\n\n");
	
	printf("Média geral da turma: %.2f\n\n", mediaTot);
	
	system("pause");
	return 0;
}
