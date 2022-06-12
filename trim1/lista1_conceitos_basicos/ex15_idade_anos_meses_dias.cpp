/*
15. Escreva um programa que pergunte o nome e a idade de um indivíduo (em
anos, meses e dias) e imprima (aproximadamente) quantos dias de vida ele
possui
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int day, month, year;

int getDate() {
	time_t date; // declara um objeto time_t
	struct tm *info; // declara um objeto tm
	
	time(&date); // tempo em segundos desde (00:00:00 UTC, January 1, 1970)
	/* Get GMT time */
	info = gmtime(&date); // transforma em um (tm object) no qual é possível ligá-lo a variáveis de calendário
	
	day = info->tm_mday; // pega o dia da data atual
	month = (info->tm_mon) + 1; // pega o mês (de 0 a 11) da data atual
	year = (info->tm_year) + 1900; // pega o ano (desde 1900, ou seja, seria 121) atual
	
	printf("Data atual: %.2d/%.2d/%d\n\n", day, month, year);
	
	return 0;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char nome[50];
	int dNasc, mNasc, aNasc;
	unsigned int diasNasc, diasAtual;
	
	getDate();
	
	printf("Nome: ");
	gets(nome);
	
	printf("Data de Nascimento: ");
	scanf("%d/%d/%d", &dNasc, &mNasc, &aNasc);
	
	diasAtual = day + (month * 30) + ((year - 1900) * 360); // data atual em dias
	
	diasNasc = dNasc + (mNasc * 30) + ((aNasc - 1900) * 360); // data de nascimento em dias
	diasNasc = diasAtual - diasNasc;
	
	printf("\nA sua idade é de, aproximadamente, %d dias ou %d anos, %d meses e %d dias.\n\n", diasNasc, diasNasc / 360, (diasNasc % 360) / 30, (diasNasc % 360) % 30);
	
	system("pause");
	return 0;
}
