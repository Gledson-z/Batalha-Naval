#include <stdio.h>
#define C 10
#define L 10

// Função para inicializar o tabuleiro
void inicializaTabuleiro(int tabuleiro[L][C])
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tabuleiro[i][j] = 0; // Inicializa o tabuleiro com (0) para indicar a agua
        }
    }
}

// Função para posicionar navios no tabuleiro
void posicionaNavios(int tabuleiro[L][C])
{
    // Posiciona os navios horizontais
    int navios_horizontais[2][2] = {{1, 1}, {4, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (navios_horizontais[i][1] + j < C)
            {
                tabuleiro[navios_horizontais[i][0]][navios_horizontais[i][1] + j] = 7; // Navio
            }
        }
    }

    // Posiciona os navios diagonais
    int navios_diagonais[2][2] = {{6, 1}, {2, 6}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = navios_diagonais[i][0] + j;
            int y = navios_diagonais[i][1] + j;
            if (x >= 0 && x < L && y >= 0 && y < C)
            {
                tabuleiro[x][y] = 7; // Navio
            }
        }
    }
}

// Função para aplicar a habilidade de Octaedro no tabuleiro.
void HabilidadeOctaedro(int tabuleiro[L][C], int linha, int coluna)
{
    int octaedro[3][3] = {
        {0, 5, 0},
        {5, 5, 5},
        {0, 5, 0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (linha + i < L && coluna + j < C)
            {
                tabuleiro[linha + i][coluna + j] = octaedro[i][j];
            }
        }
    }
}

// Função para aplicar a habilidade de Cruz no tabuleiro.
void HabilidadeCruz(int tabuleiro[L][C], int linha, int coluna)
{
    int cruz[3][5] = {
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;

            // Verifica se a posição está dentro do tabuleiro
            if (novaLinha >= 0 && novaLinha < L && novaColuna >= 0 && novaColuna < C)
            {
                // Verifica se a posição está vazia (ou seja, não tem um navio)
                if (tabuleiro[novaLinha][novaColuna] == 0)
                {
                    tabuleiro[novaLinha][novaColuna] = cruz[i][j];
                }
            }
        }
    }
}

// Habilidade de Cone
// Modifica o tabuleiro com a habilidade de Cone.
void HabilidadeCone(int tabuleiro[L][C], int linha, int coluna)
{
    int Cone[3][3] = {
        {0, 5, 0},
        {0, 5, 0},
        {5, 5, 5}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (linha + i < L && coluna + j < C)
            {
                tabuleiro[linha + i][coluna + j] = Cone[i][j];
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimeTabuleiro(int tabuleiro[L][C])
{
    char letra[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    for (int i = 0; i < C; i++)
    {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < L; i++)
    {
        printf("%c ", letra[i]);
        for (int j = 0; j < C; j++)
        {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal do programa
// Inicializa o tabuleiro, posiciona os navios, aplica as habilidades e imprime o tabuleiro
int main()
{
    int tabuleiro[L][C];
    inicializaTabuleiro(tabuleiro);
    posicionaNavios(tabuleiro);
    HabilidadeOctaedro(tabuleiro, 2, 0);
    HabilidadeCruz(tabuleiro, 7, 4);
    HabilidadeCone(tabuleiro, 0, 7);
    imprimeTabuleiro(tabuleiro);

    return 0;
}