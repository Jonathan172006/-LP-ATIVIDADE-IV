#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidadeEmEstoque;
} Produto;

float calcularValorTotalEmEstoque(Produto produto) {
    return produto.preco * produto.quantidadeEmEstoque;
}

void realizarCompra(Produto *produto, int quantidadeComprada) {
    if (produto->quantidadeEmEstoque >= quantidadeComprada) {
        produto->quantidadeEmEstoque -= quantidadeComprada;
        printf("Compra realizada com sucesso.\n");
    } else {
        printf("Quantidade insuficiente em estoque.\n");
    }
}

void consultarEstoque(Produto produto) {
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEmEstoque);
    printf("Valor total em estoque: %.2f\n", calcularValorTotalEmEstoque(produto));
}

int main() {
    Produto produto1 = {"Arroz", 10.0, 50};

    int opcao;
    do {
        printf("Menu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int quantidadeComprada;
                printf("Digite a quantidade de arroz comprada: ");
                scanf("%d", &quantidadeComprada);
                realizarCompra(&produto1, quantidadeComprada);
                break;
            }
            case 2: {
                consultarEstoque(produto1);
                break;
            }
            case 3: {
                printf("Saindo do programa.\n");
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
            }
        }
    } while (opcao != 3);

    return 0;
}
