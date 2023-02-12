#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função REGISTRO criada, sendo possível chamar ela em outro momento do código, no caso, no momento em que iniciamos o SWITCH
{
	char nomeArquivo[40]; //criação de uma STRING CPF com 40 caracteres
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	char textoFinal[400];
	int opcao = 0;
		
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // O %s significa armazenamento da STRING
	
	strcpy(nomeArquivo, cpf); //responsável por copiar os valores da string CPF no nome do arquivo (nomeArquivo)
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	strcpy(textoFinal, "\nCPF: ");
	strcat(textoFinal, cpf);
	strcat(textoFinal, "\n\n");
	strcat(textoFinal, "NOME: ");
	strcat(textoFinal, nome);
	strcat(textoFinal, "\n\n");
	strcat(textoFinal, "SOBRENOME: ");
	strcat(textoFinal, sobrenome);
	strcat(textoFinal, "\n\n");	
	strcat(textoFinal, "CARGO: ");
	strcat(textoFinal, cargo);
	strcat(textoFinal, "\n");
	
	FILE *file; // FILE = acessa o arquivo e *file = cria/consulta o arquivo
	file = fopen(nomeArquivo, "w"); //aqui significa dizer: abra um arquivo (fopen) com o nome do que estiver dentro da variável arquivo e é um arquivo novo ("w")
	fprintf(file,textoFinal); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	printf("\nDeseja continuar realizando novos cadastros?\n\n");
	printf("Se sim, digite 1.\n");
	printf("Caso não, digite 2.\n");
	scanf("%d", &opcao);
	
    switch (opcao)
	{
    	case 1:
    	registro();
        break;
      	
		case 2:
        main();
        break;
        
		default: //caso a variável tenha valor diferente de 1, 2 ou 3, ele tem que fazer a instrução abaixo
		printf("Opção inválida! Você será redirecionado ao menu inicial para escolher uma opção válida. \n\n");
		system("pause");
		break;
    }
}

int consulta() //função CONSULTA criada, sendo possível chamar ela em outro momento do código, no caso, no momento em que iniciamos o SWITCH
{

	setlocale(LC_ALL, "Portuguese"); //definição do local como português para poder colocar os ascentos
	
	char cpf[40];
	char conteudo[40];
	char textoFinal[400];
	int opcao = 0;
	
	printf("Digite o CPF a ser consultado: "); //Recebendo qual o usuário está sendo consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //O "r" é de READ (ler)

	
	if(file == NULL)
	{
		printf("\nNão foi possível abrir o arquivo, não foi localizado.\n\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL) 
	{
		strcat(textoFinal, conteudo);
	}
	
	printf(textoFinal);
	printf("\n");
		
	system("pause");
	
	printf("\nDeseja continuar consultando outros registros do sistema?\n\n");
	printf("Se sim, digite 1.\n");
	printf("Caso não, digite 2.\n");
	scanf("%d", &opcao);
	
    switch (opcao)
	{
    	case 1:
    	consulta();
        break;
      	
		case 2:
        main();
        break;
        
		default: //caso a variável tenha valor diferente de 1, 2 ou 3, ele tem que fazer a instrução abaixo
		printf("Opção inválida! Você será redirecionado ao menu inicial para escolher uma opção válida. \n\n");
		system("pause");
		break;
	}
}

int deletar() //função DELETAR criada, sendo possível chamar ela em outro momento do código, no caso, no momento em que iniciamos o SWITCH
{
	
	char cpf[40];
	int opcao = 0;
	
	printf("Digite o usuário que deseja deletar o sistema: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!\n\n");
		system("pause");
	}

	else
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}

	printf("\nDeseja continuar deletando outros registros do sistema?\n\n");
	printf("Se sim, digite 1.\n");
	printf("Caso não, digite 2.\n");
	scanf("%d", &opcao);
	
    switch (opcao)
	{
    	case 1:
    	deletar();
        break;
      	
		case 2:
        main();
        break;
        
		default: //caso a variável tenha valor diferente de 1, 2 ou 3, ele tem que fazer a instrução abaixo
		printf("Opção inválida! Você será redirecionado ao menu inicial para escolher uma opção válida. \n\n");
		system("pause");
		break;
	}

}

int main()
	{
	int opcao = 0;
	int laco=1;
	char senha[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //definição do local como português para poder colocar os ascentos	
	
	printf(" ### Bem-vinda(o) ao Cartório da EBAC ### \n\n"); //início do menu
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senha);
	
	comparacao = strcmp(senha, "admin"); //strcmp é COMPARAÇÃO DE STRINGS. Se a comparação for igual, o programa vai salvar um 0 (zero) na variavel "comparacao"
	
	if(comparacao == 0)
	{

		system("cls"); //limpo a tela de opções para deixar o programa mais amigável e organizado para o usuário
		
		for(laco=1;laco=1;) //tradução: faça quantoas vezes eu pedir -> a variável LACO enquanto for valor 1 (entrada), ele deve ficar no "for" até 1x o menu (saída) e sempre subindo 1 (x++)
		{	
			printf("\n ### Bem-vinda(o) ao Cartório da EBAC ### \n\n"); //início do menu		
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\nOpção: "); //fim do menu
	
			scanf ("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //limpo a tela de opções para deixar o programa mais amigável e organizado para o usuário
	
	
			switch (opcao) //início da seleção
			{
				case 1: //caso a variável tenha valor 1 ele tem que fazer a instrução abaixo
				registro(); //chamando a função REGISTRO criada no início do código, antes da função principal MAIN
				break;
			
				case 2:	//caso a variável tenha valor 2 ele tem que fazer a instrução abaixo
				consulta(); //chamando a função CONSULTA criada no início do código, antes da função principal MAIN
				break;
			
				case 3: //caso a variável tenha valor 3 ele tem que fazer a instrução abaixo
				deletar(); //chamando a função DELETAR criada no início do código, antes da função principal MAIN
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //é o função para sair do sistema
				break;

				default: //caso a variável tenha valor diferente de 1, 2 ou 3, ele tem que fazer a instrução abaixo
				printf("Opção inválida! Você será redirecionado ao menu inicial para escolher uma opção válida. \n\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta! Tente novamente.\n\n");
		system("pause");
		return main();
}
