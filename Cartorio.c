#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //faz o scan do que o usu�rio digita %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //o A atualiza o arquivo 
	fprintf(file,","); // coloca v�rgula entre as informa��es
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string e salva
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo
	fprintf(file,","); //coloca a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose (file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //coloca a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo); //%s refere-se a string vari�vel
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //o comando FILE acessa o arquivo
	file = fopen(cpf, "r"); //"r" � de read = ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquando busca o conte�do e for difente de null
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system ("pause");
     


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //respons�vel por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf ("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf ("Escolha a op��o desejada do menu:\n\n");
    	printf ("\t1 - Registrar nomes\n");
    	printf ("\t2 - Consultar nomes\n");
    	printf ("\t3 - Deletar nomes\n\n"); 
    	printf("Opc�o:");//fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	
    	switch(opcao) //inicio da sele��o do menu
    	{
    		case 1: 
    		registro(); //chamada das fun��es
    		break;
    		
    		case 2: 
    		consulta();
    		break;
    		
    		case 3: 
    		deletar();
    		break;
    		
    		default: 
    		printf("Essa op��o n�o est� dispon�vel!\n");
    		system("pause");
    		break;
		} //fim da sele��o do menu
    	
    }
}
