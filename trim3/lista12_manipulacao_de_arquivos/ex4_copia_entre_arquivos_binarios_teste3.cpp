/*
4. Fa�a um programa que copie um arquivo bin�rio de inteiros (denominado
�n�meros.bin�) para um outro arquivo bin�rio de inteiros (denominado
�pares.bin�) de tal forma que apenas os n�meros pares sejam copiados
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int tamanho(FILE *arquivo);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *numeros;
	FILE *pares;
	
	int status;
	int *num; // um vetor cuja mem�ria dispon�vel ser� alocada dinamicamente, de acordo com a quantidade de n�meros inteiros no arquivo
	int vet[10] = {1,2,3,4,5,6,7,8,9,10};
	
	// ABERTURA DO ARQUIVO NUMEROS.BIN
	numeros = fopen("ex4_numeros.bin", "w+b");
	
	if (numeros == NULL)
	{
		printf("Erro ao abrir/criar o arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// grava no arquivo ex4_numeros.bin alguns n�meros para teste
	status = fwrite(vet, sizeof(int), 10, numeros);
	
	if (status != 10)
	{
		printf("Erro de grava��o no arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// armazena o tamanho em bytes do arquivo numeros.bin
	status = tamanho(numeros);
	
	printf("\n\n%d\n\n", status);
	
	// como a fun��o calloc retorna um ponteiro gen�rico, precisamos convert�-lo para um ponteiro de inteiros
	num = (int *)(calloc(tamanho(numeros)/sizeof(int), sizeof(int)));
	
	if (num == NULL)
	{
		printf("Erro na aloca��o de mem�ria.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// l� os n�meros que est�o no arquivo ex4_numeros.bin e coloca-os no vetor num
	status = fread(num, sizeof(int), tamanho(numeros)/sizeof(int), numeros);
	
if (status != 0)
	{
		printf("Erro na leitura do arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// FECHAMENTO DO ARQUIVO NUMEROS.BIN
	status = fclose(numeros);
	
	// caso ocorra algum erro
	if (status)
	{
		printf("Erro ao fechar o arquivo.\n\n");
			
		system("pause");
		exit(1);
	}
	
	// ABERTURA DO ARQUIVO PARES.BIN
	pares = fopen("ex4_pares.bin", "wb");
	
	if (pares == NULL)
	{
		printf("Erro ao abrir/criar o arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	printf("N�meros encontrados no arquivo ex4_numeros.bin que ser�o copiados para o arquivo ex4_ex4_pares.bin:\n\n");
	
	for (int i = 0; i < i; i++)
	{
		// mostra em tela e copia para o arquivo ex4_pares.bin apenas os n�meros pares que estavam contidos no outro arquivo
		if (num[i] % 2 == 0)
		{
			printf("%d\n", num[i]);
			
			fwrite(num, sizeof(int), 1, pares);
		}
	}
	
	/// FECHAMENTO DO ARQUIVO PARES.BIN
	status = fclose(pares);
	
	// caso ocorra algum erro
	if (status)
	{
		printf("\nErro ao fechar o arquivo.\n\n");
			
		system("pause");
		exit(1);
	}
	else
	{
		printf("\n[C�pia dos n�meros entre os arquivos realizada com sucesso]\n\n");
	}
	
	system("pause");
	return 0;
}

int tamanho(FILE *arquivo)
{
	int posicaoAtual = ftell(arquivo); // pega a posi��o atual
	fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
	int tamanho = ftell(arquivo); // pega a posi��o do final do arquivo para saber seu tamanho em bytes
	rewind(arquivo); // volta para o in�cio do arquivo
	fseek(arquivo, posicaoAtual, SEEK_CUR); // ele andar� a quantidade relativa de bytes a posicaoAtual a partir da posi��o atual no arquivo, neste caso o in�cio
	// assim, retornamos a posi��o no arquivo em que est�vamos antes de executar a fun��o
	
	fclose(arquivo);
	
	return tamanho;
}
