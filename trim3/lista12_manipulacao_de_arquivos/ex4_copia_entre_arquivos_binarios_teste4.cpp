/*
4. Faça um programa que copie um arquivo binário de inteiros (denominado
“números.bin”) para um outro arquivo binário de inteiros (denominado
“pares.bin”) de tal forma que apenas os números pares sejam copiados
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *numeros;
	FILE *pares;
	
	int status;
	int vet[10] = {1,2,3,4,5,6,7,8,9,10};
	int lidos;
	
	// ABERTURA DO ARQUIVO NUMEROS.BIN
	numeros = fopen("ex4_numeros.bin", "w+b");
	
	if (numeros == NULL)
	{
		printf("Erro ao abrir/criar o arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// grava no arquivo ex4_numeros.bin alguns números para teste
	status = fwrite(&vet, sizeof(int), 10, numeros);
	
	if (status != 10)
	{
		printf("Erro de gravação no arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	lidos = fread(&vet, sizeof(int), 10, numeros);
	
	printf("Quantidade de números lidos: %d\n\n", lidos);
	
	for (int i = 0; i < lidos; i++)
	{
		printf("%d\n", vet[i]);
	}
	
	// FECHAMENTO DO ARQUIVO NUMEROS.BIN
	status = fclose(numeros);
	
	// caso ocorra algum erro
	if (status)
	{
		perror("O seguinte erro ocorreu ");
			
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
	
	for (int i = 0; i < lidos; i++)
	{
		if (vet[i] % 2 == 0)
		{
			fwrite(&vet, sizeof(int), 1, pares);
		}
	}
	
	printf("\nNúmeros encontrados no arquivo ex4_numeros.bin que foram copiados para o arquivo ex4_pares.bin:\n\n");
	
	lidos = fread(&vet, sizeof(int), 1, pares);
	
	for (int i = 0; i < lidos; i++)
	{
		printf("%d\n", vet[i]);
	}
	
	// FECHAMENTO DO ARQUIVO PARES.BIN
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
