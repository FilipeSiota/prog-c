#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// criando a vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	
	//abrindo o arquivo
	pont_arq = fopen("arquivo.txt", "a");
	
	// fechando arquivo
	fclose(pont_arq);
	
	//mensagem para o usu�rio
	if (pont_arq == NULL)
	{
	    printf("ERRO! O arquivo n�o foi aberto!\n\n");
	}
	else
   {
     printf("O arquivo foi aberto com sucesso!\n\n");
   }
	
	system("pause");
	return(0);
}
