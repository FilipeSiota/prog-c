/* Exercício
Usando como base o exemplo dos slides acima, faça um código que peça o nome e a idade da
pessoa.
	- Caso ela seja maior de 18, informe: “Fulano, você já pode ter habilitação”
	- Caso seja menor de 18, informe: “Fulano, faltam x anos para você poder ter habilitação”. */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char nome[100];
	int idade;
	
	printf("Informe seu nome: ");
	gets(nome);
	
	printf("Informe sua idade: ");
	scanf("%d", &idade);
	
	if (idade >= 18){
		
		printf("\n%s, voce ja pode ter habilitacao!\n\n", nome);
		
	} else {
		
		printf("\n%s, faltam %d anos para voce poder ter habilitacao.\n\n", nome, 18 - idade);
		
	}
	
	system("pause");
	
	return 0;
}
