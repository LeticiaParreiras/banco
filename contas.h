#ifndef CONTAS_H
#define CONTAS_H

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco {
    char logradouro[100];
    int cep;
    char estado[3];
    char cidade[100];
    char bairro[100];
    int numcasa;
};

struct Corrente {
    int agencia;
    int numdaconta;
    float limite;
    float saldo;
    Data vencimento;
    char nome[100];
    char cpf[15];
    Data nascimento;
    char telefone[15];
    Endereco endereco;
};

struct Poupanca {
    int agencia;
    int numdaconta;
    float saldo;
    char nome[100];
    char cpf[15];
    Data nascimento;
    char telefone[15];
    Endereco endereco;
};

void abrircontapoupanca();
void abrircontacorrente();
int encontrarC(int agencia, int numconta, Corrente &contaencontrada);
int encontrarP(int agencia, int numconta, Corrente &contaencontrada);
int excluirC(int agencia, int numdaconta);
int excluirP(int agencia, int numdaconta);
void consultarcontaC(int agencia, int numdaconta);
void consultarcontaP(int agencia, int numdaconta);
void consultarcliente(int agencia, int numdaconta, char tipo);
void alterarP(int agencia,int numdaconta);
void alterarC(int agencia,int numdaconta);
void alterarcliente(int agencia,int numdeconta,int tipo);
#endif // CONTAS_H

