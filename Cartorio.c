#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //faz o scan do que o usuário digita %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //o A atualiza o arquivo 
	fprintf(file,","); // coloca vírgula entre as informações
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string e salva
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo
	fprintf(file,","); //coloca a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome); //salva o valor da variável
	fclose (file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //coloca a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo); //%s refere-se a string variável
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, cargo); //salva o valor da variável
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
	file = fopen(cpf, "r"); //"r" é de read = ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquando busca o conteúdo e for difente de null
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system ("pause");
     


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //responsável por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf ("### Cartório da EBAC ###\n\n"); //inicio do menu
    	printf ("Escolha a opção desejada do menu:\n\n");
    	printf ("\t1 - Registrar nomes\n");
    	printf ("\t2 - Consultar nomes\n");
    	printf ("\t3 - Deletar nomes\n\n"); 
    	printf ("\t4 - Sair do Sistema\n\n");
    	printf("Opcão:");//fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls");
    	
    	
    	switch(opcao) //inicio da seleção do menu
    	{
    		case 1: 
    		registro(); //chamada das funções
    		break;
    		
    		case 2: 
    		consulta();
    		break;
    		
    		case 3: 
    		deletar();
    		break;
    		
    		case 4:
    		printf("Obrigada por utilizar o sistema!\n");
    		return 0;
    		break;
    		
    		default: 
    		printf("Essa opção não está disponível!\n");
    		system("pause");
    		break;
		} //fim da seleção do menu
    	
    }
}
