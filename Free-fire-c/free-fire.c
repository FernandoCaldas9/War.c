#include <stdio.h>  // Biblioteca padrão para entrada e saída (printf, scanf, etc.)
#include <string.h> // Biblioteca para manipulação de strings (strcmp, strcpy, etc.)
#include <stdlib.h> // Biblioteca para funções utilitárias (ex: system, malloc, etc.)

// Definimos o tamanho máximo da mochila
#define MAX_ITENS 10

// Criamos a "ficha" do item que vai dentro da mochila
// A struct permite guardar várias informações relacionadas em um só lugar
typedef struct
{
    char nome[30];  // Nome do item (ex: Pistola, Bandagem, Kit Médico)
    char tipo[20];  // Tipo do item (ex: Arma, Munição, Cura)
    int quantidade; // Quantidade que o jogador possui
} Item;

// Nosso vetor de structs é a mochila: pode guardar até MAX_ITENS
Item mochila[MAX_ITENS];
int totalItens = 0; // Controla quantos itens já foram guardados

// Função para inserir um novo item na mochila
void inserirItem()
{
    if (totalItens >= MAX_ITENS)
    {
        printf("\n⚠️ A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome); // Lê o nome (inclui espaços até Enter)

    printf("Digite o tipo do item (Arma, Munição, Cura...): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo; // Guardamos o novo item no vetor
    totalItens++;               // Atualizamos o contador de itens

    printf("\n✅ Item adicionado com sucesso!\n");
}

// Função para remover um item pelo nome
void removerItem()
{
    char nome[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", nome);

    int encontrado = 0;

    for (int i = 0; i < totalItens; i++)
    {
        if (strcmp(mochila[i].nome, nome) == 0)
        {
            encontrado = 1;
            // Desloca os itens seguintes uma posição para trás
            for (int j = i; j < totalItens - 1; j++)
            {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            printf("\n🗑️ Item '%s' removido da mochila!\n", nome);
            break;
        }
    }

    if (!encontrado)
    {
        printf("\n❌ Item não encontrado!\n");
    }
}

// Função para listar todos os itens da mochila
void listarItens()
{
    if (totalItens == 0)
    {
        printf("\n📦 A mochila está vazia!\n");
        return;
    }

    printf("\n📋 Itens na mochila:\n");
    for (int i = 0; i < totalItens; i++)
    {
        printf(" - Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItem()
{
    char nome[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalItens; i++)
    {
        if (strcmp(mochila[i].nome, nome) == 0)
        {
            printf("\n🔎 Item encontrado!\n");
            printf(" - Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\n❌ Item não encontrado na mochila.\n");
}

// Programa principal com menu para o jogador
int main()
{
    int opcao;

    do
    {
        printf("\n========== MENU DA MOCHILA ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirItem();
            listarItens();
            break;
        case 2:
            removerItem();
            listarItens();
            break;
        case 3:
            listarItens();
            break;
        case 4:
            buscarItem();
            break;
        case 0:
            printf("\n👋 Saindo do sistema de inventário...\n");
            break;
        default:
            printf("\n⚠️ Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
