/* 2) Fa�a um programa que receba as notas de tr�s provas e calcule a m�dia. Para o c�lculo, 
escreva uma fun��o. O programa deve imprimir a m�dia ao final. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculaMedia(float notas[], int quant_notas);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float mediaFinal;
	int grade, num_grades;
	
	printf("Informe a quantidade de notas que voc� deseja inserir: ");
	scanf("%d", &num_grades);
	
	// DECLARA��O DE ARRAY COM COMPRIMENTO VARI�VEL
	float grades[num_grades];
	
	printf("\n");
	
	for (grade = 0; grade < num_grades; grade++)
	{
		printf("Insira a nota %d: ", grade + 1);
		scanf("%f", &grades[grade]);
	}
	
	mediaFinal = calculaMedia(grades, num_grades);
	
	printf("\nM�dia final: %.2f\n\n", mediaFinal);
	
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
