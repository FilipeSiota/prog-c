/*
8) Fa�a um programa que leia um vetor de 10 elementos e gere um vetor cujos
componentes s�o os fatoriais dos respectivos componentes de vet.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 10;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM];
	unsigned long int fatorial[TAM] = { };
	
	printf("########## Fatorial de um n�mero ##########\n\n");
	
	printf("*Informe apenas n�meros inteiros positivos!!\n\n");
	
	for (int i = 0; i < TAM; i++) {
		
		do {
			
			printf("Informe o %d� n�mero: ", i + 1);
			scanf("%d", &vet[i]);
			fflush(stdin);
			
			if (vet[i] <= 0) {
				
				printf("\nUps! Valor inv�lido. Tente digitar um n�mero inteiro maior que 0.\n");
				
			}
			
		} while (vet[i] <= 0);
		
		for (int num = vet[i]; num >= 1; num--) { // j� faz fatorial do n�mero informado
			
			if (num == vet[i]) { // se for a primeira repeti��o, o valor inicial de fatorial[i] vai ser o pr�prio valor informado pelo usu�rio
				
				fatorial[i] = num;
				
			} else {
				
				fatorial[i] *= num;
				
			}
			
		}
		
	}
	
	printf("\n########## Resultados ##########\n");
	
	printf("\nN�mero\tFatorial\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("%4d\t%d\n", vet[i], fatorial[i]);
		
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
