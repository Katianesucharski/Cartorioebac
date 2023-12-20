#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espcao em memoria
#include <locale.h> // biblioteca de alocacao de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis
    char arquivo[40]; 
	char cpf[40]; 
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //inicio criacao de variaveis
    
    printf("digite o CPF a ser cadastrado:"); //coletando informacao do usuario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo,cpf); //responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); // fechar o arquivo
    
    file = fopen(arquivo, "a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
	    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser perguntado:");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	   printf("\nEssas são as informações do usuário:");
	   printf("%s", conteudo);
	   printf("\n\n");
	}
		
	fclose(file);
	system("pause");
		
}

int deletar()
{
       char cpf[40];
    
       printf("Digite o CPF do usuário a ser deletado:");
       scanf("%s",cpf);
    
       remove(cpf);
    
       FILE *file;
       file = fopen(cpf,"r");
    
       if(file == NULL)
    {
       printf("O usuário não se encontra no sistema!\n");
       system("pause");
    	
	}
    fclose(file);
    
}

int main()
    {
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

	 system("cls");
	 
	 setlocale(LC_ALL, "Portuguese");   //definindo a linguagem
	
	 printf("### Cartorio da EBAC ###\n\n");   //inicio do menu
	 printf("Escolha a opcao desejada do menu:\n\n");
	 printf("\t1 - Registarr nomes.\n");
	 printf("\t2 - Consultar nomes.\n");
	 printf("\t3 - Deletar nomes.\n\n"); 
	 printf("Opção:\t"); //fim do menu
		
	 scanf("%d", &opcao); // armazenando a escolha do usuario
	
	 system("cls"); //responsavel por limpar a tela
	
	
	switch(opcao) //inicio da selecao menu
    {
		
		case 1:
		registro(); // chamda de funcoes
		break;
			
		case 2:
		consulta();
		break;
			
		case 3:
        deletar();
		break;	
		
	
			
		default:
		printf("Essa opção não esta disponivel\n");
		system("pause");
		break;	
    }
	
    }
 
}
