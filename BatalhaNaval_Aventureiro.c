#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
        return 1;
    }
    return 0;
}

// Função para posicionar navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Posiciona o navio
    for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        tabuleiro[linha][j] = NAVIO;
    }
}

// Função para posicionar navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Posiciona o navio
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = NAVIO;
    }
}

// Função para posicionar navio diagonalmente
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios
    // Navio horizontal
    posicionarNavioHorizontal(tabuleiro, 2, 2);
    
    // Navio vertical
    posicionarNavioVertical(tabuleiro, 5, 5);
    
    // Navios diagonais
    posicionarNavioDiagonal(tabuleiro, 0, 0);
    posicionarNavioDiagonal(tabuleiro, 7, 0);

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
