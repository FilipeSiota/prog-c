#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	char palavra[20], letra, j1[20], j2[20];		// "Palavra" porque obviamente, tem que ter na matriz --> OK;
													// "Letra" S�o as letras que eles tem que dar --> uma vari�vel que armazene a letra da tentativa corrente (n�o seria um vetor da�);
													// "J1" Jogador 1 e "j2" jogador 2 --> como tu colocou em char daria para armazenar os nomes dos jogadores;
													// "Lacuna" S�o os espacinhos( n sei direito, a sora mandou eu por skssks); 
													//"erros" Pra armazenar o n�mero de erros --> vc tbm pode criar um vetor para armazenar as letras erradas);
													// "Vidas" Para armazenar o n�mero de vidas --> OK; "acertos" Para armazenar o n�mero de acertos --> e da para criar um vetor para imprimir as letras j� acertadas da palavra)
	int vidas = 5, acertos = 0, erros = 0;
	int acerto, erro; // contadores de for
	
	// variaveis adicionadas
	int let; // contador para passar pelo for das letras
	int tamanho; // pega o tamanho da palavra
	char letras_certas[20], letras_erradas[20];
	int contem = 0; // para ver se a letra corresponde a posi��o da letra na palavra
	int cont_let_total_acertos; // conta o n�mero de letras j� adivinhadas, inclusive as repetidas
	
	
	printf("Insira o nome do Jogador 1: ");
	fflush(stdin); // limpa buffer do teclado
	gets(j1);
	
	printf("Insira o nome do Jogador 2: ");
	fflush(stdin);
	gets(j2);
	
	// N�o sei o que fazer aqui, queria deixar o usu�rio escolher qual jogador! -> deixa eles colocarem os nomes deles
	
	system("cls"); // limpa a tela
	
	printf("%s, insira uma palavra para %s adivinhar: ", j1, j2);
	fflush(stdin);
	gets(palavra);
	// ou scanf("%20s", palavra) >> para pegar s� uma palavra de at� 20 caracteres (sem espa�os)
	
	tamanho = strlen(palavra);
	
	while(vidas > 0) // A sora disse que tinha que usar o enquanto, mas t� bugada. --> repetir enquanto tiver vidas sobrando 
	{
		//printf("%s", &lacuna); // Na verdade t� bugada de modo geral. --> vc roda um for para percorrer o vetor dos acertos para ver se a pessoa j� adivinhou alguma letra, se sim, imprimir, se n�o coloca um _
	
		system("cls");
	
		printf("Vidas: %d\n\n", vidas); // mostra a quantidade de vidas do jogador que est� adivinhando
	
		cont_let_total_acertos = 0;
	
		// imprime as lacunas ou as letras j� adivinhadas
		for (let = 0; let < tamanho; let++)
		{
			if (acertos > 0) // roda um for para as letras acertadas para colocar letras ao inves de _
			{
				contem = 0;
				
				for (acerto = 0; acerto < acertos; acerto++)
				{
					if (palavra[let] == letras_certas[acerto])
					{
						printf("%c ", letras_certas[acerto]);
						
						contem = 1; // verifica se dentre as letras j� acertadas, se encaixa com a posi��o da letra na palavra
						
						cont_let_total_acertos++; // conta para ver se o jogador que est� adivinhando j� acertou todas as letras da palavra
					}
				}
				
				if (contem != 1)
				{
					printf("_ ");
				}
			}
			else // se n�o tiver acertos ainda, s� preenche com _
			{
				printf("_ ");
			}
		}
		
		if (cont_let_total_acertos == tamanho) // verifica se o jogador que est� adivinhando j� ganhou (lembra que contamos as letras ali em cima)
		{
			printf("\n\nParab�ns %s, voc� venceu!\n\n", j2);
			
			break; // faz ele sair do while
		}
		
		if (erros > 0) // mostra as letras que o usuario j� informou e n�o est�o contidas na palavra a ser adivinhada
		{
			printf("\n\nLetras erradas: ");
			for (erro = 0; erro < erros; erro++)
			{
				printf("%c ", letras_erradas[erro]);
			}
		}
		// IMPEDIR QUE O USU�RIO INFORME UMA LETRA J� INFORMADA
		do {
			contem = 0;
			
			printf("\n\nDigite uma letra: ");
			fflush(stdin);
			scanf("%c", &letra);
			
			for (acerto = 0; acerto < acertos; acerto++) // verifica se a letra informada j� est� contida entre as certas informadas
			{
				if (letras_certas[acerto] == letra)
				{
					contem = 1; // se sim, muda o valor do contem para repetir o while at� que o usu�rio informe uma letra nunca informada antes
					
					break; // se encontrar uma repetida j� sai do la�o
				}
			}
			
			for (erro = 0; erro < erros; erro++) // verifica se a letra informada j� est� contida entre as erradas informadas
			{
				if (letras_erradas[erro] == letra)
				{
					contem = 1; // se sim, muda o valor do contem para repetir o while at� que o usu�rio informe uma letra nunca informada antes
					
					break; // se encontrar uma repetida j� sai do la�o
				}
			}
			
			if (contem == 1)
			{
				printf("\nLetra j� informada! Tente novamente."); // mensagem de aviso
			}
		} while (contem == 1);
		
		// VERIFICA SE A LETRA INFORMADA PELO USUARIO � CERTA OU ERRADA
		for (let = 0; let < tamanho; let++)
		{
			if (palavra[let] == letra) // se ele acertou
			{
				printf("\nVoc� acertou a letra!\n\n"); // mensagem de aviso
				
				letras_certas[acertos] = letra; // adiciona a letra adivinhada �s outras tbm adivinhadas (deve vir primeiro que o incremento abaixo)
				
				acertos++; // adiciona � quantidade de acertos uma unidade
				
				break; // sai desse la�o for
			}
			else if (let == tamanho - 1) // se chegou na �ltima repeti��o do la�o e n�o foi constatado o acerto
			{
				printf("\nVoc� errou a letra!\n\n"); // mensagem de aviso
				
				letras_erradas[erros] = letra; // adiciona a letra errada �s outras tbm erradas (deve vir primeiro que o incremento abaixo)
				
				erros++; // adiciona � quantidade de erros uma unidade
				
				vidas--; // tira uma vida
				
				if (vidas == 0) // se as vidas tiverem chegado a zero
				{
					printf("%s voc� perdeu! A palavra era %s.\n\nParab�ns %s!\n\n", j2, palavra, j1); // mensagem de aviso
					
					// quando for fazer a pr�xima repeti��o do while l� em cima, ele n�o vai rodar de novo pois as vidas n�o v�o ser maiores que 0 (vai ser zero)
				}
			}
		}
		
		system("pause"); // pausa o andamento do programa para que as informa��es possam ser visualizadas na tela
	}
	
	return 0;
}
