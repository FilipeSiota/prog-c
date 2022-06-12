#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct contato CONTATO;
struct contato{
	char nome[40];
	char telefone[20];
};

void cabecalho();
void cadastrar();
void listar();
void consultar();


int main(){
	setlocale(LC_ALL,"Portuguese");
 	int op;
 	
	//Tela inicial, com menú//
	do{
		cabecalho();
		printf("1 - Cadastrar\n");
		printf("2 - Listar \n");
		printf("3 - Consultar \n");
		printf("4 - Excluir \n");
		printf("5 - Sair \n");
		printf("Escolha uma opção:\n");
		scanf("%d" ,&op);
		
		switch(op){
			
			case 1:
				cadastrar();
				
			break;
			
			case 2:
				listar();
			break;
			
			case 3:
				consultar();
			break;
			
			case 4:
		        excluir();
			break;
			
			default:
				printf("Opcao invalida!");
				getch();
			break;
		}
		
	}while(op!=5);
	return 0;
}

//Função com o cabeçalho//

void cabecalho(){
	system("cls");
	printf("---------------\n");
	printf("   |Agenda|\n");
	printf("---------------\n");
}
//Função para fazer o cadastro//

void cadastrar(){
	FILE* arquivo;
	CONTATO ctt;
	int resp;
	

	
	arquivo = fopen("agenda.txt", "ab");
	if (arquivo==NULL){
		printf("Problema na abertura do arquivo");
		
	}
	else{
		do{
		
			cabecalho();
		
		fflush(stdin);
		printf("Digite o nome:");
		gets(ctt.nome);	
		
		fflush(stdin);
		printf("Digite o telefone:");
		gets(ctt.telefone);
		
		fwrite(&ctt, sizeof(CONTATO),1,arquivo);
		printf("Deseja continuar?\n");
		printf("0 - Sair\n");
		printf("1- Continuar \n");
		scanf("%d" ,&resp);
		
		system("cls");
		
		}while(resp == 1);
		fclose(arquivo);
	}
	
}
//Função para listar os dados digitados até agora//

void listar(){

	FILE* arquivo;
	CONTATO ctt;
	
	cabecalho();
	arquivo = fopen("agenda.txt", "rb");
	if (arquivo==NULL){
		printf("\nProblema na abertura do arquivo\n");
		
	}
	else{
		while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1){
			printf("\nNome:%s\n", ctt.nome);
			printf("\nTelefone:%s\n", ctt.telefone);
		}
	}
	fclose(arquivo);
	getch();
}
//Função para consultar um dado especifico//

void consultar(){
	FILE* arquivo;
	CONTATO ctt;
	char nome[30];
	
	cabecalho();	
	arquivo = fopen("agenda.txt", "rb");
	if (arquivo==NULL){
		printf("Problema na abertura do arquivo!\n");
		
	}
	else{
		fflush(stdin);
		printf("Digite o nome que você quer pesquisar:\n");
		gets(nome);
		
		while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1){
			if (strcmp(nome,ctt.nome)==0){
				printf("\nNome:%s\n", ctt.nome);
				printf("\nTelefone:%s\n", ctt.telefone);
			}
			
		}
	}
	fclose(arquivo);
	getch();
}
//Função para a exclusão de um dado especifico//

void excluir(){
	FILE* arquivo;
	FILE* arqsaida;
	CONTATO ctt;
	char procurado[30];


	cabecalho();

	arquivo = fopen("agenda.txt", "rb");
	arqsaida = fopen("agenda_nova.txt", "w");

	if (arquivo ==NULL || arqsaida == NULL){
		printf("Problema na abertura do arquivo!\n");
		return;
	}
	else{
		fflush(stdin);
		printf("Digite o nome que você quer apagar:\n");
		gets(procurado);

		while(!feof(arquivo)){
            fread(&ctt,sizeof(CONTATO),1,arquivo);

			if (strcmp(procurado,ctt.nome)==0){
                printf("Contato encontrado %s!\n",ctt.nome);
                fwrite(NULL, sizeof(CONTATO), 1, arqsaida);
			}else{
			    if(feof(arquivo)) break;
                fwrite(&ctt, sizeof(CONTATO),1,arqsaida);
            }
		}
	}

	fclose(arquivo);
	fclose(arqsaida);

    //remove backup antigo / novo backup / agenda final
    remove("agenda_backup.txt");
  	rename("agenda.txt", "agenda_backup.txt");
  	rename("agenda_nova.txt", "agenda.txt");
  	
	getch();
}
