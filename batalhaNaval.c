#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro
#define NAVIO 3     // Representação dos navios
#define HAB 5       // Representação de habilidades especiais
#define HSIZE 7     // Tamanho das matrizes de habilidades (7x7)


// Função auxiliar: Inicializa o tabuleiro com água (0)

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = 0;
}

// Função: Exibe o tabuleiro formatado

void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}


// Função: Gera matriz de habilidade em forma de CONE
// (Cone apontado para baixo)

void gerarCone(int hab[HSIZE][HSIZE]) {
    int meio = HSIZE / 2;

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            // Condicional cria uma faixa que aumenta ao descer
            if (j >= meio - i && j <= meio + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}


// Função: Gera matriz de habilidade em forma de CRUZ

void gerarCruz(int hab[HSIZE][HSIZE]) {
    int meio = HSIZE / 2;

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            // Condicional cria linha central e coluna central
            if (i == meio || j == meio)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// Função: Gera matriz de habilidade em forma de OCTAEDRO
// (Losango)

void gerarOctaedro(int hab[HSIZE][HSIZE]) {
    int meio = HSIZE / 2;

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            // |i - meio| + |j - meio| <= meio cria um losango
            if ( (abs(i - meio) + abs(j - meio)) <= meio )
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}


// Função: Aplica uma habilidade ao tabuleiro
// Sobrepõe valores 1 da matriz de habilidade como valor 5 no tabuleiro
// O ponto central da habilidade fica na coordenada passada

void aplicarHabilidade(int tab[TAM][TAM], int hab[HSIZE][HSIZE], int linha, int coluna) {
    int meio = HSIZE / 2;

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {

            if (hab[i][j] == 1) {
                int ti = linha + (i - meio);
                int tj = coluna + (j - meio);

                // Verifica limites do tabuleiro
                if (ti >= 0 && ti < TAM && tj >= 0 && tj < TAM) {

                    // Marca como área de habilidade APENAS se não for navio
                    if (tab[ti][tj] != NAVIO)
                        tab[ti][tj] = HAB;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // POSICIONAR NAVIOS (mesmos do desafio anterior)
   
    tabuleiro[2][1] = NAVIO; tabuleiro[2][2] = NAVIO; tabuleiro[2][3] = NAVIO;
    tabuleiro[5][4] = NAVIO; tabuleiro[6][4] = NAVIO; tabuleiro[7][4] = NAVIO;
    tabuleiro[0][0] = NAVIO; tabuleiro[1][1] = NAVIO; tabuleiro[2][2] = NAVIO;
    tabuleiro[3][8] = NAVIO; tabuleiro[4][7] = NAVIO; tabuleiro[5][6] = NAVIO;

    
    // Criar matrizes de habilidades

    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octaedro[HSIZE][HSIZE];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);


    // Aplicar habilidades no tabuleiro
    // Coordenadas dos centros escolhidas livremente

    aplicarHabilidade(tabuleiro, cone, 1, 5);      // Cone no topo direito
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz na parte inferior esquerda
    aplicarHabilidade(tabuleiro, octaedro, 5, 7);  // Octaedro à direita

    // Exibir tabuleiro completo
   
    exibirTabuleiro(tabuleiro);

    return 0;
}
