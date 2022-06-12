#include <stdio.h>
#include <stdlib.h>

const int TAM = 5;

int main() {
	
	int vet[TAM] = {5, 4, 3, 2, 1}, aux;
	
	/*
	Algoritmo Bubble Sort
	
	Basicamente, ele compara o valor da posi��o atual do vetor com o valor da pr�xima posi��o,
	caso for maior, o valor da posi��o atual passa a ser o valor da pr�xima posi��o e vice-versa
	(utiliza-se uma vari�vel auxiliar para tal). Dessa forma, sabemos que cada vez que o vetor for
	percorrido, ele se ordenar� aos poucos de forma crescente. O n�mero de vezes que o vetor ter� que
	ser percorrido para que a ordena��o esteja completa � o tamanho do vetor menos uma unidade (TAM - 1),
	pois n�o � necess�rio percorrer apenas a primeira posi��o do vetor, por isso o menos 1.
	
	O algoritmo coloca, em cada repeti��o do for para percorrer o vetor, o maior n�mero a direita,
	ent�o, se na primeira repeti��o o maior n�mero no vetor j� foi colocado mais a direita, sabe-se que
	ele � o maior, e por isso, na pr�xima vez que o vetor for percorrida, tal posi��o n�o precisa ser analisada.
	Assim, temos que a o for percorrer� o vetor at� a posi��o descrita pelo tamaho do vetor mais um menos a valor
	da repeti��o corrente (TAM + 1 - rep).
	*/
	
	for (int rep = 1; rep < TAM; rep++) { // o n�mero de vezes para que o vetor seja ordenado � (tamanho do vetor - 1)
		
		printf("rep%d --> ", rep);
		
		for (int i = 0; i < TAM + 1 - rep; i++) { // percorre o vetor de acordo com a necessidade
			
			/* O algoritmo coloca, em cada repeti��o do for para percorrer o vetor, o maior n�mero a direita,
			ent�o, se na primeira repeti��o o maior n�mero no vetor j� foi colocado mais a direita, sabe-se que
			ele � o maior, e por isso, na pr�xima vez que o vetor for percorrida, tal posi��o n�o precisa ser analisada.
			Assim, temos que a o for percorrer� o vetor at� a posi��o descrita pelo tamaho do vetor mais um menos a valor
			da repeti��o corrente (TAM + 1 - rep). */
			
			if (vet[i] > vet[i + 1]) {
				
				// fazer a troca do valor da posi��o atual pelo da posi��o seguinte
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				
			}
			
			printf("%2d ", vet[i]);
		}
		
		printf("\n\n");
		
	}
	
	system("pause");
	return 0;
}
