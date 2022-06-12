/*
7) Fa�a um programa em C que leia dois conjuntos de n�meros inteiros, tendo cada
um 10 elementos. Ao final o programa deve listar os elementos comuns aos
conjuntos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int TAM = 10;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vet1[TAM], vet2[TAM], comum[TAM] = { }, contComum = 0, rep = 0;
	
	printf("####### 1� Conjunto #######\n\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe o %d� n�mero: ", i + 1);
		scanf("%d", &vet1[i]);
		
	}
	
	printf("\n####### 2� Conjunto #######\n\n");
	
	for (int i = 0; i < TAM; i++) {
		
		printf("Informe o %d� n�mero: ", i + 1);
		scanf("%d", &vet2[i]);
		
	}
	
	printf("\n####### Elementos em Comum #######\n\n");
	
	for (int v1 = 0; v1 < TAM; v1++) { // percorre o vetor do conjunto 1
		
		for (int v2 = 0; v2 < TAM; v2++) { // percorre o vetor do conjunto 2
			
			if (vet1[v1] == vet2[v2]) { // se achar um valor igual nos dois conjuntos
				
				for (int c1 = 0; c1 < TAM; c1++) { // percorre o vetor comum para saber se tal n�mero j� consta no vetor como elemento comum entre os conjuntos
					
					if (comum[c1] == vet2[v2]) { // se tal n�mero j� estiver no conjunto comum
						
						rep = 1; // � repetido
						
						break; // sai da itera��o para evitar processamewnto excessivo
						
					}
					
				}
				
				if (!rep) { // verifica se o n�mero � 0, pois se for � um elemento comum novo
					
					comum[contComum] = vet2[v2]; // e ser� adicionado ao vetor comum
					contComum++; // incrementa uma unidade para manipular corretamente o vetor comum e saber quantos elementos h� em comum entre os conjuntos
					
				}
				
				rep = 0; // coloca o valor falso (0), para a vari�vel que indica n�mero repetido
				
				break; // sai da itera��o para evitar processamewnto excessivo
				
			}
			
		}
		
	}
	
	if (!contComum) { // confere se h� elementos em comum
		
		printf("* N�o h� elementos em comum!\n");
		
	} else {
	
		for (int i = 0; i < contComum; i++) {
			
			printf(">> %d\n", comum[i]);
			
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
