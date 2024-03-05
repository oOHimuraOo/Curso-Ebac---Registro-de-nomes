#include <stdio.h> //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca respons�vel por localiza��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por gerir as strings

int main (){//Fun��o responsavel pelo menu principal.
	int opcoes_do_menu = 0; //Vari�vel respons�vel por armazenar a op��o escolhida pelo usu�rio.
	int repeticao = 1;
	char usuario_digitado[50];
	char senha_digitada[50];
	char verificador_de_senha[50] = "admin";
	int valor = 0;
	int valor_2 = 0;
	
	setlocale(LC_ALL, "Portuguese"); //Fun��o respons�vel por ativar a localiza��o idiom�tica.
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("por favor digite seu usuario: \n\n");
	
	printf("digite aqui: ");
	scanf("%s",usuario_digitado);
	
	system("cls");
	
	valor = strcmp(usuario_digitado,verificador_de_senha);
	//FILE *file;
	//file = fopen(usuario_digitado,"r"); era pra ser assim, pois dessa forma voc� consegue buscar no banco de dados a informa��o de admin, mas como n�o posso inviabilizar o acesso dos professores. To mantendo da forma padr�o.
	
	if (valor == 0){//tem que substituir essa linha por "if (file != NULL){"
		printf("### Cart�rio da EBAC ### \n\n");
		printf("Por favor digite sua senha: \n\n");
	
		printf("digite aqui: ");
		scanf("%s",senha_digitada);
	
		system("cls");
		
		//while(fgets(verificador_de_senha, 50, file) != NULL){ 
		//}
		//tem que descomentar as linhas 36 e 37
		
		valor_2 = strcmp(senha_digitada,verificador_de_senha);
		
		if (valor_2 == 0){//tem que substituir essa linha por "if (valor == 0){"
			//fclose(file); tem que descomentar essa linha.
			for (repeticao = 1; repeticao = 1;){ //O loop "for" pode ser utilizado dessa forma para criar um la�o de repeti��o. Porem a logica padr�o dele � for(x=0;x=10;x++) obs.: voc� pode fazer negativo tamb�m.
			
				system("cls");
			
				printf("### Cart�rio da EBAC ### \n\n");
				printf("Escolha a op��o desejada do menu: \n\n");
				printf("\t1) Registrar nomes. \n");
				printf("\t2) Consultar nomes. \n");
				printf("\t3) Apagar nomes. \n");
				printf("\t4) Sair. \n\n\n");
			
				printf("Digite aqui: ");
				scanf("%d", &opcoes_do_menu); //Fun��o respons�vel por solicitar uma informa��o do usu�rio quando lidando com vari�veis do tipo inteiro
			
				system("cls"); //Fun��o respons�vel por limpar as informa��es impressas no inspetor anteriormente.
		
				switch (opcoes_do_menu){
					case 1:
						registrar_nomes();
						break;
					case 2:
						consultar_nomes();
						break;
					case 3:
						apagar_nomes();
						break;
					case 4:
						finlizar_programa();
						return 0;
						break;
		
					default:
						input_invalido();
						break;
				}
			}
		}
		else{
			printf("senha n�o encontrada. \n");
			printf("finalizando aplica��o.");
		}
	}
	else{
		printf("usuario n�o encontrado. \n");
		printf("finalizando aplica��o.");
	}
}

int registrar_nomes(){//Fun��o respons�vel por criar informa��es novas no banco de dados.
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	char matricula[100];
	char conteudo[500];
	int opcao_do_menu = 0;
	int opcao_do_menu_2 = 0;

	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("Digite o CPF que voc� deseja cadastrar: ");
	scanf("%s", cpf);//Fun��o respons�vel por permitir que o usu�rio armazene informa��es em vari�veis do tipo string.
		
	//Pretendo substituir essa c�pia de valores, por um sistema de gera��o de valor para poder armazenar na vari�vel matricula. Buscando melhorar o sistema de busca.
	strcpy(matricula, cpf); //Fun��o respons�vel por permitir que uma vari�vel do tipo string tenha seus valores copiados para outra vari�vel do tipo string.
	
	FILE *file; //Trecho respons�vel pela cria��o de arquivo.
	file = fopen(matricula,"r");
	if (file == NULL){
		fclose(file);
		
		printf("Digite o nome: ");
		scanf("%s", nome);
	
		printf("Digite o sobrenome: ");
		scanf("%s", sobrenome);
	
		printf("Digite o cargo: ");
		scanf("%s", cargo);
		
		file = fopen(matricula, "w"); //Aqui voc� est� informando que voc� que o arquivo que voc� deseja abrir seja o arquivo com o nome igual ao valor registrado na matr�cula. O "W" significa que � um arquivo novo e que voc� est� escrevendo o nome agora.
		fprintf(file,cpf); //Salva a informa��o da vari�vel no arquivo
		fclose(file); //Fecha o arquivo.
		
		file = fopen(matricula, "a");//O "a" serve para simbolizar que voc� quer apenas abrir o arquivo com o nome armazenado na vari�vel em quest�o.
		fprintf(file,", ");
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file, nome);
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file," ");
		fclose(file);
		
		file = fopen(matricula, "a");
		fprintf(file, sobrenome);
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file,", ");
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file, cargo);
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file,", ");
		fclose(file);
	
		file = fopen(matricula, "a");
		fprintf(file, matricula);
		fclose(file);	
		
		printf("Deseja inserir um novo nome?\n\n");
		printf("\t1) Sim.\n");
		printf("\t2) N�o. \n\n");
		
		printf("Digite aqui: ");
		scanf("%d",&opcao_do_menu_2);
		switch (opcao_do_menu_2){
			case 1:
				registrar_nomes();
				break;
			case 2:
				printf("Retornando para o menu principal.\n");
				system("pause");
				break;
			default:
				input_invalido();
				break;
		}
	}
	else {
		printf("CPF j� cadastrado. Deseja consultar informa��es do CPF?\n\n");
		printf("\t1) Sim.\n");
		printf("\t2) N�o. \n\n");
		
		printf("Digite aqui: ");
		scanf("%d", &opcao_do_menu);
		
		if (opcao_do_menu == 1){
			while(fgets(conteudo, 500, file) != NULL){//Esse � o loop "while". Esse loop vai rodar enquanto o arquivo registrado na vari�vel "file" possuir informa��o para ser armazenada na vari�vel "conte�do". Aten��o: a quantidade m�xima de informa��o que ser� armazenada na vari�vel conte�do � 500 caracteres.
			printf("\nEssas s�o as informa��es de usu�rio desejadas:\n");
			printf("%s", conteudo);
			printf("\n\n");
			}
			fclose(file);
		}
	}
}

