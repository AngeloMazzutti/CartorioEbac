#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registrar () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file, cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	//scanf("%s", nome)
	getchar(); // Limpa o caractere de nova linha pendente no buffer
	fgets(nome, sizeof(nome), stdin); // L� uma linha inteira, incluindo espa�os em branco	
	nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome	
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);	
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	//scanf("%s", sobrenome);
	fgets(sobrenome, sizeof(sobrenome), stdin); // L� uma linha inteira, incluindo espa�os em branco
	sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove a nova linha do final do sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	fclose(file);
	
}

int consultar ()
{
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a Linguagem
	 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar ()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso e n�o se encontra no sistema!.\n");
		fclose(file);
		system ("pause");
	}
	
	fclose(file);
}

int main ()
{
	int opcao=0; //Definindo as Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //Respons�vel por limpar a tela
	
	
	    setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu		
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
    	printf("\t3 - Deletar Nomes\n\n");
    	printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //Final do Menu
    
    	scanf("%d", &opcao); //Armazenando a escolha do Usu�rio
	
		system("cls");
		
		
		switch(opcao) //In�cio da sele��o do Menu
		{
			case 1:
			registrar(); //Chamada de Fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por Utilizar o Sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
	   		printf("\tTente Novamente!\n"); 
	   		system("pause");
		    break;
				
				
		}
	
			
	}
}
