/* 4. Escreva um programa que contenha uma estrutura representando uma data
v�lida. Essa estrutura deve conter os campos dia, m�s e ano. Em seguida, leia
duas datas e armazene nessa estrutura. Calcule e exiba o n�mero de dias que
decorrem entre as duas datas. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
	int dia;
	int mes;
	int ano;
	
} Data;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Data data1, data2;
	int periodo_dias;
	
	printf("Informe a 1� data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
	
	printf("Informe a 2� data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
	
	if (data1.ano > data2.ano)
	{
		periodo_dias = (data1.ano - data2.ano) * 365 + data1.mes * 30 + data1.dia - data2.mes * 30 - data2.dia;
	}
	else
	{
		periodo_dias = (data2.ano - data1.ano) * 365 + data2.mes * 30 + data2.dia - data1.mes * 30 - data1.dia;
	}
	
	printf("\nO per�odo entre essas datas corresponde a aproximadamente %d dias.\n\n", periodo_dias);
	
	system("pause");
	return 0;
}
