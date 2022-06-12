/*
9) Fa�a um programa em C que possa armazenar as alturas de dez atletas de cinco
delega��es que participar�o dos jogos de ver�o. Imprimir a maior altura de cada 
delega��o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int ATLETAS = 10, PAISES = 5;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float altura[ATLETAS][PAISES], maiorAlt[PAISES];
	
	printf("JOGOS DE VER�O 2021\n");
	
	printf("\n=====================================\n\n");
	
	for (int j = 0; j < PAISES; j++)
	{
		printf("DELEGA��O %d\n\n", j + 1);
		
		for (int i = 0; i < ATLETAS; i++)
		{	
			printf("Altura do atleta %d (em metros): ", i + 1);
			scanf("%f", &altura[i][j]);
			
			if (!i)
			{
				maiorAlt[j] = altura[i][j];
			}
			else if (altura[i][j] > maiorAlt[j])
			{
				maiorAlt[j] = altura[i][j];
			}
		}
		
		printf("\n=====================================\n\n");
	}
	
	for (int j = 0; j < PAISES; j++)
	{
		printf("A maior altura da delega��o %d: %.2f m\n", j + 1, maiorAlt[j]);
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
