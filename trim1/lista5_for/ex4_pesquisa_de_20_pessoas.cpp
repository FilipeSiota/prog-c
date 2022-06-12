/*
4. Faça um programa em C que permita entrar com o nome, a idade e o sexo de
20 pessoas. O programa deve imprimir o nome da pessoa se ela for do sexo
masculino e tiver mais de 21 anos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[100], sexo;
	int idade;
	
	for (int i = 0; i < 20; i++) {
		
		printf("Nome completo: ");
		fflush(stdin); // limpar o BUFFER do teclado
		fgets(nome, 100, stdin);
		
		printf("Idade: ");
		scanf("%d", &idade);
		
		printf("Sexo (M para masculino ou F para feminino): ");
		sexo = getche();
		
		if ( (sexo == 'M' || sexo == 'm') && idade > 21 ) {
			
			printf("\n\n>>>> %s\n", nome);
			
		} else {
			
			printf("\n\n");
			
		}
	}
	
	system("pause");
	return 0;
}
