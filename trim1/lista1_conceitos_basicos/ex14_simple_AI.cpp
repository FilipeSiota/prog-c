/*
14. Escreva um programa para simular uma pequena conversa do computador com
o usu�rio. O programa deve seguir os passos:
	(a) inicialmente escreve "Ol� eu sou o N� 1, como � seu nome?";
	(b) em seguida espera que o usu�rio digite seu nome;
	(c) por fim escreve: "Bem-vindo ao clube (nome)�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const char PROGRAMA[26] = "AI from ZyonTech", AI[5] = "N� 1";

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char user[50];
	
	printf("%s - %s\n\n", PROGRAMA, AI);
	
	printf("%s: Ol�, eu sou a AI %s, como � seu nome?\n", AI, AI);
	
	printf("User: Meu nome � ");
	gets(user);
	
	printf("%s: Bem-vindo ao clube %s!\n\n", AI, user);
	
	system("pause");
	return 0;
}
