#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int sudoku[9][9];

        // Leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        bool ok = true;

        // Verifica linhas
        for (int i = 0; i < 9 && ok; i++) {
            bool seen[10] = { false };
            for (int j = 0; j < 9; j++) {
                int v = sudoku[i][j];
                if (v < 1 || v > 9 || seen[v]) {
                    ok = false;
                    break;
                }
                seen[v] = true;
            }
        }

        // Verifica colunas
        for (int j = 0; j < 9 && ok; j++) {
            bool seen[10] = { false };
            for (int i = 0; i < 9; i++) {
                int v = sudoku[i][j];
                if (v < 1 || v > 9 || seen[v]) {
                    ok = false;
                    break;
                }
                seen[v] = true;
            }
        }

        // Verifica blocos 3x3
        for (int bi = 0; bi < 3 && ok; bi++) {
            for (int bj = 0; bj < 3 && ok; bj++) {
                bool seen[10] = { false };
                for (int di = 0; di < 3; di++) {
                    for (int dj = 0; dj < 3; dj++) {
                        int i = bi * 3 + di;
                        int j = bj * 3 + dj;
                        int v = sudoku[i][j];
                        if (v < 1 || v > 9 || seen[v]) {
                            ok = false;
                            break;
                        }
                        seen[v] = true;
                    }
                    if (!ok) break;
                }
            }
        }

        printf("Instancia %d\n", instancia);
        if (ok) printf("SIM\n");
        else printf("NAO\n");
        if (instancia < n) printf("\n");
    }

    return 0;
}
