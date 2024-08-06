#include <stdio.h> //BIBLIOTECA DE COMUNICA��O COM O USU�RIO
#include <stdlib.h> //BIBLIOTECA DE ALOCA��O DE ESPA�O EM MEM�RIA
#include <locale.h> //BIBLIOTECA DE ALOCA��O DE TEXTO POR REGI�O
#include <string.h> // BIBLIOTECA RESPONSAVELPOR CUIDAR DAS STRING

int registro() //FUN��O RESPONDALVEL POR CADASTRAR O USUARIO NO SISTEMA
{
	// INICIO DE CRI��O DE VARIAVEIS/STRING
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		// FINAL DA  CRI��O DE VARIAVEIS/STRING
	
	printf("Digite o cpf para ser cadastrado: ");
	scanf("%s", cpf); //%S REFERE-SE A STRING
	
	strcpy(arquivo, cpf); //RESPOSAVEL POR COPIAR OS VALORES DAS STRINGS
	
	FILE *file; //CRIA O ARQUIVO
	file = fopen(arquivo, "w"); // CRIA O ARQUIVO E O "W" SIGINIFICA ESCREVER
	fprintf(file,cpf); //SALVA O VALOR DA VARIAVEL
	fclose(file); //FECHA O ARQUIVO
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //COLETANDO INFORMA��O DO USUARIO
	scanf("%s",nome); //%S REFERE-SE A STRING
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
	
		
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //LER O ARQUIVO E O "R" SIGINIFICA LER
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquiovo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do us�ario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //LER O ARQUIVO
	
	if(file == NULL)
	{
				printf("O us�ario foi deletado do sistema! \n ");
				system("pause");
	}
}

int main() 
{
	int opcao=0; //DEFININDO VARIAVEIS
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	
		setlocale(LC_ALL, "portuguese"); //DEFININDO A LINGUAGEM
	
		printf("### Cart�r�o da EBAC ###\n\n"); //INICIO DO MENU
		printf("Escolha uma op��o desejada para seu menu:\n\n");
		printf("\t1 - Registra nome\n\n");
		printf("\t2 - Consulta nome\n\n");
		printf("\t3 - Deletar nome\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:"); //FIM DO MENU 
	
		scanf("%d", &opcao); //ARMAZENANDO A ESCOLHA DO USUARIO
		
		system("cls"); //RESPONSALVEL POR LIMPAR A TELA
		
		
		switch(opcao) //INICIO DA SELE��O DO MENU
		{
			case 1:
			registro(); //CHAMADA DE FUN��ES
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			
			
		}
	
	}
}


