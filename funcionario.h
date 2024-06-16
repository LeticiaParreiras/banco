#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "contas.h"

struct Funcionario{
	int codigo;
	char cargo[100];
	char nome[100];
	char cpf [15];
	Data nascimento;
	char telefone[15];
	Endereco endereco;
	char senha [100];
};

bool verificarSenha(char user);
void cadfuncionario();
int encontrarF(int codigo, Funcionario &encontrado);
void alterarF(int codigo);
void consultarF(int codigo);
#endif // FUNCIONARIO_H
