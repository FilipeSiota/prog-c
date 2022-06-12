/*
4. Faça um programa que informe o mês de acordo com o número digitado pelo
usuário.
	Exemplo: Entrada = 4. Saída = Abril
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mes;
	
	printf("Informe um número de 1 a 12 para que o respectivo mês seja informado: ");
	scanf("%d", &mes);
	
	switch (mes) {
		case 1:
			printf("\nMês %d: Janeiro\n\n", mes);
			break;
			
		case 2:
			printf("\nMês %d: Fevereiro\n\n", mes);
			break;
			
		case 3:
			printf("\nMês %d: Março\n\n", mes);
			break;
			
		case 4:
			printf("\nMês %d: Abril\n\n", mes);
			break;
			
		case 5:
			printf("\nMês %d: Maio\n\n", mes);
			break;
			
		case 6:
			printf("\nMês %d: Junho\n\n", mes);
			break;
			
		case 7:
			printf("\nMês %d: Julho\n\n", mes);
			break;
			
		case 8:
			printf("\nMês %d: Agosto\n\n", mes);
			break;
			
		case 9:
			printf("\nMês %d: Setembro\n\n", mes);
			break;
			
		case 10:
			printf("\nMês %d: Outubro\n\n", mes);
			break;
			
		case 11:
			printf("\nMês %d: Novembro\n\n", mes);
			break;
			
		case 12:
			printf("\nMês %d: Dezembro\n\n", mes);
			break;
			
		default:
			puts("\nUps! Você informou uma opção inválida.\n");
	}
	
	system("pause");
	return 0;
}
