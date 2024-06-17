#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include "contas.h"

void abrircontapoupanca() {
    printf("Abertura de Conta Poupanca selecionada\n");
    Poupanca contapoupanca;
    printf("Informe a agencia: ");
    scanf("%d", &contapoupanca.agencia);
    printf("Informe o numero da conta: ");
    scanf("%d", &contapoupanca.numdaconta);
    printf("Informe o nome: ");
    fflush(stdin);
    fgets(contapoupanca.nome, sizeof(contapoupanca.nome), stdin);
    printf("Informe o CPF: ");
    fgets(contapoupanca.cpf, sizeof(contapoupanca.cpf), stdin);
    printf("Informe a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &contapoupanca.nascimento.dia, &contapoupanca.nascimento.mes, &contapoupanca.nascimento.ano);
    printf("Informe o telefone: ");
    fflush(stdin);
    fgets(contapoupanca.telefone, sizeof(contapoupanca.telefone), stdin);
    printf("Informe o logradouro: ");
    fflush(stdin);
    fgets(contapoupanca.endereco.logradouro, sizeof(contapoupanca.endereco.logradouro), stdin);
    printf("Informe o CEP: ");
    scanf("%d", &contapoupanca.endereco.cep);
    printf("Informe o estado: ");
    fflush(stdin);
    fgets(contapoupanca.endereco.estado, sizeof(contapoupanca.endereco.estado), stdin);
    printf("Informe a cidade: ");
    fflush(stdin);
    fgets(contapoupanca.endereco.cidade, sizeof(contapoupanca.endereco.cidade), stdin);
    printf("Informe o bairro: ");
    fflush(stdin);
    fgets(contapoupanca.endereco.bairro, sizeof(contapoupanca.endereco.bairro), stdin);
    printf("Informe o numero da casa: ");
    scanf("%d", &contapoupanca.endereco.numcasa);

    FILE* arquivocontas = fopen("contapoupanca.bin", "ab");
    if (arquivocontas == NULL) {
        printf("Houve algum erro na hora de salvar os dados\n");
        return;
    }
    fwrite(&contapoupanca, sizeof(Poupanca), 1, arquivocontas);
    fclose(arquivocontas);
	system("cls");	
}

void abrircontacorrente() {
    Corrente contacorrente;
    printf("Abertura de Conta Corrente selecionada\n");
    printf("Informe a agencia: ");
    scanf("%d", &contacorrente.agencia);
    printf("Informe o numero da conta: ");
    scanf("%d", &contacorrente.numdaconta);
    printf("Informe o limite: ");
    scanf("%f", &contacorrente.limite);
    printf("Informe a data de vencimento (DD MM AAAA): ");
    scanf("%d %d %d", &contacorrente.vencimento.dia, &contacorrente.vencimento.mes, &contacorrente.vencimento.ano);
    printf("Informe o nome: ");
    fflush(stdin);
    fgets(contacorrente.nome, sizeof(contacorrente.nome), stdin);
    printf("Informe o CPF: ");
    fflush(stdin);
    fgets(contacorrente.cpf, sizeof(contacorrente.cpf), stdin);
    printf("Informe a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &contacorrente.nascimento.dia, &contacorrente.nascimento.mes, &contacorrente.nascimento.ano);
    printf("Informe o telefone: ");
    fflush(stdin);
    fgets(contacorrente.telefone, sizeof(contacorrente.telefone), stdin);
    printf("Informe o logradouro: ");
    fflush(stdin);
    fgets(contacorrente.endereco.logradouro, sizeof(contacorrente.endereco.logradouro), stdin);
    printf("Informe o CEP: ");
    scanf("%d", &contacorrente.endereco.cep);
    printf("Informe o estado: ");
    fflush(stdin);
    fgets(contacorrente.endereco.estado, sizeof(contacorrente.endereco.estado), stdin);
    printf("Informe a cidade: ");
    fflush(stdin);
    fgets(contacorrente.endereco.cidade, sizeof(contacorrente.endereco.cidade), stdin);
    printf("Informe o bairro: ");
    fflush(stdin);
    fgets(contacorrente.endereco.bairro, sizeof(contacorrente.endereco.bairro), stdin);    
	printf("Informe o numero da casa: ");
    scanf("%d", &contacorrente.endereco.numcasa);

    FILE* Contas = fopen("contacorrente.bin", "ab");
    if (Contas == NULL) {
        printf("Houve algum erro na hora de salvar os dados\n");
        return;
    }
    fwrite(&contacorrente, sizeof(Corrente), 1, Contas);
    fclose(Contas);
    system("cls");
}


int encontrarC(int agencia, int numconta, Corrente &contaencontrada) {
    FILE* arquivocontas = fopen("contacorrente.bin", "rb");
    if (arquivocontas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    int posicao = 0;
    Corrente conta;
    while (fread(&conta, sizeof(Corrente), 1, arquivocontas)) {
        if (conta.agencia == agencia && conta.numdaconta == numconta) {
            contaencontrada = conta;
            fclose(arquivocontas);
            return posicao;
        }
        posicao++;
    }
    fclose(arquivocontas);
    return -1;
}

int encontrarP(int agencia, int numconta, Poupanca &contaencontrada) {
    FILE* arquivocontas = fopen("contapoupanca.bin", "rb");
    if (arquivocontas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    int posicao = 0;
    Poupanca conta;
    while (fread(&conta, sizeof(Poupanca), 1, arquivocontas)) {
        if (conta.agencia == agencia && conta.numdaconta == numconta) {
            contaencontrada = conta;
            fclose(arquivocontas);
            return posicao;
        }
        posicao++;
    }
    fclose(arquivocontas);
    return -1;
}
int excluirC(int agencia, int numdaconta) {
    Corrente contaencontrada;            
    int posicao = encontrarC(agencia, numdaconta, contaencontrada);
    if (posicao == -1) {
        printf("Conta não encontrada.\n");
        system("pause");
        return 0;
    }
    FILE* arquivocontas = fopen("contacorrente.bin", "r+b");
    if (arquivocontas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        return 0;
    }
    Corrente contanull = {0};
    fseek(arquivocontas, posicao * sizeof(Corrente), SEEK_SET);
    fwrite(&contanull, sizeof(Corrente), 1, arquivocontas);
    fclose(arquivocontas);
    return 1;
}
int excluirP(int agencia, int numdaconta) {
    Poupanca contaencontrada;
    int posicao = encontrarP(agencia, numdaconta, contaencontrada);
    if (posicao == -1) {
        printf("Conta não encontrada.\n");
        system("pause");
        return 0;
    }
    FILE* arquivocontas = fopen("contapoupanca.bin", "r+b");
    if (arquivocontas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    Poupanca contanull = {0};
    fseek(arquivocontas, posicao * sizeof(Poupanca), SEEK_SET);
    fwrite(&contanull, sizeof(Poupanca), 1, arquivocontas);
    fclose(arquivocontas);
    return 1;
}

void consultarcontaC(int agencia, int numdaconta) {
    Corrente contaencontrada;
    int posicao = encontrarC(agencia, numdaconta, contaencontrada);
    if (posicao != -1) {
        printf("Informações da conta:\n");
        printf("\tTipo da Conta: Corrente \n");
        printf("\tAgência: %d\n", contaencontrada.agencia);
        printf("\tNúmero da conta: %d\n", contaencontrada.numdaconta);
        printf("\tNome: %s", contaencontrada.nome);
        printf("\tCPF: %s\n", contaencontrada.cpf);
        printf("\tLimite: %.2f\n", contaencontrada.limite);
        printf("\tData de Vencimento: %d/%d/%d\n", contaencontrada.vencimento.dia, contaencontrada.vencimento.mes, contaencontrada.vencimento.ano);
    	system("pause");
	} else {
        printf("Conta não encontrada.\n");
        system("pause");
    }
}
void consultarcontaP(int agencia, int numdaconta) {
    Poupanca contaencontrada;
    int posicao = encontrarP(agencia, numdaconta, contaencontrada);
    if (posicao != -1) {
        printf("Informações da conta:\n");
        printf("\tTipo da Conta: Poupanca\n");
        printf("\tAgência: %d\n", contaencontrada.agencia);
        printf("\tNúmero da conta: %d\n", contaencontrada.numdaconta);
        printf("\tNome: %s", contaencontrada.nome);
        printf("\tCPF: %s\n", contaencontrada.cpf);
        system("pause");
    } else {
        printf("Conta não encontrada.\n");
        system("pause");
    }
}
void consultarcliente(int agencia, int numdaconta, char tipo){
  int posicao;
    if (tipo == '1') {
        Poupanca contaencontrada;
        posicao = encontrarP(agencia, numdaconta, contaencontrada);
        if (posicao != -1) {
            printf("\tCliente\n");
            printf("\tNome: %s", contaencontrada.nome);
            printf("\tCPF: %s\n", contaencontrada.cpf);
            printf("\tData de nascimento: %d/%d/%d\n", contaencontrada.nascimento.dia, contaencontrada.nascimento.mes, contaencontrada.nascimento.ano);
            printf("\tTelefone: %s\n", contaencontrada.telefone);
            printf("\t**Endereço**\n");
            printf("\tLogradouro: %s", contaencontrada.endereco.logradouro);
            printf("\tNúmero da casa: %d", contaencontrada.endereco.numcasa);
            printf("\tCEP: %d\n", contaencontrada.endereco.cep);
            printf("\tBairro: %s", contaencontrada.endereco.bairro);
            printf("\tCidade: %s", contaencontrada.endereco.cidade);
            printf("\tEstado: %s\n", contaencontrada.endereco.estado);
            system("pause");
        } else {
            printf("Conta não encontrada.\n");
            system("pause");
        }
    } else if (tipo == '2') {
        Corrente contaencontrada;
        posicao = encontrarC(agencia, numdaconta, contaencontrada);
        if (posicao != -1) {
            printf("\tCliente\n");
            printf("\tNome: %s", contaencontrada.nome);
            printf("\tCPF: %s\n", contaencontrada.cpf);
            printf("\tData de nascimento: %d/%d/%d\n", contaencontrada.nascimento.dia, contaencontrada.nascimento.mes, contaencontrada.nascimento.ano);
            printf("\tTelefone: %s\n", contaencontrada.telefone);
            printf("\t**Endereço**\n");
            printf("\tLogradouro: %s", contaencontrada.endereco.logradouro);
            printf("\tNúmero da casa: %d\n", contaencontrada.endereco.numcasa);
            printf("\tCEP: %d\n", contaencontrada.endereco.cep);
            printf("\tBairro: %s", contaencontrada.endereco.bairro);
            printf("\tCidade: %s", contaencontrada.endereco.cidade);
            printf("\tEstado: %s\n", contaencontrada.endereco.estado);
            system("pause");
        } else {
            printf("Conta não encontrada.\n");
            system("pause");
        }
}}
void alterarP(int agencia,int numdaconta){
    Poupanca contaencontrada;
    int posicao = encontrarP(agencia, numdaconta, contaencontrada);
    if (posicao != -1) {
        Corrente contaalterada;
        printf("\n\tInforme o limite: ");
        scanf("%f", &contaalterada.limite);
        printf("\tInforme a data de vencimento (DD MM AAAA): ");
        scanf("%d %d %d", &contaalterada.vencimento.dia, &contaalterada.vencimento.mes, &contaalterada.vencimento.ano);
        contaalterada.agencia = contaencontrada.agencia;
	    contaalterada.numdaconta = contaencontrada.numdaconta;
	    strcpy(contaalterada.nome, contaencontrada.nome);
	    strcpy(contaalterada.cpf, contaencontrada.cpf);
	    strcpy(contaalterada.telefone, contaencontrada.telefone);
	    contaalterada.nascimento = contaencontrada.nascimento;
	    contaalterada.endereco = contaencontrada.endereco;
        FILE* Contas = fopen("contacorrente.bin", "ab");
	    if (Contas == NULL) {
	        printf("Houve algum erro na hora de salvar os dados\n");
	        return;}
	    fwrite(&contaalterada, sizeof(Corrente), 1, Contas);
	    fclose(Contas);
	    excluirP(agencia, numdaconta);
	}else{
		printf("Conta não encontrada");
		system("pause");
		}     
    }
void alterarC(int agencia, int numdaconta){
	Corrente contaencontrada;char mudar;
	printf("\n\tAlterar o tipo da conta: \n");
	printf("\t[1] - Altrerar para conta Poupanca\n");
	printf("\t[2] - Manter como conta Corrente");
	fflush(stdin);
	mudar = getch();
	switch(mudar){
		case '1':{
			Poupanca contaalterada;
			int posicao = encontrarC(agencia,numdaconta,contaencontrada);
			if (posicao != -1){
				contaalterada.agencia = contaencontrada.agencia;
			    contaalterada.numdaconta = contaencontrada.numdaconta;
			    strcpy(contaalterada.nome, contaencontrada.nome);
			    strcpy(contaalterada.cpf, contaencontrada.cpf);
			    strcpy(contaalterada.telefone, contaencontrada.telefone);
			    contaalterada.nascimento = contaencontrada.nascimento;
			    contaalterada.endereco = contaencontrada.endereco;
			    FILE* Contas = fopen("contapoupanca.bin", "ab");
			    if (Contas == NULL) {
			        printf("Houve algum erro na hora de salvar os dados\n");
			        return;
			    }
			    fwrite(&contaalterada, sizeof(Poupanca), 1, Contas);
			    fclose(Contas);
			    excluirC(agencia,numdaconta);}
			else{
				printf("Conta não encontrada");
				system("pause");
				}
			break;
		}
		case '2':{
			int posicao = encontrarC(agencia,numdaconta,contaencontrada);
			if (posicao != -1){
				printf("\n\tInforme a nova data de vencimento(DD MM AAAA): ");
				scanf("%d %d %d",&contaencontrada.vencimento.dia,&contaencontrada.vencimento.mes,&contaencontrada.vencimento.ano);
				printf("\tInforme o novo limite: ");
				scanf("%f",&contaencontrada.limite);
				excluirC(agencia,numdaconta);
				FILE* Contas = fopen("contacorrente.bin", "ab");
			    if (Contas == NULL) {
			        printf("Houve algum erro na hora de salvar os dados\n");
			        return;}
			    fwrite(&contaencontrada, sizeof(Corrente), 1, Contas);
			    fclose(Contas);
			    printf("Conta Alterada");
			    system("pause");
			}else{
				printf("Conta não encontrada");
				system("pause");
		}
			break;
		}		
	}	
}
void alterarcliente(int agencia,int numdaconta,int tipo){
	int posicao;
	if(tipo != '1'&& tipo!='2')
	{
		printf("Opção invalida");
		return;
	}
	if(tipo == '1'){
		Poupanca contaencontrada;
        posicao = encontrarP(agencia, numdaconta, contaencontrada);	
        if(posicao!= -1){
        printf("\n\tInforme o novo telefone: ");
        fflush(stdin);
    	fgets(contaencontrada.telefone, sizeof(contaencontrada.telefone), stdin);
        printf("\tInforme o novo logaduro: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.logradouro, sizeof(contaencontrada.endereco.logradouro), stdin);
        printf("\tInforma o novo numero da casa: ");
    	scanf("%d",&contaencontrada.endereco.numcasa);
        printf("\tInforme o novo CEP: ");
        scanf("%d",&contaencontrada.endereco.cep);
        printf("\tInforme o novo Bairro: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.bairro, sizeof(contaencontrada.endereco.bairro), stdin);
        printf("\tInforme a nova cidade: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.cidade, sizeof(contaencontrada.endereco.cidade), stdin);
        printf("\tInforme o novo estado: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.estado, sizeof(contaencontrada.endereco.estado), stdin);
    	if (excluirP(agencia, numdaconta)==1){
    	FILE* Contas = fopen("contapoupanca.bin", "ab");
			    if (Contas == NULL) {
			        printf("Houve algum erro\n");
			        return;
			    }
			    fwrite(&contaencontrada, sizeof(Poupanca), 1, Contas);
			    fclose(Contas);
				}else{
					printf("\n\thouve algum erro\n");
					system("pause");
				}
    	}else{
    		printf("\tConta não encontrada\n");
    		system("pause");
		}
	}
	if(tipo == '2'){
		Corrente contaencontrada;
        posicao = encontrarC(agencia, numdaconta, contaencontrada);
        if(posicao!= -1){
        printf("\n\tInforme o novo telefone: ");
        fflush(stdin);
    	fgets(contaencontrada.telefone, sizeof(contaencontrada.telefone), stdin);
        printf("\tInforme o novo logaduro: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.logradouro, sizeof(contaencontrada.endereco.logradouro), stdin);
        printf("\tInforma o novo numero da casa: ");
    	scanf("%d",&contaencontrada.endereco.numcasa);
        printf("\tInforme o novo CEP: ");
        scanf("%d",&contaencontrada.endereco.cep);
        printf("\tInforme o novo Bairro: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.bairro, sizeof(contaencontrada.endereco.bairro), stdin);
        printf("\tInforme a nova cidade: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.cidade, sizeof(contaencontrada.endereco.cidade), stdin);
        printf("\tInforme o novo estado: ");
        fflush(stdin);
    	fgets(contaencontrada.endereco.estado, sizeof(contaencontrada.endereco.estado), stdin);
    	if (excluirC(agencia, numdaconta)==1){
    	FILE* Contas = fopen("contacorrente.bin", "ab");
			    if (Contas == NULL) {
			        printf("Houve algum erro na hora de salvar os dados\n");
			        return;
			    }
			    fwrite(&contaencontrada, sizeof(Corrente), 1, Contas);
			    fclose(Contas);
				}else{
					printf("\n\thouve algum erro\n");
					system("pause");
				}
    	}else{
    		printf("\tConta não encontrada\n");
    		system("pause");}
	}
	}
