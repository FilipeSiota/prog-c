#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	char palavra[20], letra, j1[20], j2[20];		// "Palavra" porque obviamente, tem que ter na matriz --> OK;
													// "Letra" São as letras que eles tem que dar --> uma variável que armazene a letra da tentativa corrente (não seria um vetor daí);
													// "J1" Jogador 1 e "j2" jogador 2 --> como tu colocou em char daria para armazenar os nomes dos jogadores;
													// "Lacuna" São os espacinhos( n sei direito, a sora mandou eu por skssks); 
													//"erros" Pra armazenar o número de erros --> vc tbm pode criar um vetor para armazenar as letras erradas);
													// "Vidas" Para armazenar o número de vidas --> OK; "acertos" Para armazenar o número de acertos --> e da para criar um vetor para imprimir as letras já acertadas da palavra)
	int vidas = 5, acertos = 0, erros = 0;
	int acerto, erro; // contadores de for
	
	// variaveis adicionadas
	int let; // contador para passar pelo for das letras
	int tamanho; // pega o tamanho da palavra
	char letras_certas[20], letras_erradas[20];
	int contem = 0; // para ver se a letra corresponde a posição da letra na palavra
	int cont_let_total_acertos; // conta o número de letras já adivinhadas, inclusive as repetidas
	
	
	printf("Insira o nome do Jogador 1: ");
	fflush(stdin); // limpa buffer do teclado
	gets(j1);
	
	printf("Insira o nome do Jogador 2: ");
	fflush(stdin);
	gets(j2);
	
	// Não sei o que fazer aqui, queria deixar o usuário escolher qual jogador! -> deixa eles colocarem os nomes deles
	
	system("cls"); // limpa a tela
	
	printf("%s, insira uma palavra para %s adivinhar: ", j1, j2);
	fflush(stdin);
	gets(palavra);
	// ou scanf("%20s", palavra) >> para pegar só uma palavra de até 20 caracteres (sem espaços)
	
	tamanho = strlen(palavra);
	
	while(vidas > 0) // A sora disse que tinha que usar o enquanto, mas tô bugada. --> repetir enquanto tiver vidas sobrando 
	{
		//printf("%s", &lacuna); // Na verdade tô bugada de modo geral. --> vc roda um for para percorrer o vetor dos acertos para ver se a pessoa já adivinhou alguma letra, se sim, imprimir, se não coloca um _
	
		system("cls");
	
		printf("Vidas: %d\n\n", vidas); // mostra a quantidade de vidas do jogador que está adivinhando
	
		cont_let_total_acertos = 0;
	
		// imprime as lacunas ou as letras já adivinhadas
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
						
						contem = 1; // verifica se dentre as letras já acertadas, se encaixa com a posição da letra na palavra
						
						cont_let_total_acertos++; // conta para ver se o jogador que está adivinhando já acertou todas as letras da palavra
					}
				}
				
				if (contem != 1)
				{
					printf("_ ");
				}
			}
			else // se não tiver acertos ainda, só preenche com _
			{
				printf("_ ");
			}
		}
		
		if (cont_let_total_acertos == tamanho) // verifica se o jogador que está adivinhando já ganhou (lembra que contamos as letras ali em cima)
		{
			printf("\n\nParabéns %s, você venceu!\n\n", j2);
			
			break; // faz ele sair do while
		}
		
		if (erros > 0) // mostra as letras que o usuario já informou e não estão contidas na palavra a ser adivinhada
		{
			printf("\n\nLetras erradas: ");
			for (erro = 0; erro < erros; erro++)
			{
				printf("%c ", letras_erradas[erro]);
			}
		}
		// IMPEDIR QUE O USUÁRIO INFORME UMA LETRA JÁ INFORMADA
		do {
			contem = 0;
			
			printf("\n\nDigite uma letra: ");
			fflush(stdin);
			scanf("%c", &letra);
			
			for (acerto = 0; acerto < acertos; acerto++) // verifica se a letra informada já está contida entre as certas informadas
			{
				if (letras_certas[acerto] == letra)
				{
					contem = 1; // se sim, muda o valor do contem para repetir o while até que o usuário informe uma letra nunca informada antes
					
					break; // se encontrar uma repetida já sai do laço
				}
			}
			
			for (erro = 0; erro < erros; erro++) // verifica se a letra informada já está contida entre as erradas informadas
			{
				if (letras_erradas[erro] == letra)
				{
					contem = 1; // se sim, muda o valor do contem para repetir o while até que o usuário informe uma letra nunca informada antes
					
					break; // se encontrar uma repetida já sai do laço
				}
			}
			
			if (contem == 1)
			{
				printf("\nLetra já informada! Tente novamente."); // mensagem de aviso
			}
		} while (contem == 1);
		
		// VERIFICA SE A LETRA INFORMADA PELO USUARIO É CERTA OU ERRADA
		for (let = 0; let < tamanho; let++)
		{
			if (palavra[let] == letra) // se ele acertou
			{
				printf("\nVocê acertou a letra!\n\n"); // mensagem de aviso
				
				letras_certas[acertos] = letra; // adiciona a letra adivinhada às outras tbm adivinhadas (deve vir primeiro que o incremento abaixo)
				
				acertos++; // adiciona à quantidade de acertos uma unidade
				
				break; // sai desse laço for
			}
			else if (let == tamanho - 1) // se chegou na última repetição do laço e não foi constatado o acerto
			{
				printf("\nVocê errou a letra!\n\n"); // mensagem de aviso
				
				letras_erradas[erros] = letra; // adiciona a letra errada às outras tbm erradas (deve vir primeiro que o incremento abaixo)
				
				erros++; // adiciona à quantidade de erros uma unidade
				
				vidas--; // tira uma vida
				
				if (vidas == 0) // se as vidas tiverem chegado a zero
				{
					printf("%s você perdeu! A palavra era %s.\n\nParabéns %s!\n\n", j2, palavra, j1); // mensagem de aviso
					
					// quando for fazer a próxima repetição do while lá em cima, ele não vai rodar de novo pois as vidas não vão ser maiores que 0 (vai ser zero)
				}
			}
		}
		
		system("pause"); // pausa o andamento do programa para que as informações possam ser visualizadas na tela
	}
	
	return 0;
}
