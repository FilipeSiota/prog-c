/*
4. Fa�a um programa que copie um arquivo bin�rio de inteiros (denominado
�n�meros.bin�) para um outro arquivo bin�rio de inteiros (denominado
�pares.bin�) de tal forma que apenas os n�meros pares sejam copiados
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
	int i;
	int aux;
	
	// ABERTURA DO ARQUIVO NUMEROS.BIN
	numeros = fopen("ex4_numeros.bin", "w+b");
	
	if (numeros == NULL)
	{
		printf("Erro ao abrir/criar o arquivo.\n\n");
		
		system("pause");
		exit(1);
	}
	
	// grava no arquivo ex4_numeros.bin alguns n�meros para teste
	for (i = 0; i < 10; i++)
	{
		status = fprintf(numeros, " %d ", vet[i]);
		
		if (status < 0)
		{
			printf("Erro de grava��o no arquivo.\n\n");
			
			system("pause");
			exit(1);
		}
	}
	
	// conta a quantidade de n�meros lidos
	lidos = 0;
	
	while (!feof(numeros))
	{
		fscanf(numeros, " %d ", &vet[lidos]);
		
		lidos++;
	}
	
	printf("Quantidade de n�meros lidos: %d\n\n", lidos);
	
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
	
	// grava apenas os n�meros pares no arquivos pares.bin
	for (int i = 0; i < lidos; i++)
	{
		if (vet[i] % 2 == 0)
		{
			fprintf(pares, " %d ", vet[i]);
		}
	}
	
	printf("\nN�meros encontrados no arquivo ex4_numeros.bin que foram copiados para o arquivo ex4_pares.bin:\n\n");
	
	while (!feof(pares))
	{
		fscanf(pares, " %d ", &aux);
		
		printf("%d\n", aux);
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
