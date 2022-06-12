/* 2. Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura
deve conter o número de matrícula do aluno, seu nome e as notas de três 
provas.
Defina também um tipo para esta estrutura. Agora, escreva um programa que
leia os dados de cinco alunos e os armazena nessa estrutura. Em seguida, exiba 
o nome e as notas do aluno que possui a maior média geral dentre os cinco. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUM_ALUNOS 5
#define NUM_NOTAS 3

typedef struct
{
	char matricula[51];
	char nome[51];
	float notas[NUM_NOTAS];
	
} Aluno;

typedef struct maior_media_geral
{
	float maior_mg;
	int num_aluno;
	
} MMG;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Aluno alunos[NUM_ALUNOS];
	MMG mmg;
	float total_notas, mg;
	int aluno, nota;
	
	for (aluno = 0; aluno < NUM_ALUNOS; aluno++)
	{
		total_notas = 0.0;
		mg = 0.0;
		
		printf("========== ALUNO %d ==========\n\n", aluno + 1);
		
		printf("Número de matrícula: ");
		fflush(stdin);
		scanf("%50[^\n]", alunos[aluno].matricula);
		
		printf("Nome completo......: ");
		fflush(stdin);
		scanf("%50[^\n]", alunos[aluno].nome);
		
		printf("\n");
		
		for (nota = 0; nota < NUM_NOTAS; nota++)
		{
			printf("Nota %d.............: ", nota + 1);
			fflush(stdin);
			scanf("%f", &alunos[aluno].notas[nota]);
			
			total_notas += alunos[aluno].notas[nota];
		}
		
		mg = total_notas / NUM_NOTAS;
		
		printf("\nMédia Geral: %.2f\n", mg);
		
		if (!aluno)
		{
			mmg.maior_mg = mg;
			mmg.num_aluno = aluno;
		}
		else if (mg > mmg.maior_mg)
		{
			mmg.maior_mg = mg;
			mmg.num_aluno = aluno;
		}
		
		printf("\n\n");
	}
	
	printf("========== MAIOR MÉDIA GERAL ==========\n\n");
	
	printf("Nome completo: %s\n\n", alunos[mmg.num_aluno].nome);
	
	for (nota = 0; nota < NUM_NOTAS; nota++)
	{
		printf("Nota %d.......: %.2f\n", nota + 1, alunos[mmg.num_aluno].notas[nota]);
	}
	
	printf("\nMédia Geral: %.2f\n\n", mmg.maior_mg);
	
	system("pause");
	return 0;
}
