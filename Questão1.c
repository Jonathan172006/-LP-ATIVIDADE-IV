#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

char* buscarTelefone(Contato contatos[], int qtdContatos, char* nome) {
    for (int i = 0; i < qtdContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].telefone;
        }
    }
    return NULL;
}

int main() {
    Contato contatos[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do contato %d: ", i+1);
        fgets(contatos[i].nome, sizeof(contatos[i].nome), stdin);
        strtok(contatos[i].nome, "\n");

        printf("Digite o telefone do contato %d: ", i+1);
        fgets(contatos[i].telefone, sizeof(contatos[i].telefone), stdin);
        strtok(contatos[i].telefone, "\n");

        printf("Digite o email do contato %d: ", i+1);
        fgets(contatos[i].email, sizeof(contatos[i].email), stdin);
        strtok(contatos[i].email, "\n");
    }

    char* nomeContato;
    printf("Digite o nome do contato que deseja buscar o telefone: ");
    scanf("%s", nomeContato);

    char* telefone = buscarTelefone(contatos, 3, nomeContato);

    if (telefone != NULL) {
        printf("O telefone do contato %s é: %s\n", nomeContato, telefone);
    } else {
        printf("Nenhum contato encontrado com esse nome.\n");
    }

    return 0;
}
