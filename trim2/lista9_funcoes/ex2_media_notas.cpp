/* 2) Faça um programa que receba as notas de três provas e calcule a média. Para o cálculo, 
escreva uma função. O programa deve imprimir a média ao final. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculaMedia(float notas[], int quant_notas);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float mediaFinal;
	int grade, num_grades;
	
	printf("Informe a quantidade de notas que você deseja inserir: ");
	scanf("%d", &num_grades);
	
	// DECLARAÇÃO DE ARRAY COM COMPRIMENTO VARIÁVEL
	float grades[num_grades];
	
	printf("\n");
	
	for (grade = 0; grade < num_grades; grade++)
	{
		printf("Insira a nota %d: ", grade + 1);
		scanf("%f", &grades[grade]);
	}
	
	mediaFinal = calculaMedia(grades, num_grades);
	
	printf("\nMédia final: %.2f\n\n", mediaFinal);
	
	system("pause");
	return 0;
}

float calculaMedia(float notas[], int quant_notas)
{
	int nota;
	float media = 0;
	
	for (nota = 0; nota < quant_notas; nota++)
	{
		media += notas[nota];
	}
	
	media /= quant_notas;
	
	return media;
}
