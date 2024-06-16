#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "menu.h"
#include "contas.h"
#include "funcionario.h"

void menufuncionario() {
    char opcao, opcao2, tipo;
    int anumdeconta, aagencia,acodigo; // a de achar
    do {
        system("cls");
        printf("\n\t[1] - Abertura de conta");
        printf("\n\t[2] - Encerramento de Conta");
        printf("\n\t[3] - Consultar Dados");
        printf("\n\t[4] - Alterar Dados");
        printf("\n\t[5] - Cadastro de Funcionarios");
        printf("\n\t[6] - Gerar Relatorio");
        printf("\n\t[7] - Sair");
        printf("\n\tEscolha uma opcao: ");
        fflush(stdin);
        opcao = getch();
        system("cls");

        switch(opcao) {
            case '1': 
                do {
                    printf("\tSeleciona tipo da Conta\n");
                    printf("\t[1] - Conta Poupanca(CP)\n");
                    printf("\t[2] - Conta Corrente (CC)\n");
                    printf("\t[3] - Voltar\n");
                    fflush(stdin);
                    tipo = getch();
                    system("cls");
                    switch(tipo) {
                        case '1':
                            abrircontapoupanca();
                            break;
                        case '2':
                            abrircontacorrente();
                            break;
                        case '3':
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while(tipo != '3');
                break;
            case '2':
                printf("Encerramento de Conta selecionada\n");
                if (verificarSenha('a')) {
                    printf("\n\tQual tipo da conta: \n");
                    printf("\t[1] - Conta Poupanca\n");
                    printf("\t[2] - Conta Corrente\n");
                    fflush(stdin);
                    tipo = getch();
                    system("cls");
                    switch(tipo) {
                        case '1':
                            printf("\tInforme a agencia: ");
                            scanf("%d", &aagencia);
                            printf("\tInforme o numero da conta: ");
                            scanf("%d", &anumdeconta);
                            if (excluirP(aagencia, anumdeconta)==1){
                            	printf("\tConta excluida\n");
                            	system("pause");
							}else{
								printf("\tHouve erro ao excluir\n");
								system("pause");
							}
                            break;
                        case '2':
                            printf("\tInforme a agencia: ");
                            scanf("%d", &aagencia);
                            printf("\tInforme o numero da conta: ");
                            scanf("%d", &anumdeconta);
                            if (excluirC(aagencia, anumdeconta)==1){
                            	printf("\tConta excluida\n");
                            	system("pause");
							}else{
								printf("\tHouve erro ao excluir\n");
								system("pause");
							}
                            break;
                        default:
                            break;
                    }
                } 
				else {
                    printf("\n\tSenha incorreta.\n");
                    system("pause");
                }
                break;
            case '3':
                printf("Consultar Dados selecionada\n");
                printf("\t[1] - Consultar conta\n");
                printf("\t[2] - Consultar funcionario\n");
                printf("\t[3] - Consultar cliente\n");
                printf("\tEscolha uma opcao: ");
                fflush(stdin);
                opcao2 = getch();
                switch(opcao2) {
                    case '1':
                        system("cls");
                        printf("\tInforme o tipo da conta\n");
                        printf("\t[1] - Conta Poupanca\n");
                        printf("\t[2] - Conta Corrente\n");
                        fflush(stdin);
                        tipo = getch();
                        switch(tipo) {
                            case '1':
                            	system("cls");
                                printf("\n\tInforme a agencia: ");
                                scanf("%d", &aagencia);
                                printf("\tInforme o numero da conta: ");
                                scanf("%d", &anumdeconta);
                                system("cls");
                                consultarcontaP(aagencia, anumdeconta);
                                break;
                            case '2':
                            	system("cls");
                                printf("\tInforme a agencia: ");
                                scanf("%d", &aagencia);
                                printf("\tInforme o numero da conta: ");
                                scanf("%d", &anumdeconta);
                                system("cls");
                                consultarcontaC(aagencia, anumdeconta);
                                break;
                            default:
                                break;
                        }
                        break;
                    case '2':
                    	system("cls");
                    	printf("\n\tInforme o codigo do funcionario: ");
                    	scanf("%d",&acodigo);
                    	consultarF(acodigo);
                        break;
                    case '3':
                    	system("cls");
                        printf("\tInforme o tipo da conta\n");
                        printf("\t[1] - Conta Poupanca\n");
                        printf("\t[2] - Conta Corrente\n");
                        fflush(stdin);
                        tipo = getch();
                        system("cls");
                        printf("\tInforme a agencia: ");
                        scanf("%d", &aagencia);
                        printf("\tInforme o numero da conta: ");
                        scanf("%d", &anumdeconta);
                        system("cls");
                        consultarcliente(aagencia,anumdeconta,tipo);
                        break;
                    default:
                    	printf("Opção invalida");
                        break;
                }
                break;
            case '4':
            	if (verificarSenha('a')){
                printf("Alterar Dados selecionada\n");
			    printf("\t[1] - Alterar conta\n");
			    printf("\t[2] - Alterar funcionario\n");
			    printf("\t[3] - Alterar cliente\n");
			    printf("\tEscolha uma opcao: ");
			    fflush(stdin);
			    opcao2 = getch();
			    switch (opcao2) {
			        case '1':
			            printf("\tInforme o tipo da conta\n");
			            printf("\t[1] - Conta Poupanca\n");
			            printf("\t[2] - Conta Corrente\n");
			            fflush(stdin);
			            tipo = getch();
			            switch (tipo) {
			                case '1':
			                    printf("\tInforme a agencia: ");
			                    scanf("%d", &aagencia);
			                    printf("\tInforme o numero da conta: ");
			                    scanf("%d", &anumdeconta);
			                    alterarP(aagencia, anumdeconta);
			                    break;
			                case '2':
			                    printf("\tInforme a agencia: ");
			                    scanf("%d", &aagencia);
			                    printf("\tInforme o numero da conta: ");
			                    scanf("%d", &anumdeconta);
			                    alterarC(aagencia, anumdeconta);
			                    break;
			                default:
			                    printf("Tipo de conta inválido.\n");
			                    break;
			            }
			            break;
			        case '2':
			           	printf("Alterar Dados de Funcionario selecionada\n");
			           	printf("\tInforme o codigo do funcionario: ");
			           	scanf("%d",&acodigo);
			           	alterarF(acodigo);
			           	system("cls");
			           	break;
			        case '3':
			           	printf("Alterar Dados selecionada\n");
			           	system("cls");
                        printf("\tInforme o tipo da conta\n");
                        printf("\t[1] - Conta Poupanca\n");
                        printf("\t[2] - Conta Corrente\n");
                        fflush(stdin);
                        tipo = getch();
                        system("cls");
                        printf("\tInforme a agencia: ");
                        scanf("%d", &aagencia);
                        printf("\tInforme o numero da conta: ");
                        scanf("%d", &anumdeconta);
                        system("cls");
                        alterarcliente(aagencia,anumdeconta,tipo);
			           	break;
			        default:
	                    printf("Tipo de conta inválido.\n");
	                    break;
	                }} else {
                    printf("\n\tSenha incorreta.\n");
                    system("pause");
                    break;
            case '5':
                printf("Cadastro de Funcionarios selecionada\n");
                if (verificarSenha('a')){
                cadfuncionario();
				}else{
					printf("\n\tSenha incorreta\n");
					system("pause");
				}
                break;
            case '6':
                printf("Gerar Relatorio selecionada\n");
                if (verificarSenha('a')){
                system("realtorio.xlsx");
				}else{
					printf("\n\tSenha incorreta\n");
					system("pause");
				}
                break;
            case '7':
                printf("Saindo...\n");
                break;
        }
        if (opcao != '7') {
            system("pause");
        }}
    } while(opcao != '7');
}

void menucliente() {
    printf("Funcao abrir cliente nao implementada.\n");
    system("pause");
}

