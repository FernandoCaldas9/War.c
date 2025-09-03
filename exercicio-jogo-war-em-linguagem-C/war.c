#include <stdio.h>    // Para printf, scanf etc.
#include <stdlib.h>   // Para malloc, free, rand, srand
#include <string.h>   // Para strcpy
#include <time.h>     // Para srand(time(NULL))

// Estrutura que representa cada território no jogo
typedef struct {
    char nome[30];  // Nome do território
    char cor[10];   // Cor do dono do território
    int tropas;     // Quantidade de tropas no território
} Territorio;

// ----------------- FUNÇÕES DE MISSÃO -----------------

// Atribui uma missão aleatória a um jogador
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;   // Sorteia um índice válido do vetor de missões
    strcpy(destino, missoes[sorteio]);     // Copia a missão sorteada para o espaço de memória do jogador
}

// Verifica se a missão foi cumprida (aqui uma lógica simplificada)
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    // Exemplo de missão: "Conquistar 3 territórios"
    if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int conquistados = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "azul") == 0) { // Supondo jogador "azul"
                conquistados++;
            }
        }
        if (conquistados >= 3) return 1; // Cumpriu missão
    }
    return 0; // Não cumpriu
}

// Exibe a missão (passagem por valor, não altera nada)
void exibirMissao(char* missao) {
    printf("Sua missao: %s\n", missao);
}

// ----------------- FUNÇÕES DE ATAQUE -----------------

// Função para simular ataque entre territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao pode atacar territorio aliado!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1; // rola 1 a 6
    int dadoDefensor = rand() % 6 + 1;

    printf("%s (%d) atacou %s (%d)\n", atacante->nome, dadoAtacante, defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");
        strcpy(defensor->cor, atacante->cor); // defensor muda de cor
        defensor->tropas = atacante->tropas / 2; // metade das tropas do atacante ocupam
    } else {
        printf("Defensor resistiu!\n");
        atacante->tropas--; // atacante perde uma tropa
    }
}

// ----------------- GERENCIAMENTO DE MEMÓRIA -----------------

// Libera toda a memória alocada dinamicamente
void liberarMemoria(char** missoesJogadores, int numJogadores) {
    for (int i = 0; i < numJogadores; i++) {
        free(missoesJogadores[i]); // libera cada missão
    }
    free(missoesJogadores); // libera vetor de ponteiros
}

// ----------------- FUNÇÃO PRINCIPAL -----------------

int main() {
    srand(time(NULL)); // Semente aleatória para rand()

    // Vetor de missões pré-definidas
    char* missoes[] = {
        "Conquistar 3 territorios",
        "Eliminar todas as tropas vermelhas",
        "Controlar 2 territorios verdes",
        "Ter 5 territorios com mais de 3 tropas",
        "Sobreviver por 3 rodadas"
    };
    int totalMissoes = 5;

    int numJogadores = 2;

    // Aloca dinamicamente vetor de missões para cada jogador
    char** missoesJogadores = (char**)malloc(numJogadores * sizeof(char*));
    for (int i = 0; i < numJogadores; i++) {
        missoesJogadores[i] = (char*)malloc(100 * sizeof(char)); // espaço para missão
        atribuirMissao(missoesJogadores[i], missoes, totalMissoes);
    }

    // Exibe missão de cada jogador (somente uma vez no início)
    for (int i = 0; i < numJogadores; i++) {
        printf("Jogador %d:\n", i + 1);
        exibirMissao(missoesJogadores[i]);
    }

    // Simulação simples de mapa (2 territórios)
    Territorio mapa[2] = {
        {"TerritorioA", "azul", 5},
        {"TerritorioB", "vermelho", 3}
    };

    // Exemplo: jogador 1 ataca
    atacar(&mapa[0], &mapa[1]);

    // Verificação de vitória
    for (int i = 0; i < numJogadores; i++) {
        if (verificarMissao(missoesJogadores[i], mapa, 2)) {
            printf("Jogador %d venceu! Missao cumprida: %s\n", i + 1, missoesJogadores[i]);
        }
    }

    // Libera memória
    liberarMemoria(missoesJogadores, numJogadores);

    return 0;
}
