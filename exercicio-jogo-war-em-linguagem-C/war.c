#include <stdio.h>
#include <string.h>

/*
 * Definição da struct Territorio

 * Armazena os dados de um território:
 * - nome: até 29 caracteres + '\0'
 * - cor: até 9 caracteres + '\0'
 * - tropas: quantidade de tropas do território
 */
typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main()
{
    // Vetor para armazenar 5 territórios
    Territorio territorios[5];

    // Entrada de dados
    for (int i = 0; i < 5; i++)
    {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);

        // Leitura do nome do território
        printf("Digite o nome do território: ");
        scanf(" %29[^\n]", territorios[i].nome);
        // "%29[^\n]" lê até 29 caracteres, incluindo espaços, até '\n'

        // Leitura da cor do exército
        printf("Digite a cor do exército: ");
        scanf(" %9[^\n]", territorios[i].cor);

        // Leitura do número de tropas
        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territórios cadastrados ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Número de tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
