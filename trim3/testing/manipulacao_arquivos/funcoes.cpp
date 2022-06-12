#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp; // declarando ponteiro para arquivo
	
	int result;
	
	// FILE *fopen(char *nome do arquivo,char *modo) - PROT�TIPO
	fp = fopen("arquivo.txt", "r+"); // r+ --> Leitura/Escrita. O arquivo deve existir e pode ser modificado.
	
	// Caso o arquivo nao tenha sido aberto com sucesso
	if (fp == NULL)
	{
		printf("Erro na abertura do arquivo.\n");
		
		system("pause");
		
		// void exit (int codigo de retorno) - PROT�TIPO
		exit(1);
		/* A conven��o mais usada � que um programa retorne zero
		no caso de um termino normal e retorne um n�mero n�o
		nulo no caso de ter ocorrido um problema durante a sua
		execuc�o. */
	}
	
	// MANIPULANDO O ARQUIVO
	
	// # ESCREVENDO UM CARACTERE
	// int fputc(char c,FILE *fp); - PROT�TIPO
	fputc('a', fp);
	// fputc(�*�, stdout); --> escreve um �*� na tela do monitor (dispositivo de sa�da padr�o) ao inv�s de em um arquivo no disco r�gido.
	
	// # LENDO UM CARACTERE
	// int fgetc(FILE *fp); - PROT�TIPO
	fgetc(fp);
	// char c = fgetc(stdin); --> l� um caractere do teclado (dispositivo de entrada padr�o) ao inv�s de um arquivo no disco r�gido.
	
	// # FIM DO ARQUIVO
	/*
	while((c = fgetc(fp)) != EOF)
	{
		printf("%c\n", c);
	}
	*/
	// int feof(FILE *fp) - PROT�TIPO
	char c;
	
	while(!feof(fp))
	{
		c = fgetc(fp);
		printf("%c\n", c);
	}
	// Basicamente, a func�o feof() retorna um valor inteiro diferente de zero se o arquivo chegou ao fim, caso contrario, retorna ZERO.

	// # FOR�ANDO A ESCRITA DOS DADOS DO "BUFFER"
	// int fflush(FILE *fp); - PROT�TIPO
	fflush(fp);
	// o seu comportamento depende do modo como o arquivo foi aberto
	
	// # SABENDO A POSI��O ATUAL DENTRO DO ARQUIVO
	// long int ftell(FILE *fp); - PROT�TIPO
	int tamanho = ftell(fp);
	printf("Tamanho do arquivo em bytes: %d", tamanho);
	system("pause");
	
	// # ESCREVENDO UMA STRING
	// int fputs (char *str,FILE *fp); - PROT�TIPO
	fputs("hahah", fp);
	if (result == EOF)
	{
		printf("Erro na grava��o.\n");
	}
	// A fun��o fputs() n�o coloca o caracter de nova linha '\n', nem nenhum outro tipo de caractere, no final da string escrita no arquivo. Essa tarefa pertence ao programador.
	// Como a func�o fputc(), a func�o fputs() tamb�m pode ser utilizada para escrever uma string no dispositivo de sa�da padr�o (geralmente a tela do monitor).
	
	// # LENDO UMA STRING
	// char *fgets (char *str, int tamanho, FILE *fp); - PROT�TIPO
	char string[10];
	result = fgets(string, 10, fp);
	if (result == EOF)
	{
		printf("Erro na leitura.\n");
	}
	else
	{
		printf("%s", string);
	}
	// A func�o fgets() l� uma string do arquivo at� que um caractere de nova linha (\n) seja lido ou �tamanho-1� caracteres tenham sido lidos.
	// Como a func�o gets(), a func�o fgets(), tamb�m pode ser utilizada para ler uma string do dispositivo de entrada padr�o (geralmente o teclado).
	
	// # ESCREVENDO BLOCOS DE BYTES
	// int fwrite(void *buffer, int nro_de_bytes, int count, FILE *fp); - PROT�TIPO
	/*
		� buffer: um ponteiro gen�rico para a regi�o de mem�ria que cont�m
		os dados que ser�o gravados no arquivo;
		� nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser
		gravada;
		� count: total de unidades de dados que devem ser gravadas.
		� fp: o ponteiro para o arquivo que se deseja trabalhar;
		
		- Note que temos dois valores inteiros: nro_de_bytes e
		count. Isto significa que o n�mero total de bytes gravados
		no arquivo ser�: nro_de_bytes * count.
		
		- O valor do retorno da func�o fwrite() ser� igual ao valor
		de count a menos que ocorra algum erro na gravac�o dos dados.
	*/
	int total_gravado, v[5] = {1, 2, 3, 4, 5};
	// grava todo o array no arquivo (5 posi��es)
	total_gravado = fwrite(v, sizeof(int), 5, fp);
	if (total_gravado != 5)
	{
		printf("Erro na escrita do arquivo!\n");
		system("pause");
		exit(1);
	}
	
	// # LENDO BLOCOS DE BYTES
	// int fread(void *buffer, int nro de bytes, int count, FILE *fp); - PROT�TIPO
	/*
		� buffer: um ponteiro gen�rico para a regi�o de mem�ria que ir� armazenar
		os dados que ser�o lidos do arquivo;
		� nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser lida;
		� count: total de unidades de dados que devem ser lidas.
		� fp: o ponteiro para o arquivo que se deseja trabalhar;
		
		- Note que temos dois valores inteiros: nro_de_bytes e
		count. Isto significa que o n�mero total de bytes gravados
		no arquivo ser�: nro_de_bytes * count.
		
		- O valor do retorno da func�o fread() ser� igual ao valor
		de count a menos que ocorra algum erro na leitura dos dados.
	*/
	int i, total_lido, v[5];
	// l� 5 posi��es inteiras do arquivo
	total_lido = fread(v, sizeof(int), 5, arq);
	if (total_lido != 5)
	{
		printf("Erro na leitura do arquivo!\n");
		system("pause");
		exit(1);
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			printf("v[%d] = %d\n", i, v[i]);
		}
		system("pause");
	}
	
	// Ao se trabalhar com strings ou arrays, e sempre bom gravar no arquivo, antes da string ou array, o seu tamanho. Isso facilita muito a sua leitura posterior.
	// # GRAVANDO UMA STRING E SEU TAMANHO
	char str[20] = "Hello World!";
	int tam = strlen(str);
	fwrite(&t, sizeof(int), 1, fp);
	fwrite(str, sizeof(char), tam, fp);
	// # LENDO UMA STRING COM SEU TAMANHO
	char str1[20];
	int tam1;
	fread(&tam1, sizeof(int), 1, fp);
	fread(str1, sizeof(char), tam1);
	str1[tam1] = '\0';
	printf("%s\n", str1);
	system("pause");
	
	// # ESCREVENDO DADOS FORMATADOS
	// int fprintf(FILE *fp, �tipos de sa�ida�, lista de variaveis); - PROT�TIPO
	/*
		� fp: o ponteiro para o arquivo que se deseja trabalhar;
		� �tipos de sa�da�: conjunto de caracteres que especifica o formato
		dos dados a serem escritos e/ou o texto a ser escrito;
		� lista de vari�veis: conjunto de nomes de vari�veis, separados por
		v�rgula, que ser�o escritos.
		E retorna:
		� Em caso de sucesso, o n�mero total de caracteres escritos no arquivo � retornado; �
		� Em caso de erro, um n�mero negativo � retornado.
		
		- Semelhante a fun��o printf(), sua diferen�a � que, ao inv�s de escrever na tela, a func�o fprintf()
		direciona os dados para o arquivo especificado.
	*/
	char nome[20] = "Ricardo";
	int idade = 30;
	float altura = 1.74;
	result = fprintf(fp, "Nome: %s\nIdade: %d\nAltura: %f\n", nome, idade, altura);
	if (resultado < 0)
	{
		printf("Erro na escrita.\n");
	}
	
	// # LENDO DADOS FORMATADOS
	// int fscanf(FILE *fp, �tipos de entrada�, lista de variaveis); - PROT�TIPO
	/*
		� fp: o ponteiro para o arquivo que se deseja trabalhar;
		� �tipos de sa�da�: conjunto de caracteres que especifica o formato
		dos dados a serem lidos;
		� lista de vari�veis: conjunto de nomes de vari�veis, separados por
		v�rgula, onde cada nome de vari�vel � precedido pelo operador &.
		E retorna:
		� Em caso de sucesso, a func�o retorna o n�mero de itens lidos com
		sucesso. Esse n�mero pode ser menor do que o n�mero de itens
		esperado, indicando que houve erro parcial de leitura.
		� a constante EOF, indicando que nenhum item foi lido com sucesso.
		
		- Semelhante a fun��o scanf(), sua diferen�a � que, ao inv�s de ler os dados do teclado, a func�o
		fscanf() direciona a leitura dos dados para o arquivo especificado.
	*/
	char texto[20], name[20];
	int age;
	float height;
	fscanf(fp, "%s%s", texto, name);
	printf("%s: %s\n", texto, name);
	fscanf(fp, "%s%d", texto, age);
	printf("%s: %d\n", texto, age);
	fscanf(fp, "%s%f", texto, height);
	printf("%s: %f\n", texto, height);
	
	// Se a intenc�o do programador � velocidade ou tamanho do arquivo, deve-se utilizar as func�es fwrite() e fread() ao inv�s de fprintf() e fscanf(), respectivamente.
	
	// # GRAVANDO UMA MATRIZ DENTRO DE UM ARQUIVO
	int mat[2][2] = {{1,2},{3,4}};
	int row, col;
	for (row = 0; row < 2; row++)
	{
		for (col = 0; col < 2; col++)
		{
			fprintf(fp, "%d\n", mat[row][col]);
		}
	}
	
	// # LENDO UMA MATRIZ DE DENTRO DE UM ARQUIVO
	int linha, coluna, v, soma = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d\n", &v);
		soma += v;
	}
	printf("Soma = %d\n", soma);
	
	// # MOVENDO-SE DENTRO DO ARQUIVO
	// O acesso ao arquivo � quase sempre feito de modo sequencial. Por�m, a linguagem C permite realizar operac�es de leitura e escrita randomica.
	// int fseek(FILE *fp, long numbytes, int origem); - PROT�TIPO
	// Basicamente, a fun��o fseek() move a posic�o atual de leitura ou escrita no arquivo para um byte espec�fico, a partir de um ponto especificado.
	/*
		� fp: o ponteiro para o arquivo que se deseja trabalhar;
		� numbytes: � o total de bytes a partir de origem a ser pulado;
		� origem: determina a partir de onde os numbytes de movimenta��o ser�o contados.
		
		- A fun��o fseek() e retorna um valor inteiro igual a ZERO quando a movimentac�o
		dentro do arquivo for bem sucedida. Um valor de retorno diferente de zero
		significa que houve um erro durante a movimenta��o.
		
		- Portanto, para movermos numbytes a partir do in�cio do arquivo, a origem
		deve ser SEEK_SET. Se quisermos mover a partir da posi��o atual em que
		estamos no arquivo, devemos usar a constante SEEK_CUR. E, por fim,
		se quisermos mover a partir do final do arquivo, a constante SEEK_END
		dever� ser usada.
		
		- O valor do par�metro numbytes pode ser negativo dependendo do tipo de movimentac�o que formos realizar.
		Por exemplo, se quisermos se mover no arquivo a parir do ponto atual
		(SEEK_CUR) ou do seu final (SEEK_END), um valor negativo de bytes e poss�vel.
		Nesse caso, estar�amos voltando dentro do arquivo a partir daquele ponto.
	*/
	fputs("1234567890", fp);
	fseek(fp, 5, SEEK_SET);
	fputs("abcde", fp);
	// Resultado: 12345abcde
	
	// # VOLTANDO AO COME�O DO ARQUIVO
	// void rewind(FILE *fp); - PROT�TIPO
	rewind(fp);
	
	// # EXCLUINDO UM ARQUIVO
	// int remove(char *nome do arquivo); - PROT�TIPO
	/*
		- Diferente das fun��es vistas at� aqui, a fun��o remove() recebe como
		par�metro de entrada o caminho e nome do arquivo (caminho absoluto ou relativo) a ser exclu�do do
		disco r�gido, e n�o um ponteiro para FILE. Como resultado, essa fun��o
		retorna um valor inteiro igual a ZERO quando houver sucesso na exclus�o
		do arquivo. Um valor de retorno diferente de zero significa que houve um
		erro durante a sua exclus�o.
	
	int status = remove("arquivo.txt");
	if (status != 0)
	{
		printf("Erro na remo��o do arquivo.\n");
		system("pause");
		exit(1);
	}
	else
	{
		printf("Arquivo removido com sucesso!\n");
		system("pause");
	}*/
	
	// Sempre que terminamos de usar um arquivo, devemos fech�-lo
	// int fclose (FILE *fp) - PROT�TIPO
	result = fclose(fp);
	
	// # ERRO AO ACESSAR UM ARQUIVO
	// int ferror(FILE *fp); - PROT�TIPO
	/*
		- Ao se trabalhar com arquivos, diversos tipos de erros podem ocorrer;
		
		- Basicamente, a fun��o ferror() recebe como par�metro o ponteiro fp que
		determina o arquivo que se quer verificar. A fun��o verifica se o indicador
		de erro associado ao arquivo esta marcado, e retorna um valor igual a
		zero se nenhum erro ocorreu. Do contr�rio, a fun��o retorna um n�mero diferente de zero.
		
		- Como cada opera��o modifica a condi��o de erro do arquivo, a fun��o
		ferror() deve ser chamada logo ap�s cada opera��o realizada com o arquivo.
		
		- Uma outra fun��oo interessante para se utilizar em conjunto com a fun��o
		ferror() e a fun��o perror(). Seu nome vem da express�o em ingl�s print
		error, ou seja, impress�o de erro.
		
		// void perror(char *str); - PROT�TIPO
		// A fun��o perror() recebe como par�metro uma string que ir� preceder a mensagem de erro do sistema.
		
		- Abaixo e apresentado um exemplo de uso das fun��es ferror() e perror().
		Nele, um programador tenta acessar um arquivo que n�o existe. A abertura desse arquivo ir� falhar e a seguinte
		mensagem ser� apresentada: "O seguinte erro ocorreu: No such file or directory".
	*/
	FILE *arq;
	arq = fopen("NaoExiste.txt", "r");
	if (arq == NULL)
	{
		perror("O seguinte erro ocorreu: ");
	}
	else
	{
		fclose(arq);
	}
	
	system("pause");
	return 0;
}
