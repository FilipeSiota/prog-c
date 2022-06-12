/*
4. Faça um programa que copie um arquivo binário de inteiros (denominado
“números.bin”) para um outro arquivo binário de inteiros (denominado
“pares.bin”) de tal forma que apenas os números pares sejam copiados
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
	int *num; // um vetor cuja memória disponível será alocada dinamicamente, de acordo com a quantidade de números inteiros no arquivo
	int vet[10] = {1,2,3,4,5,6,7,8,9,10};
	
	// ABERTURA DO ARQUIVO NUMEROS.BIN
	numeros = fopen("ex4_numeros.bin", "w+b");
	
	if (numeros == NULL)
	{
		printf("Erro ao abrir/criar o arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// grava no arquivo ex4_numeros.bin alguns números para teste
	status = fwrite(vet, sizeof(int), 10, numeros);
	
	if (status != 10)
	{
		printf("Erro de gravação no arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// armazena o tamanho em bytes do arquivo numeros.bin
	status = tamanho(numeros);
	
	printf("\n\n%d\n\n", status);
	
	// como a função calloc retorna um ponteiro genérico, precisamos convertê-lo para um ponteiro de inteiros
	num = (int *)(calloc(tamanho(numeros)/sizeof(int), sizeof(int)));
	
	if (num == NULL)
	{
		printf("Erro na alocação de memória.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// lê os números que estão no arquivo ex4_numeros.bin e coloca-os no vetor num
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
	
	printf("Números encontrados no arquivo ex4_numeros.bin que serão copiados para o arquivo ex4_ex4_pares.bin:\n\n");
	
	for (int i = 0; i < i; i++)
	{
		// mostra em tela e copia para o arquivo ex4_pares.bin apenas os números pares que estavam contidos no outro arquivo
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
		printf("\n[Cópia dos números entre os arquivos realizada com sucesso]\n\n");
	}
	
	system("pause");
	return 0;
}

int tamanho(FILE *arquivo)
{
	int posicaoAtual = ftell(arquivo); // pega a posição atual
	fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
	int tamanho = ftell(arquivo); // pega a posição do final do arquivo para saber seu tamanho em bytes
	rewind(arquivo); // volta para o início do arquivo
	fseek(arquivo, posicaoAtual, SEEK_CUR); // ele andará a quantidade relativa de bytes a posicaoAtual a partir da posição atual no arquivo, neste caso o início
	// assim, retornamos a posição no arquivo em que estávamos antes de executar a função
	
	fclose(arquivo);
	
	return tamanho;
}
