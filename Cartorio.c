#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca responsável por localização de texto por região
#include <string.h> //Biblioteca responsável por gerir as strings

int main (){//Função responsavel pelo menu principal.
	int opcoes_do_menu = 0; //Variável responsável por armazenar a opção escolhida pelo usuário.
	int repeticao = 1;
	char usuario_digitado[50];
	char senha_digitada[50];
	char verificador_de_senha[50] = "admin";
	int valor = 0;
	int valor_2 = 0;
	
	setlocale(LC_ALL, "Portuguese"); //Função responsável por ativar a localização idiomática.
	
	printf("### Cartório da EBAC ### \n\n");
	printf("por favor digite seu usuario: \n\n");
	
	printf("digite aqui: ");
	scanf("%s",usuario_digitado);
	
	system("cls");
	
	valor = strcmp(usuario_digitado,verificador_de_senha);
	//FILE *file;
	//file = fopen(usuario_digitado,"r"); era pra ser assim, pois dessa forma você consegue buscar no banco de dados a informação de admin, mas como não posso inviabilizar o acesso dos professores. To mantendo da forma padrão.
	
	if (valor == 0){//tem que substituir essa linha por "if (file != NULL){"
		printf("### Cartório da EBAC ### \n\n");
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
			for (repeticao = 1; repeticao = 1;){ //O loop "for" pode ser utilizado dessa forma para criar um laço de repetição. Porem a logica padrão dele é for(x=0;x=10;x++) obs.: você pode fazer negativo também.
			
				system("cls");
			
				printf("### Cartório da EBAC ### \n\n");
				printf("Escolha a opção desejada do menu: \n\n");
				printf("\t1) Registrar nomes. \n");
				printf("\t2) Consultar nomes. \n");
				printf("\t3) Apagar nomes. \n");
				printf("\t4) Sair. \n\n\n");
			
				printf("Digite aqui: ");
				scanf("%d", &opcoes_do_menu); //Função responsável por solicitar uma informação do usuário quando lidando com variáveis do tipo inteiro
			
				system("cls"); //Função responsável por limpar as informações impressas no inspetor anteriormente.
		
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
			printf("senha não encontrada. \n");
			printf("finalizando aplicação.");
		}
	}
	else{
		printf("usuario não encontrado. \n");
		printf("finalizando aplicação.");
	}
}

int registrar_nomes(){//Função responsável por criar informações novas no banco de dados.
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
	
	printf("Digite o CPF que você deseja cadastrar: ");
	scanf("%s", cpf);//Função responsável por permitir que o usuário armazene informações em variáveis do tipo string.
		
	//Pretendo substituir essa cópia de valores, por um sistema de geração de valor para poder armazenar na variável matricula. Buscando melhorar o sistema de busca.
	strcpy(matricula, cpf); //Função responsável por permitir que uma variável do tipo string tenha seus valores copiados para outra variável do tipo string.
	
	FILE *file; //Trecho responsável pela criação de arquivo.
	file = fopen(matricula,"r");
	if (file == NULL){
		fclose(file);
		
		printf("Digite o nome: ");
		scanf("%s", nome);
	
		printf("Digite o sobrenome: ");
		scanf("%s", sobrenome);
	
		printf("Digite o cargo: ");
		scanf("%s", cargo);
		
		file = fopen(matricula, "w"); //Aqui você está informando que você que o arquivo que você deseja abrir seja o arquivo com o nome igual ao valor registrado na matrícula. O "W" significa que é um arquivo novo e que você está escrevendo o nome agora.
		fprintf(file,cpf); //Salva a informação da variável no arquivo
		fclose(file); //Fecha o arquivo.
		
		file = fopen(matricula, "a");//O "a" serve para simbolizar que você quer apenas abrir o arquivo com o nome armazenado na variável em questão.
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
		printf("\t2) Não. \n\n");
		
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
		printf("CPF já cadastrado. Deseja consultar informações do CPF?\n\n");
		printf("\t1) Sim.\n");
		printf("\t2) Não. \n\n");
		
		printf("Digite aqui: ");
		scanf("%d", &opcao_do_menu);
		
		if (opcao_do_menu == 1){
			while(fgets(conteudo, 500, file) != NULL){//Esse é o loop "while". Esse loop vai rodar enquanto o arquivo registrado na variável "file" possuir informação para ser armazenada na variável "conteúdo". Atenção: a quantidade máxima de informação que será armazenada na variável conteúdo é 500 caracteres.
			printf("\nEssas são as informações de usuário desejadas:\n");
			printf("%s", conteudo);
			printf("\n\n");
			}
			fclose(file);
		}
	}
}

int consultar_nomes(){//Função responsavel por verificar a forma de consulta que o usuario deseja executar.
	int opcoes_do_menu = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf("Escolha a forma como você deseja realizar sua consulta: \n\n");
	printf("\t1) CPF. \n");
	printf("\t2) Matricula. \n\n");
	
	printf("Digite aqui: ");
	scanf("%d", &opcoes_do_menu);
	
	switch (opcoes_do_menu){
		case 1:		
			verificar_via_cpf();
			break;
		case 2:
			printf("Infelizmente essa opção está temporariamente indisponível. \n");
			system("pause");
			break;
		default:
			printf("Opção invalida. \n");
			system("pause");
			consultar_nomes();
			break;
	}
	
}

int verificar_via_cpf(){//Função responsavel por puxar as informações do usuario via CPF.
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
		printf("CPF não encontrado. \n");
		printf("deseja tentar novamente?. \n\n");
		printf("\t1) Sim \n");
		printf("\t2) Não \n");
		
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
			printf("\nEssas são as informações de usuário desejadas:\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
		
	fclose(file);	
	system("pause");
}

int apagar_nomes(){//Função responsavel por verificar a forma que o usuario deseja encontrar o iten a ser apagado.
	int opcao_do_menu_1 = 0;

	setlocale(LC_ALL, "Portuguese");
	
	system ("cls");
	
	printf("Como você deseja encontrar qual item você deseja apagar? \n\n");
	printf("\t1)CPF.\n");
	printf("\t2)Matricula. \n\n");
	
	printf("Digite aqui: ");
	scanf("%d",&opcao_do_menu_1);
	
	switch (opcao_do_menu_1){
		case 1:
			apagar_nome_via_cpf();
			break;
		case 2:
			printf("Infelizmente essa opção está temporariamente indisponível. \n");
			system("pause");
			apagar_nomes();
			break;
		default:
			input_invalido();
			break;
	}	
}

int apagar_nome_via_cpf(){//Função responsavel por apagar entradas utilizando o cpf.
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
		printf("O cpf encontrado corresponde a seguinte informação:\n\n");
			
		while(fgets(conteudo, 500, file) != NULL){
			printf("%s", conteudo);
			printf("\n\n");
			
			printf("você deseja apagar essa entrada do banco de dados? \n\n");
			printf("\t1)Sim.\n");
			printf("\t2)Não.\n\n");
				
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
		printf("CPF não cadastrado. \n\n");
		system("pause");
	}
}

int finlizar_programa(){//Função responsavel por fechar o programa
	printf("Você escolheu sair. \n");
	printf("Obrigado por utilizar esse software. \n\n");
	printf("software em desenvolvimento por Felipe Cerqueira. Aluno EBAC.");
}

int input_invalido(){//função responsavel para revelar que o usuario inseriu alguma informação invalida.
	printf("O charactere digitado é inválido. \n");
	system("pause");
}
