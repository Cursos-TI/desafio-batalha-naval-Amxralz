#include <stdio.h>
#include <stdlib.h>

// Definição das constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

int main() {
    // Declaração de todas as variáveis
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int i, j, linha_origem, coluna_origem;
    int offset;
    
    // Inicialização do tabuleiro com água (0)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Criação da habilidade Cone (ajustada para corresponder ao exemplo)
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 0 && j == 2) {
                habilidadeCone[i][j] = 1;  // Ponto superior
            } else if (i == 1 && j >= 1 && j <= 3) {
                habilidadeCone[i][j] = 1;  // Linha do meio
            } else if (i == 2) {
                habilidadeCone[i][j] = 1;  // Linha inferior
            } else {
                habilidadeCone[i][j] = 0;
            }
        }
    }
    
    // Criação da habilidade Cruz
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE/2 || j == TAMANHO_HABILIDADE/2) {
                habilidadeCruz[i][j] = 1;
            } else {
                habilidadeCruz[i][j] = 0;
            }
        }
    }
    
    // Criação da habilidade Octaedro
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int centro = TAMANHO_HABILIDADE/2;
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidadeOctaedro[i][j] = 1;
            } else {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }
    
    // Adicionando navios para teste
    tabuleiro[3][3] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[4][3] = 3;
    tabuleiro[4][4] = 3;
    
    // Aplicando a habilidade Cone
    linha_origem = 5;
    coluna_origem = 5;
    offset = TAMANHO_HABILIDADE/2;
    
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tabuleiro = linha_origem - offset + i;
            int coluna_tabuleiro = coluna_origem - offset + j;
            
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO &&
                habilidadeCone[i][j] == 1) {
                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
            }
        }
    }
    
    // Aplicando a habilidade Cruz
    linha_origem = 7;
    coluna_origem = 7;
    
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tabuleiro = linha_origem - offset + i;
            int coluna_tabuleiro = coluna_origem - offset + j;
            
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO &&
                habilidadeCruz[i][j] == 1) {
                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
            }
        }
    }
    
    // Aplicando a habilidade Octaedro
    linha_origem = 2;
    coluna_origem = 2;
    
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tabuleiro = linha_origem - offset + i;
            int coluna_tabuleiro = coluna_origem - offset + j;
            
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO &&
                habilidadeOctaedro[i][j] == 1) {
                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
            }
        }
    }
    
    // Exibindo o tabuleiro
    printf("\nTabuleiro com habilidades aplicadas:\n");
    printf("  ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // Área afetada pela habilidade
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
    
    return 0;
} 