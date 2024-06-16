#include <cstdio>
#include <cstring>

// Defini��o das estruturas
struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco {
    char logradouro[100];
    int cep;
    char estado[3];  // Inclui espa�o para o terminador nulo '\0'
    char cidade[100];
    char bairro[100];
};

struct Poupanca {
    int agencia;
    int numdaconta;
    float saldo;
    char nome[100];
    char cpf[12]; // Certifique-se de que h� espa�o suficiente para o terminador nulo '\0'
    Data nascimento;
    char telefone[20];
    Endereco endereco;
};

int main() {
    // Abertura do arquivo para leitura
    FILE *arquivo = fopen("contapupanca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Poupanca conta;

    // Leitura dos dados do arquivo e impress�o
    while (fread(&conta, sizeof(Poupanca), 1, arquivo) == 1) {
        printf("Informa��es da conta:\n");
        printf("\tTipo da Conta: Poupan�a\n");
        printf("\tAg�ncia: %d\n", conta.agencia);
        printf("\tN�mero da conta: %d\n", conta.numdaconta);
        printf("\tNome: %s\n", conta.nome);
        printf("\tCPF: %s\n", conta.cpf);
        printf("\tData de Nascimento: %02d/%02d/%04d\n", conta.nascimento.dia, conta.nascimento.mes, conta.nascimento.ano);
        printf("\tTelefone: %s\n", conta.telefone);
        printf("\tEndere�o:\n");
        printf("\t\tLogradouro: %s\n", conta.endereco.logradouro);
        printf("\t\tCEP: %d\n", conta.endereco.cep);
        printf("\t\tEstado: %s\n", conta.endereco.estado);
        printf("\t\tCidade: %s\n", conta.endereco.cidade);
        printf("\t\tBairro: %s\n", conta.endereco.bairro);
        printf("\tSaldo: %.2f\n", conta.saldo);
    }

    if (ferror(arquivo)) {
        printf("Erro na leitura do arquivo.\n");
    } else if (feof(arquivo)) {
        printf("Fim do arquivo alcan�ado.\n");
    }

    fclose(arquivo);
    return 0;
}

