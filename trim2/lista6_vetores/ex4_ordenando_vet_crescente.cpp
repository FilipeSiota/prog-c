/*
4) Receba um vetor de 6 posições com números inteiros, e mostre esse vetor com os
números ordenados em forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 6;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet[TAM], aux;
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe o %d° número: ", i + 1);
		scanf("%d", &vet[i]);
		
	}
	
	/*
	Algoritmo Bubble Sort
	
	Basicamente, ele compara o valor da posição atual do vetor com o valor da próxima posição,
	caso for maior, o valor da posição atual passa a ser o valor da próxima posição e vice-versa
	(utiliza-se uma variável auxiliar para tal). Dessa forma, sabemos que cada vez que o vetor for
	percorrido, ele se ordenará aos poucos de forma crescente. O número de vezes que o vetor terá que
	ser percorrido para que a ordenação esteja completa é o tamanho do vetor menos uma unidade (TAM - 1),
	pois não é necessário percorrer apenas a primeira posição do vetor, por isso o menos 1.
	
	O algoritmo coloca, em cada repetição do for para percorrer o vetor, o maior número a direita,
	então, se na primeira repetição o maior número no vetor já foi colocado mais a direita, sabe-se que
	ele é o maior, e por isso, na próxima vez que o vetor for percorrida, tal posição não precisa ser analisada.
	Assim, temos que a o for percorrerá o vetor até a posição descrita pelo tamaho do vetor mais um menos a valor
	da repetição corrente (TAM + 1 - rep).
	*/
	
	printf("\nOrdenando a array com o Algoritmo Bubble Sort:\n\n");
	
	for (int rep = 1; rep < TAM; rep++) { // o número de vezes para que o vetor seja ordenado é (tamanho do vetor - 1)
		
		printf("rep%d --> ", rep);
		
		for (int i = 0; i < TAM + 1 - rep; i++) { // percorre o vetor de acordo com a necessidade
			
			/* O algoritmo coloca, em cada repetição do for para percorrer o vetor, o maior número a direita,
			então, se na primeira repetição o maior número no vetor já foi colocado mais a direita, sabe-se que
			ele é o maior, e por isso, na próxima vez que o vetor for percorrida, tal posição não precisa ser analisada.
			Assim, temos que a o for percorrerá o vetor até a posição descrita pelo tamaho do vetor mais um menos a valor
			da repetição corrente (TAM + 1 - rep). */
			
			if (vet[i] > vet[i + 1]) {
				
				// fazer a troca do valor da posição atual pelo da posição seguinte
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				
			}
			
			printf("%-2d ", vet[i]);
		}
		
		printf("\n");
		
	}
	
	printf("\nO vetor em ordem crescente: {");
	
	for (int i = 0; i < TAM; i++) {
		
		if (i != TAM - 1) {
		
			printf("%d, ", vet[i]);	
			
		} else {
			
			printf("%d}\n\n", vet[i]);
			
		}
		
	}
	
	system("pause");
	return 0;
}
