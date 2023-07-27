#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registrar () //Função responsável por cadastrar os usuários no sistema
{
	// Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores dos string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	//scanf("%s", nome)
	getchar(); // Limpa o caractere de nova linha pendente no buffer
	fgets(nome, sizeof(nome), stdin); // Lê uma linha inteira, incluindo espaços em branco	
	nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome	
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);	
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	//scanf("%s", sobrenome);
	fgets(sobrenome, sizeof(sobrenome), stdin); // Lê uma linha inteira, incluindo espaços em branco
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar ()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário foi deletado com sucesso e não se encontra no sistema!.\n");
		fclose(file);
		system ("pause");
	}
	
	fclose(file);
}

int main ()
{
	int opcao=0; //Definindo as Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //Responsável por limpar a tela
	
	
	    setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a Linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu		
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
    	printf("\t3 - Deletar Nomes\n\n");
    	printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //Final do Menu
    
    	scanf("%d", &opcao); //Armazenando a escolha do Usuário
	
		system("cls");
		
		
		switch(opcao) //Início da seleção do Menu
		{
			case 1:
			registrar(); //Chamada de Funções
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
			printf("Essa opção não está disponível!\n");
	   		printf("\tTente Novamente!\n"); 
	   		system("pause");
		    break;
				
				
		}
	
			
	}
}
