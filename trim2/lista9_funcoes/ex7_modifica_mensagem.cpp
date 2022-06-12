/* 7) Implemente um programa que leia uma mensagem e um caractere. Ap�s a leitura, o 
programa deve, por meio de fun��o, retirar todas as ocorr�ncias do caractere informado 
na mensagem colocando * em seu lugar. A fun��o deve tamb�m retornar o total de 
caracteres retirados. Ao final, o programa deve imprimir a frase ajustada e a quantidade 
de caracteres substitu�dos. */

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

// # PROT�TIPO DA FUN��O
void modificaMensagem(Texto *text);

// # FUN��O PRINCIPAL
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Texto string;
	
	printf("Digite uma breve mensagem de no m�ximo 100 caracteres (pressione ENTER apenas quando terminar de digitar a mensagem):\n\n\t| ");
	fgets(string.mensagem, MAX_TEXT, stdin);
	
	// # TIRA A QUEBRA DE LINHA QUE PODE VIR COM O FGETS
	for (int letra = 0; letra < MAX_TEXT; letra++)
	{
		if (string.mensagem[letra] == '\n')
		{
			string.mensagem[letra] = '\0';
		}
	}
	
	printf("\nInforme um caractere que voc� deseja remover da mensagem: ");
	scanf("%c", &string.charSubst);
	
	modificaMensagem(&string);
	
	printf("\n===================================================================\n");
	printf("                       MODIFICA��O CONCLU�DA                       \n");
	printf("===================================================================\n");
	printf("\nA mensagem foi modificada com '*' no lugar do caractere '%c':\n\n", string.charSubst);
	
	printf("%s\n", string.mensagem);
	
	printf("\nQuantidade de caracteres substitu�dos: %d\n\n", string.numSubst);
	
	system("pause");
	return 0;
}

// # DECLARA��O DA FUN��O
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
