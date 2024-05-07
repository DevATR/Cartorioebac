#include <stdio.h>//biblioteca de comunicaçao com o usúario
#include <stdlib.h>//biblioteca de locaçao de armazenamento
#include <string.h>//biblioteca das strings
#include <locale.h>//biblioteca de localizaçao

int registro(){ //funçao responsavel para o usuario cadastrar


setlocale(LC_ALL, "portuguese"); //setando a localizacao
char arquivo[40];//criaçao de variaveis(strings)
char cpf[40];
char nome[40];
char sobrenome[40];
char cargo[40];

printf("Digite o CPF:"); //pergunta ao usuario
fflush(stdin);  // para o cliente poder usar o (espaço) na hora da pesquisa
scanf("%s", cpf);// esperando respota do usuario

strcpy(arquivo, cpf); // copiando as strings

FILE *file; //abrindo arquivo
file = fopen(arquivo, "w"); // w = escrever r= ler a = atualizar
fprintf(file,cpf);
fclose(file);

file = fopen(arquivo, "a"); 
fprintf(file,"\nNome:"); // deixando mais pratico para o usuario
fclose(file);

printf("\n\nDigite o nome:"); //perguntando ao usuario
fflush(stdin);
scanf("%s", nome);

file = fopen(arquivo, "a");//atualizando e salvando o file = arquivo no nome
fprintf(file,nome);
fclose(file);

file=fopen(arquivo, "a");
fprintf(file, "\nSobrenome: ");
fclose(file);

printf("Digite o sobrenome:");
fflush(stdin);
scanf("%s", sobrenome);

file = fopen(arquivo, "a");
fprintf(file,sobrenome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file, "\nCargo:");
fclose(file);

printf("\n\n\nDigite o cargo:");
fflush(stdin);
scanf("%s", cargo);

file = fopen(arquivo, "a");
fprintf(file,cargo);
fclose(file);

file=fopen(arquivo, "a");
fprintf(file, "\n\n");
fclose(file);

system("pause");

}

int consulta(){ //funcao resposvael para o usuario consultar
	
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	fflush(stdin);
	scanf("%s", cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL){ //validando caso seja nulo 
	printf("\t\tNão foi Possivel abrir o arquivo/Não localizado\n\n");// avisando o usuario caso seja nulo
	}
	
	while (fgets(conteudo, 200, file) != NULL){ //while = enquanto... fgets = buscando arquivo (conteudo)200 max count, lugar da busca... ! validando se for nulo
	printf("%s",conteudo);
	printf("\n\n");
	}
	
	system("pause");
	
}

int deletar(){ //funcao responsavel para o usuario deletar
	char cpf[40];
	printf("\t\n\nDigite o CPF a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	remove(cpf); //removendo o cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
	printf("\t\t\n\nCPF deletado do sistema...\n\n");//validando para o usuario
	system("pause");
	}
	
}

int main(){ // funcao principal..(MENU)
	
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;){
		
		system("color f0");//cor do sistema
		system("cls");
		setlocale(LC_ALL, "portuguese");
		
	printf("\t\t## Cartório da EBAC ##\n");//menu
	printf("\n\tEscola Britânica de artes criativas & tecnologia\n\n\n");
	printf("1- Registrar Cliente\n\n");
	printf("2- Consultar Cliente\n\n");
	printf("3- Deletar Cliente\n\n");
	printf("Digite a opção:");
	scanf("%d", &opcao);
	
	    system("cls");
	    
    switch(opcao){ // criando as telas
	
    
    case 1:
    registro();
    break;
    
    case 2:
    consulta();
    break;
    
    case 3:
    deletar();
    break;
    
    default:
    printf("\topção inexistente...\n\n");
    system("pause");
    break;
	
	}
	}
}
