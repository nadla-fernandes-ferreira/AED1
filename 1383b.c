#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contemDe1a9(int* elementos) {
    bool seen[10] = { false };
    for (int i = 0; i < 9; i++) {
        int v = elementos[i];
        if (v < 1 || v > 9 || seen[v])
            return false;
        seen[v] = true;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int instancia = 1; instancia <= N; instancia++) {
        // Alocação dinâmica da matriz 9x9
        int** mat = malloc(9 * sizeof(int*));
        for (int i = 0; i < 9; i++) {
            mat[i] = malloc(9 * sizeof(int));
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        bool valido = true;

        // Verificar linhas
        for (int i = 0; i < 9 && valido; i++) {
            if (!contemDe1a9(mat[i]))
                valido = false;
        }

        // Verificar colunas
        for (int j = 0; j < 9 && valido; j++) {
            int col[9];
            for (int i = 0; i < 9; i++)
                col[i] = mat[i][j];
            if (!contemDe1a9(col))
                valido = false;
        }

        // Verificar blocos 3x3
        for (int bi = 0; bi < 3 && valido; bi++) {
            for (int bj = 0; bj < 3 && valido; bj++) {
                int bloco[9];
                int idx = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        bloco[idx++] = mat[bi * 3 + i][bj * 3 + j];
                    }
                }
                if (!contemDe1a9(bloco))
                    valido = false;
            }
        }

        printf("Instancia %d\n", instancia);
        printf(valido ? "SIM\n" : "NAO\n");
        if (instancia < N) printf("\n");

        // Liberar memória
        for (int i = 0; i < 9; i++) {
            free(mat[i]);
        }
        free(mat);
    }

    return 0;
}
