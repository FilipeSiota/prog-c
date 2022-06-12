/*
1. Uma empresa vende o mesmo produto para quatro diferentes estados. Cada
estado possui uma taxa diferente de imposto sobre o produto. Faça um
programa em que o usuário entre com o valor e o estado de destino do
produto e o programa retorne o preço final do produto acrescido do imposto
do estado em que ele será vendido. Se o estado digitado não for válido,
mostrará uma mensagem de erro.
	Estado 	MG	SP 	RJ 	MS
	Imposto	7%	12% 15% 8%
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const float MG = 7.0, SP = 12.0, RJ = 15.0, MS = 8.0;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float val_init, val_imp;
	int estado;
	
	printf("Valor do produto: R$");
	scanf("%f", &val_init);
	
	puts("\n1. Minas Gerais - MG\n2. São Paulo - SP\n3. Rio de Janeiro - RJ\n4. Mato Grosso do Sul - MS\n");
	
	printf("De acordo com as opções acima, informe o número do estado de destino do produto: ");
	scanf("%d", &estado);
	
	switch (estado) {
		case 1:
			val_imp = MG / 100.0 * val_init;
			
			printf("\nNo estado de Minas Gerais a taxa de imposto é de %.2f%%.\nValor do imposto: R$%.2f\n", MG, val_imp);
			
			val_imp += val_init;
			
			printf("\nPreço final do produto: R$%.2f\n\n", val_imp);
			break;
			
		case 2:
			val_imp = SP / 100.0 * val_init;
			
			printf("\nNo estado de São Paulo a taxa de imposto é de %.2f%%.\nValor do imposto: R$%.2f\n", SP, val_imp);
			
			val_imp += val_init;
			
			printf("\nPreço final do produto: R$%.2f\n\n", val_imp);
			break;
			
		case 3:
			val_imp = RJ / 100.0 * val_init;
			
			printf("\nNo estado do Rio de Janeiro a taxa de imposto é de %.2f%%.\nValor do imposto: R$%.2f\n", RJ, val_imp);
			
			val_imp += val_init;
			
			printf("\nPreço final do produto: R$%.2f\n\n", val_imp);
			break;
			
		case 4:
			val_imp = MS / 100.0 * val_init;
			
			printf("\nNo estado de Mato Grosso do Sul a taxa de imposto é de %.2f%%.\nValor do imposto: R$%.2f\n", MS, val_imp);
			
			val_imp += val_init;
			
			printf("\nPreço final do produto: R$%.2f\n\n", val_imp);
			break;
			
		default:
			puts("\nUps! Você informou uma opção inválida.\n");
			break;
	}
	
	system("pause");
	return 0;
}
