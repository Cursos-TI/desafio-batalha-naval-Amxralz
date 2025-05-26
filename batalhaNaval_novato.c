#include <stdio.h>

int main() {
    // Declaração das variáveis
    int tabuleiro[10][10] = {0};  
    int navio_horizontal[3] = {3, 3, 3};  
    int navio_vertical[3] = {3, 3, 3}; 
    
    // Coordenadas iniciais dos navios
    int linha_h = 2;  
    int coluna_h = 3; 
    int linha_v = 5;  
    int coluna_v = 7; 
    
    // Validação das coordenadas
    if (linha_h < 0 || linha_h >= 10 || coluna_h < 0 || coluna_h + 3 > 10) {
        printf("Erro: Coordenadas do navio horizontal inválidas!\n");
        return 1;
    }
    
    if (linha_v < 0 || linha_v + 3 > 10 || coluna_v < 0 || coluna_v >= 10) {
        printf("Erro: Coordenadas do navio vertical inválidas!\n");
        return 1;
    }
    
    // Validação de sobreposição
    for (int j = coluna_h; j < coluna_h + 3; j++) {
        if (tabuleiro[linha_h][j] == 3) {
            printf("Erro: Navio horizontal sobrepõe outro navio!\n");
            return 1;
        }
    }
    
    for (int i = linha_v; i < linha_v + 3; i++) {
        if (tabuleiro[i][coluna_v] == 3) {
            printf("Erro: Navio vertical sobrepõe outro navio!\n");
            return 1;
        }
    }
    
    // Posiciona o navio horizontal usando o array unidimensional
    for (int j = 0; j < 3; j++) {
        tabuleiro[linha_h][coluna_h + j] = navio_horizontal[j];
    }
    
    // Posiciona o navio vertical usando o array unidimensional
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }
    
    // Exibe o tabuleiro com formatação
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("  ");  
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);  // Números das colunas
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);  // Número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