int consultar_nomes(){//Fun��o responsavel por verificar a forma de consulta que o usuario deseja executar.
	int opcoes_do_menu = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("Escolha a forma como voc� deseja realizar sua consulta: \n\n");
	printf("\t1) CPF. \n");
	printf("\t2) Matricula. \n\n");
	
	printf("Digite aqui: ");
	scanf("%d", &opcoes_do_menu);
	
	switch (opcoes_do_menu){
		case 1:		
			verificar_via_cpf();
			break;
		case 2:
			printf("Infelizmente essa op��o est� temporariamente indispon�vel. \n");
			system("pause");
			break;
		default:
			printf("Op��o invalida. \n");
			system("pause");
			consultar_nomes();
			break;
	}
	
}

int verificar_via_cpf(){//Fun��o responsavel por puxar as informa��es do usuario via CPF.
	char cpf[100];
	char conteudo[500];
	int opcao_do_menu = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("Por favor digite o CPF desejado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL){
		printf("CPF n�o encontrado. \n");
		printf("deseja tentar novamente?. \n\n");
		printf("\t1) Sim \n");
		printf("\t2) N�o \n");
		
		printf("Digite aqui: ");
		scanf("%d", &opcao_do_menu);
		
		if (opcao_do_menu == 1){
			verificar_via_cpf();	
		}
		else
			consultar_nomes();
	}
	else{
		printf("CPF encontrado! \n");
		
		while(fgets(conteudo, 500, file) != NULL){
			printf("\nEssas s�o as informa��es de usu�rio desejadas:\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
		
	fclose(file);	
	system("pause");
}

int apagar_nomes(){//Fun��o responsavel por verificar a forma que o usuario deseja encontrar o iten a ser apagado.
	int opcao_do_menu_1 = 0;

	setlocale(LC_ALL, "Portuguese");
	
	system ("cls");
	
	printf("Como voc� deseja encontrar qual item voc� deseja apagar? \n\n");
	printf("\t1)CPF.\n");
	printf("\t2)Matricula. \n\n");
	
	printf("Digite aqui: ");
	scanf("%d",&opcao_do_menu_1);
	
	switch (opcao_do_menu_1){
		case 1:
			apagar_nome_via_cpf();
			break;
		case 2:
			printf("Infelizmente essa op��o est� temporariamente indispon�vel. \n");
			system("pause");
			apagar_nomes();
			break;
		default:
			input_invalido();
			break;
	}	
}

int apagar_nome_via_cpf(){//Fun��o responsavel por apagar entradas utilizando o cpf.
	char cpf[100];
	char conteudo[500];
	int opcao_do_menu = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("Digite aqui o cpf desejado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf,"r");
		
	if (file != NULL){
		printf("O cpf encontrado corresponde a seguinte informa��o:\n\n");
			
		while(fgets(conteudo, 500, file) != NULL){
			printf("%s", conteudo);
			printf("\n\n");
			
			printf("voc� deseja apagar essa entrada do banco de dados? \n\n");
			printf("\t1)Sim.\n");
			printf("\t2)N�o.\n\n");
				
			printf("Digite aqui: ");
			scanf("%d", &opcao_do_menu);
				
			switch (opcao_do_menu){
				case 1:
					system("cls");
					fclose(file);
					remove(cpf);
					printf("Entrada apagada com sucesso!\n\n");
					system("pause");
					break;
		
				case 2:
					fclose(file);
					apagar_nomes();
					break;
		
				default:
					fclose(file);
					input_invalido();
					break;
			}
		}
	}
	else{
		system("cls");
		printf("CPF n�o cadastrado. \n\n");
		system("pause");
	}
}

int finlizar_programa(){//Fun��o responsavel por fechar o programa
	printf("Voc� escolheu sair. \n");
	printf("Obrigado por utilizar esse software. \n\n");
	printf("software em desenvolvimento por Felipe Cerqueira. Aluno EBAC.");
}

int input_invalido(){//fun��o responsavel para revelar que o usuario inseriu alguma informa��o invalida.
	printf("O charactere digitado � inv�lido. \n");
	system("pause");
}
