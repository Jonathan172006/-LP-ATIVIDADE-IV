#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {poupanca, corrente} TipoConta;

typedef struct {
    int numero;
    char nome[50];
    float saldo;
    TipoConta tipo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
    } else {
        printf("Saldo insuficiente.\n");
    }
}

void imprimir_saldo(ContaBancaria *conta) {
    printf("Saldo atual: %.2f\n", conta->saldo);
}

void menu() {
    printf("Escolha uma opção:\n");
    printf("1. Depositar\n");
    printf("2. Sacar\n");
    printf("3. Imprimir saldo\n");
    printf("4. Sair\n");
}

int main() {
    ContaBancaria conta1 = {1234, "João Silva", 5000, corrente};

    int opcao;
    float valor;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta1, valor);
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&conta1, valor);
                break;
            case 3:
                imprimir_saldo(&conta1);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
