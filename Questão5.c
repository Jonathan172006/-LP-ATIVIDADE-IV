#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cargo[50];
    float salario;
} Funcionario;

float calcular_media_salarial(Funcionario *funcionarios, int quantidade, char *cargo) {
    int count = 0;
    float total_salario = 0;

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(funcionarios[i].cargo, cargo) == 0) {
            total_salario += funcionarios[i].salario;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return total_salario / count;
}

int main() {
    Funcionario funcionarios[] = {
        {"Maria Silva", "Analista", 2500},
        {"Carlos Anderson", "Programador", 3000},
        {"João Oliveira", "Analista", 2800},
        {"Ana Beatriz", "Programador", 3500},
        {"Bruno Martins", "Analista", 2700}
    };

    int quantidade = sizeof(funcionarios) / sizeof(funcionarios[0]);

    float media_salarial = calcular_media_salarial(funcionarios, quantidade, "Programador");

    if (media_salarial == 0) {
        printf("Não há programadores na empresa.\n");
    } else {
        printf("A média salarial dos programadores é: %.2f\n", media_salarial);
    }

    return 0;
}
