/*
4. Fa�a um programa que informe o m�s de acordo com o n�mero digitado pelo
usu�rio.
	Exemplo: Entrada = 4. Sa�da = Abril
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int mes;
	
	printf("Informe um n�mero de 1 a 12 para que o respectivo m�s seja informado: ");
	scanf("%d", &mes);
	
	switch (mes) {
		case 1:
			printf("\nM�s %d: Janeiro\n\n", mes);
			break;
			
		case 2:
			printf("\nM�s %d: Fevereiro\n\n", mes);
			break;
			
		case 3:
			printf("\nM�s %d: Mar�o\n\n", mes);
			break;
			
		case 4:
			printf("\nM�s %d: Abril\n\n", mes);
			break;
			
		case 5:
			printf("\nM�s %d: Maio\n\n", mes);
			break;
			
		case 6:
			printf("\nM�s %d: Junho\n\n", mes);
			break;
			
		case 7:
			printf("\nM�s %d: Julho\n\n", mes);
			break;
			
		case 8:
			printf("\nM�s %d: Agosto\n\n", mes);
			break;
			
		case 9:
			printf("\nM�s %d: Setembro\n\n", mes);
			break;
			
		case 10:
			printf("\nM�s %d: Outubro\n\n", mes);
			break;
			
		case 11:
			printf("\nM�s %d: Novembro\n\n", mes);
			break;
			
		case 12:
			printf("\nM�s %d: Dezembro\n\n", mes);
			break;
			
		default:
			puts("\nUps! Voc� informou uma op��o inv�lida.\n");
	}
	
	system("pause");
	return 0;
}
