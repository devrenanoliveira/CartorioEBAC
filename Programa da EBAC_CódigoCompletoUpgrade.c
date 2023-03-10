#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o
#include <string.h> //biblioteca respons?vel por cuidar das strings

int registro() //fun??o REGISTRO criada, sendo poss?vel chamar ela em outro momento do c?digo, no caso, no momento em que iniciamos o SWITCH
{
	char nomeArquivo[40]; //cria??o de uma STRING CPF com 40 caracteres
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	char textoFinal[400];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // O %s significa armazenamento da STRING
	
	strcpy(nomeArquivo, cpf); //respons?vel por copiar os valores das string
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	strcpy(textoFinal, "CPF: ");
	strcat(textoFinal, cpf);
	strcat(textoFinal, "\n");
	strcat(textoFinal, "NOME: ");
	strcat(textoFinal, nome);
	strcat(textoFinal, "\n");
	strcat(textoFinal, "SOBRENOME: ");
	strcat(textoFinal, sobrenome);
	strcat(textoFinal, "\n");	
	strcat(textoFinal, "CARGO: ");
	strcat(textoFinal, cargo);
	
	FILE *file; // FILE = acessa o arquivo e *file = cria/consulta o arquivo
	file = fopen(nomeArquivo, "w"); //aqui significa dizer: abra um arquivo (fopen) com o nome do que estiver dentro da vari?vel arquivo e ? um arquivo novo ("w")
	fprintf(file,textoFinal); //salvo o valor da vari?vel
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta() //fun??o CONSULTA criada, sendo poss?vel chamar ela em outro momento do c?digo, no caso, no momento em que iniciamos o SWITCH
{

	setlocale(LC_ALL, "Portuguese"); //defini??o do local como portugu?s para poder colocar os ascentos
	
	char cpf[40];
	char conteudo[40];
	char textoFinal[400];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //O "r" ? de READ (ler)

	
	if(file == NULL)
	{
		printf("\nN?o foi poss?vel abrir o arquivo, n?o foi localizado.\n\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL) 
	{
		strcat(textoFinal, conteudo);
	}
	
	printf(textoFinal);
	printf("\n");
		
	system("pause");
}

int deletar() //fun??o DELETAR criada, sendo poss?vel chamar ela em outro momento do c?digo, no caso, no momento em que iniciamos o SWITCH
{
	
	char cpf[40];
	
	printf("Digite o usu?rio que deseja deletar o sistema: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("\nO usu?rio n?o se encontra no sistema!\n\n");
		system("pause");
	}

	else
	{
		printf("\nUsu?rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao = 0;
	int laco=1;
	
	for(laco=1;laco=1;) //tradu??o: fa?a quantoas vezes eu pedir -> a vari?vel LACO enquanto for valor 1 (entrada), ele deve ficar no "for" at? 1x o menu (sa?da) e sempre subindo 1 (x++)
	{
		
		system("cls"); //limpo a tela de op??es para deixar o programa mais amig?vel e organizado para o usu?rio
		
		setlocale(LC_ALL, "Portuguese"); //defini??o do local como portugu?s para poder colocar os ascentos
	
		printf(" ### Bem-vinda(o) ao Cart?rio da EBAC ### \n\n"); //in?cio do menu
		printf("Escolha a op??o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("\nOp??o: "); //fim do menu
	
		scanf ("%d", &opcao); //armazenando a escolha do usu?rio
	
		system("cls"); //limpo a tela de op??es para deixar o programa mais amig?vel e organizado para o usu?rio
	
	
		switch (opcao) //in?cio da sele??o
		{
			case 1: //caso a vari?vel tenha valor 1 ele tem que fazer a instru??o abaixo
			registro(); //chamando a fun??o REGISTRO criada no in?cio do c?digo, antes da fun??o principal MAIN
			break;
			
			case 2:	//caso a vari?vel tenha valor 2 ele tem que fazer a instru??o abaixo
			consulta(); //chamando a fun??o CONSULTA criada no in?cio do c?digo, antes da fun??o principal MAIN
			break;
			
			case 3: //caso a vari?vel tenha valor 3 ele tem que fazer a instru??o abaixo
			deletar(); //chamando a fun??o DELETAR criada no in?cio do c?digo, antes da fun??o principal MAIN
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //? o fun??o para sair do sistema
			break;

			default: //caso a vari?vel tenha valor diferente de 1, 2 ou 3, ele tem que fazer a instru??o abaixo
			printf("Op??o inv?lida! Voc? ser? redirecionado ao menu inicial para escolher uma op??o v?lida. \n\n");
			system("pause");
			break;
		}
		
	}
	
}
