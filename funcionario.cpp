#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "funcionario.h"

bool verificarSenha(char user){
	char senha[100];
	const char *senhacorreta;

    switch (user) {
        case 'a':
            senhacorreta = "a1234"; // Senha predefinida para administrador
            break;
        case 'f':
            senhacorreta = "f1234"; // Senha predefinida para funcionário
            
            break;
        case 'c':
            senhacorreta = "c1234"; // Senha predefinida para cliente
            break;
        default:
            return false;
    }
    printf("Digite a senha: ");
    fflush(stdin);
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0;
 if (strcmp(senha, senhacorreta) == 0) {
        return true;
    } else {
        return false;
    }}
void cadfuncionario()
{
	printf("\n\tCadastro de novo funcionario\n");
	Funcionario novo;
	printf("\tInforme o codigo: ");
	scanf("%d",&novo.codigo);
	printf("\tInforme o cargo: ");
	fflush(stdin);
    fgets(novo.cargo, sizeof(novo.cargo), stdin);
	printf("\tInforme o nome: ");
	fflush(stdin);
    fgets(novo.nome, sizeof(novo.nome), stdin);
	printf("\tInforme o CPF: ");
	fflush(stdin);
    fgets(novo.cpf, sizeof(novo.cpf), stdin);
	printf("\tInforme a Data de Nascimento(DD MM AAAA): ");
	scanf("%d %d %d",&novo.nascimento.dia,&novo.nascimento.mes,&novo.nascimento.ano);
	printf("\tInforme o telefone: ");
	fflush(stdin);
    fgets(novo.telefone, sizeof(novo.telefone), stdin);
	printf("\tInforme o estado: ");
	fflush(stdin);
    fgets(novo.endereco.estado, sizeof(novo.endereco.estado), stdin);
	printf("\tInforme o CEP: ");
	scanf("%d",&novo.endereco.cep);
	printf("\tInforme a Cidade: ");
	fflush(stdin);
    fgets(novo.endereco.cidade, sizeof(novo.endereco.cidade), stdin);
	printf("\tInforme o logaduro: ");
	fflush(stdin);
    fgets(novo.endereco.logradouro, sizeof(novo.endereco.logradouro), stdin);
    printf("\tInforme o bairro: ");
    fflush(stdin);
    fgets(novo.endereco.bairro, sizeof(novo.endereco.bairro), stdin);
	printf("\tInforme o numero da casa: ");
	scanf("%d",&novo.endereco.numcasa);
	printf("\tInforme a senha: ");
	fflush(stdin);
    fgets(novo.senha, sizeof(novo.senha), stdin);
	FILE* arquivofuncionario = fopen("funcionario.bin", "ab");
    if (arquivofuncionario == NULL) {
        printf("Houve algum erro na hora de salvar os dados\n");
        return;
    }
    fwrite(&novo, sizeof(Funcionario), 1, arquivofuncionario);
    fclose(arquivofuncionario);
	system("cls");	
}
int encontrarF(int codigo, Funcionario &encontrado)
{
	 FILE* arquivofuncionario = fopen("funcionario.bin", "rb");
    if (arquivofuncionario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    int posicao = 0;
    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivofuncionario)) {
        if (funcionario.codigo == codigo) {
            encontrado = funcionario;
            fclose(arquivofuncionario);
            return posicao;
        }
        posicao++;
    }
    fclose(arquivofuncionario);
    return -1;
}
void alterarF(int codigo){
 	Funcionario encontrado;
    int posicao = encontrarF(codigo, encontrado);
    if (posicao == -1) {
        printf("funcionario não encontrado.\n");
        system("pause");
        return;
    }
    printf("\tInforme o codigo: ");
	scanf("%d",&encontrado.codigo);
	printf("\tInforme o cargo: ");
	fflush(stdin);
	fgets(encontrado.cargo, sizeof(encontrado.cargo), stdin);
	printf("\tInforme o telefone: ");
	fflush(stdin);
    fgets(encontrado.telefone, sizeof(encontrado.telefone), stdin);
	printf("\tInforme o estado: ");
	fflush(stdin);
    fgets(encontrado.endereco.estado, sizeof(encontrado.endereco.estado), stdin);
	printf("\tInforme o CEP: ");
	scanf("%d",&encontrado.endereco.cep);
	printf("\tInforme o bairro: ");
    fflush(stdin);
    fgets(encontrado.endereco.bairro, sizeof(encontrado.endereco.bairro), stdin);
	printf("\tInforme a Cidade: ");
	fflush(stdin);
    fgets(encontrado.endereco.cidade, sizeof(encontrado.endereco.cidade), stdin);
	printf("\tInforme o logaduro: ");
	fflush(stdin);
    fgets(encontrado.endereco.logradouro, sizeof(encontrado.endereco.logradouro), stdin);
	printf("\tInforme o numero da casa: ");
	scanf("%d",&encontrado.endereco.numcasa);
    FILE* arquivofuncionario = fopen("funcionario.bin", "r+b");
    if (arquivofuncionario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fseek(arquivofuncionario, posicao * sizeof(Funcionario), SEEK_SET);
    fwrite(&encontrado, sizeof(Funcionario), 1, arquivofuncionario);
    fclose(arquivofuncionario);	
    printf("\n\tAlterado com sucesso\n");
    system("pause");
}
void consultarF(int codigo){
	Funcionario encontrado;
	int posicao = encontrarF(codigo, encontrado);
	if (posicao == -1){
		printf("\tFuncionario não encontrado\n");
		system("pause");
		return;
	}else{
		system("cls");
		printf("\n\tCodigo: %d\n",encontrado.codigo);
		printf("\tCargo: %s",encontrado.cargo);
		printf("\tNome: %s",encontrado.nome);
		printf("\tCPF: %s\n",encontrado.cpf);
		printf("\tData nascimento: %d/%d/%d\n",encontrado.nascimento.dia,encontrado.nascimento.mes,encontrado.nascimento.ano);
		printf("\tTelefone: %s\n",encontrado.telefone);
		printf("\tLogaduro: %s",encontrado.endereco.logradouro);
		printf("\tNumero da casa: %d\n",encontrado.endereco.numcasa);
		printf("\tCEP: %d\n",encontrado.endereco.cep);
		printf("\tBairro %s",encontrado.endereco.bairro);
		printf("\tCidade: %s",encontrado.endereco.cidade);
		printf("\tEstado: %s\n",encontrado.endereco.estado);
		system("pause");
	}
}
