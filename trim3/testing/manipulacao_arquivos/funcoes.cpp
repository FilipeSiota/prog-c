#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp; // declarando ponteiro para arquivo
	
	int result;
	
	// FILE *fopen(char *nome do arquivo,char *modo) - PROTÓTIPO
	fp = fopen("arquivo.txt", "r+"); // r+ --> Leitura/Escrita. O arquivo deve existir e pode ser modificado.
	
	// Caso o arquivo nao tenha sido aberto com sucesso
	if (fp == NULL)
	{
		printf("Erro na abertura do arquivo.\n");
		
		system("pause");
		
		// void exit (int codigo de retorno) - PROTÓTIPO
		exit(1);
		/* A convenção mais usada é que um programa retorne zero
		no caso de um termino normal e retorne um número não
		nulo no caso de ter ocorrido um problema durante a sua
		execucão. */
	}
	
	// MANIPULANDO O ARQUIVO
	
	// # ESCREVENDO UM CARACTERE
	// int fputc(char c,FILE *fp); - PROTÓTIPO
	fputc('a', fp);
	// fputc(’*’, stdout); --> escreve um “*” na tela do monitor (dispositivo de saída padrão) ao invés de em um arquivo no disco rígido.
	
	// # LENDO UM CARACTERE
	// int fgetc(FILE *fp); - PROTÓTIPO
	fgetc(fp);
	// char c = fgetc(stdin); --> lê um caractere do teclado (dispositivo de entrada padrão) ao invés de um arquivo no disco rígido.
	
	// # FIM DO ARQUIVO
	/*
	while((c = fgetc(fp)) != EOF)
	{
		printf("%c\n", c);
	}
	*/
	// int feof(FILE *fp) - PROTÓTIPO
	char c;
	
	while(!feof(fp))
	{
		c = fgetc(fp);
		printf("%c\n", c);
	}
	// Basicamente, a funcão feof() retorna um valor inteiro diferente de zero se o arquivo chegou ao fim, caso contrario, retorna ZERO.

	// # FORÇANDO A ESCRITA DOS DADOS DO "BUFFER"
	// int fflush(FILE *fp); - PROTÓTIPO
	fflush(fp);
	// o seu comportamento depende do modo como o arquivo foi aberto
	
	// # SABENDO A POSIÇÃO ATUAL DENTRO DO ARQUIVO
	// long int ftell(FILE *fp); - PROTÓTIPO
	int tamanho = ftell(fp);
	printf("Tamanho do arquivo em bytes: %d", tamanho);
	system("pause");
	
	// # ESCREVENDO UMA STRING
	// int fputs (char *str,FILE *fp); - PROTÓTIPO
	fputs("hahah", fp);
	if (result == EOF)
	{
		printf("Erro na gravação.\n");
	}
	// A função fputs() não coloca o caracter de nova linha '\n', nem nenhum outro tipo de caractere, no final da string escrita no arquivo. Essa tarefa pertence ao programador.
	// Como a funcão fputc(), a funcão fputs() também pode ser utilizada para escrever uma string no dispositivo de saída padrão (geralmente a tela do monitor).
	
	// # LENDO UMA STRING
	// char *fgets (char *str, int tamanho, FILE *fp); - PROTÓTIPO
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
	// A funcão fgets() lê uma string do arquivo até que um caractere de nova linha (\n) seja lido ou “tamanho-1” caracteres tenham sido lidos.
	// Como a funcão gets(), a funcão fgets(), também pode ser utilizada para ler uma string do dispositivo de entrada padrão (geralmente o teclado).
	
	// # ESCREVENDO BLOCOS DE BYTES
	// int fwrite(void *buffer, int nro_de_bytes, int count, FILE *fp); - PROTÓTIPO
	/*
		• buffer: um ponteiro genérico para a região de memória que contém
		os dados que serão gravados no arquivo;
		• nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser
		gravada;
		• count: total de unidades de dados que devem ser gravadas.
		• fp: o ponteiro para o arquivo que se deseja trabalhar;
		
		- Note que temos dois valores inteiros: nro_de_bytes e
		count. Isto significa que o número total de bytes gravados
		no arquivo será: nro_de_bytes * count.
		
		- O valor do retorno da funcão fwrite() será igual ao valor
		de count a menos que ocorra algum erro na gravacão dos dados.
	*/
	int total_gravado, v[5] = {1, 2, 3, 4, 5};
	// grava todo o array no arquivo (5 posições)
	total_gravado = fwrite(v, sizeof(int), 5, fp);
	if (total_gravado != 5)
	{
		printf("Erro na escrita do arquivo!\n");
		system("pause");
		exit(1);
	}
	
	// # LENDO BLOCOS DE BYTES
	// int fread(void *buffer, int nro de bytes, int count, FILE *fp); - PROTÓTIPO
	/*
		• buffer: um ponteiro genérico para a região de memória que irá armazenar
		os dados que serão lidos do arquivo;
		• nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser lida;
		• count: total de unidades de dados que devem ser lidas.
		• fp: o ponteiro para o arquivo que se deseja trabalhar;
		
		- Note que temos dois valores inteiros: nro_de_bytes e
		count. Isto significa que o número total de bytes gravados
		no arquivo será: nro_de_bytes * count.
		
		- O valor do retorno da funcão fread() será igual ao valor
		de count a menos que ocorra algum erro na leitura dos dados.
	*/
	int i, total_lido, v[5];
	// lê 5 posições inteiras do arquivo
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
	// int fprintf(FILE *fp, “tipos de sa´ida”, lista de variaveis); - PROTÓTIPO
	/*
		• fp: o ponteiro para o arquivo que se deseja trabalhar;
		• “tipos de saída”: conjunto de caracteres que especifica o formato
		dos dados a serem escritos e/ou o texto a ser escrito;
		• lista de variáveis: conjunto de nomes de variáveis, separados por
		vírgula, que serão escritos.
		E retorna:
		• Em caso de sucesso, o número total de caracteres escritos no arquivo é retornado; ´
		• Em caso de erro, um número negativo é retornado.
		
		- Semelhante a função printf(), sua diferença é que, ao invés de escrever na tela, a funcão fprintf()
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
	// int fscanf(FILE *fp, “tipos de entrada”, lista de variaveis); - PROTÓTIPO
	/*
		• fp: o ponteiro para o arquivo que se deseja trabalhar;
		• “tipos de saída”: conjunto de caracteres que especifica o formato
		dos dados a serem lidos;
		• lista de variáveis: conjunto de nomes de variáveis, separados por
		vírgula, onde cada nome de variável é precedido pelo operador &.
		E retorna:
		• Em caso de sucesso, a funcão retorna o número de itens lidos com
		sucesso. Esse número pode ser menor do que o número de itens
		esperado, indicando que houve erro parcial de leitura.
		• a constante EOF, indicando que nenhum item foi lido com sucesso.
		
		- Semelhante a função scanf(), sua diferença é que, ao invés de ler os dados do teclado, a funcão
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
	
	// Se a intencão do programador é velocidade ou tamanho do arquivo, deve-se utilizar as funcões fwrite() e fread() ao invés de fprintf() e fscanf(), respectivamente.
	
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
	// O acesso ao arquivo é quase sempre feito de modo sequencial. Porém, a linguagem C permite realizar operacões de leitura e escrita randomica.
	// int fseek(FILE *fp, long numbytes, int origem); - PROTÓTIPO
	// Basicamente, a função fseek() move a posicão atual de leitura ou escrita no arquivo para um byte específico, a partir de um ponto especificado.
	/*
		• fp: o ponteiro para o arquivo que se deseja trabalhar;
		• numbytes: é o total de bytes a partir de origem a ser pulado;
		• origem: determina a partir de onde os numbytes de movimentação serão contados.
		
		- A função fseek() e retorna um valor inteiro igual a ZERO quando a movimentacão
		dentro do arquivo for bem sucedida. Um valor de retorno diferente de zero
		significa que houve um erro durante a movimentação.
		
		- Portanto, para movermos numbytes a partir do início do arquivo, a origem
		deve ser SEEK_SET. Se quisermos mover a partir da posição atual em que
		estamos no arquivo, devemos usar a constante SEEK_CUR. E, por fim,
		se quisermos mover a partir do final do arquivo, a constante SEEK_END
		deverá ser usada.
		
		- O valor do parâmetro numbytes pode ser negativo dependendo do tipo de movimentacão que formos realizar.
		Por exemplo, se quisermos se mover no arquivo a parir do ponto atual
		(SEEK_CUR) ou do seu final (SEEK_END), um valor negativo de bytes e possível.
		Nesse caso, estaríamos voltando dentro do arquivo a partir daquele ponto.
	*/
	fputs("1234567890", fp);
	fseek(fp, 5, SEEK_SET);
	fputs("abcde", fp);
	// Resultado: 12345abcde
	
	// # VOLTANDO AO COMEÇO DO ARQUIVO
	// void rewind(FILE *fp); - PROTÓTIPO
	rewind(fp);
	
	// # EXCLUINDO UM ARQUIVO
	// int remove(char *nome do arquivo); - PROTÓTIPO
	/*
		- Diferente das funções vistas até aqui, a função remove() recebe como
		parâmetro de entrada o caminho e nome do arquivo (caminho absoluto ou relativo) a ser excluído do
		disco rígido, e não um ponteiro para FILE. Como resultado, essa função
		retorna um valor inteiro igual a ZERO quando houver sucesso na exclusão
		do arquivo. Um valor de retorno diferente de zero significa que houve um
		erro durante a sua exclusão.
	
	int status = remove("arquivo.txt");
	if (status != 0)
	{
		printf("Erro na remoção do arquivo.\n");
		system("pause");
		exit(1);
	}
	else
	{
		printf("Arquivo removido com sucesso!\n");
		system("pause");
	}*/
	
	// Sempre que terminamos de usar um arquivo, devemos fechá-lo
	// int fclose (FILE *fp) - PROTÓTIPO
	result = fclose(fp);
	
	// # ERRO AO ACESSAR UM ARQUIVO
	// int ferror(FILE *fp); - PROTÓTIPO
	/*
		- Ao se trabalhar com arquivos, diversos tipos de erros podem ocorrer;
		
		- Basicamente, a função ferror() recebe como parâmetro o ponteiro fp que
		determina o arquivo que se quer verificar. A função verifica se o indicador
		de erro associado ao arquivo esta marcado, e retorna um valor igual a
		zero se nenhum erro ocorreu. Do contrário, a função retorna um número diferente de zero.
		
		- Como cada operação modifica a condição de erro do arquivo, a função
		ferror() deve ser chamada logo após cada operação realizada com o arquivo.
		
		- Uma outra funçãoo interessante para se utilizar em conjunto com a função
		ferror() e a função perror(). Seu nome vem da expressão em inglês print
		error, ou seja, impressão de erro.
		
		// void perror(char *str); - PROTÓTIPO
		// A função perror() recebe como parâmetro uma string que irá preceder a mensagem de erro do sistema.
		
		- Abaixo e apresentado um exemplo de uso das funções ferror() e perror().
		Nele, um programador tenta acessar um arquivo que não existe. A abertura desse arquivo irá falhar e a seguinte
		mensagem será apresentada: "O seguinte erro ocorreu: No such file or directory".
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
