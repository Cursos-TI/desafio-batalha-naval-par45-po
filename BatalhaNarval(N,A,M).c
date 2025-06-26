#include <stdio.h>
#include <stdlib.h> // Usei  para colocar a funçao abs() no losango

//  Constantes pra organizar  o código 
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

//  Valores para cada item no  tabuleiro
#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 1 // Usando 1 para o efeito, como sugerido no Nível Mestre

// --- Protótipos das Funções ---
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void posicionar_navios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibir_coordenadas_navios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void criar_habilidade_cone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criar_habilidade_cruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criar_habilidade_octaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna);

int main() {
    // Declara a matriz 10x10  para o tabuleiro (Nível Aventureiro)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche o tabuleiro com água (valor 0)
    inicializar_tabuleiro(tabuleiro);
    
    // Nível Novato & Aventureiro - Posicionamento dos Navios
    posicionar_navios(tabuleiro);

    // Nível Novato - Exibir Coordenadas
    printf("--- NIVEL NOVATO ---\n");
    exibir_coordenadas_navios(tabuleiro);

    // Nível Aventureiro - Exibir Tabuleiro Completo
    printf("\n--- NIVEL AVENTUREIRO ---\n");
    printf("Tabuleiro com todos os navios posicionados:\n");
    exibir_tabuleiro(tabuleiro);

    // Nível Mestre - Habilidades Especiais com Matrizes
    printf("\n--- NIVEL MESTRE ---\n");
    
    // Criei matrizes para representar habilidades especiai cone,cruz, e octaedro.
    int hab_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int hab_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int hab_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criar_habilidade_cone(hab_cone);
    criar_habilidade_cruz(hab_cruz);
    criar_habilidade_octaedro(hab_octaedro);
    printf("Matrizes de habilidade criadas!\n");

    // (A lógica de preenchimento está dentro da função 'aplicar_habilidade')
    aplicar_habilidade(tabuleiro, hab_cone, 2, 7);
    aplicar_habilidade(tabuleiro, hab_cruz, 7, 2);
    aplicar_habilidade(tabuleiro, hab_octaedro, 5, 5);
    printf("Habilidades especiais aplicadas no tabuleiro!\n");
    
    printf("\nTabuleiro Final com Areas de Efeito das Habilidades:\n");
    printf("Legenda: %d=Agua, %d=Navio, %d=Area Afetada\n", AGUA, NAVIO, EFEITO_HABILIDADE);
    exibir_tabuleiro(tabuleiro);

    return 0;
}


// --- Implementação das Funções ---

// Zera o tabuleiro, preenchendo com ÁGUA
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Mostra o tabuleiro na tela
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Coloca os 4 navios no tabuleiro
void posicionar_navios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Navio Horizontal (Novato)
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    // Navio Vertical (Novato)
    tabuleiro[3][8] = NAVIO;
    tabuleiro[4][8] = NAVIO;
    tabuleiro[5][8] = NAVIO;

    // Navio Diagonal 1 (Aventureiro)
    tabuleiro[5][1] = NAVIO;
    tabuleiro[6][2] = NAVIO;
    tabuleiro[7][3] = NAVIO;

    // Navio Diagonal 2 (Aventureiro)
    tabuleiro[8][8] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[6][6] = NAVIO;
}

// Varre o tabuleiro e mostra as coordenadas de onde tem navio
void exibir_coordenadas_navios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Coordenadas das partes dos navios:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == NAVIO) {
                printf("- Navio na posicao: [%d][%d]\n", i, j);
            }
        }
    }
}

// As três funções abaixo criam os "moldes" 5x5 para as habilidades
void criar_habilidade_cone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= centro - i && j <= centro + i) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void criar_habilidade_cruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void criar_habilidade_octaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

// "Carimba" o molde da habilidade no tabuleiro principal
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    int centro = TAMANHO_HABILIDADE / 2;
    // Loop aninhado para percorrer o molde 5x5
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se essa parte do molde for 1
            if (habilidade[i][j] ==
