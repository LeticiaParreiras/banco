#include <cstdio>
#include<stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include "menu.h"
#include "funcionario.h"

int main() {
    char opcao;
    do {
    	setlocale(LC_ALL, "");
        system("cls");
        printf("\n\tMENU PRINCIPAL");
        printf("\n\t[1] - Funcionario");
        printf("\n\t[2] - Cliente");
        printf("\n\t[3] - Sair");
        printf("\n\tEscolha uma opcao: ");
        opcao = getch();
        system("cls");

        switch(opcao) {
            case '1':
              if (verificarSenha('f')) {
              
                    menufuncionario();
               } else {
                    printf("\n\tSenha incorreta.\n");
                    system("pause");
                }
                break;
            case '2':
                //if (verificarSenha('c')) {
                    menucliente();
               /* } else {
                    printf("\n\tSenha incorreta.\n");
                    system("pause");
                }*/
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                system("pause");
        }
    } while (opcao != '3');

    return 0;
}

