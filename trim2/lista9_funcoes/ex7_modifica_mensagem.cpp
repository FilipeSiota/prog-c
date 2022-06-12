/* 7) Implemente um programa que leia uma mensagem e um caractere. Após a leitura, o 
programa deve, por meio de função, retirar todas as ocorrências do caractere informado 
na mensagem colocando * em seu lugar. A função deve também retornar o total de 
caracteres retirados. Ao final, o programa deve imprimir a frase ajustada e a quantidade 
de caracteres substituídos. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_TEXT 101

// # DEFINE UM NOVO TIPO DE DADO BASEADO NA ESTRUTURA DE DADOS (STRUCT) 'TEXTO'
typedef struct
{
	char mensagem[MAX_TEXT];
	char charSubst;
	int numSubst;
	
} Texto;

// # PROTÓTIPO DA FUNÇÃO
void modificaMensagem(Texto *text);

// # FUNÇÃO PRINCIPAL
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Texto string;
	
	printf("Digite uma breve mensagem de no máximo 100 caracteres (pressione ENTER apenas quando terminar de digitar a mensagem):\n\n\t| ");
	fgets(string.mensagem, MAX_TEXT, stdin);
	
	// # TIRA A QUEBRA DE LINHA QUE PODE VIR COM O FGETS
	for (int letra = 0; letra < MAX_TEXT; letra++)
	{
		if (string.mensagem[letra] == '\n')
		{
			string.mensagem[letra] = '\0';
		}
	}
	
	printf("\nInforme um caractere que você deseja remover da mensagem: ");
	scanf("%c", &string.charSubst);
	
	modificaMensagem(&string);
	
	printf("\n===================================================================\n");
	printf("                       MODIFICAÇÃO CONCLUÍDA                       \n");
	printf("===================================================================\n");
	printf("\nA mensagem foi modificada com '*' no lugar do caractere '%c':\n\n", string.charSubst);
	
	printf("%s\n", string.mensagem);
	
	printf("\nQuantidade de caracteres substituídos: %d\n\n", string.numSubst);
	
	system("pause");
	return 0;
}

// # DECLARAÇÃO DA FUNÇÃO
void modificaMensagem(Texto *text)
{
	int charText;
	
	text->numSubst = 0;
	
	for (charText = 0; charText < MAX_TEXT; charText++)
	{
		if (text->charSubst == text->mensagem[charText])
		{
			text->mensagem[charText] = '*';
			
			text->numSubst++;
		}
	}
	
	return;
}
