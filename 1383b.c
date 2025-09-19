#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool contemDe1a9(int* elementos) {
    set<int> s;
    for (int i = 0; i < 9; i++) {
        if (elementos[i] < 1 || elementos[i] > 9) return false;
        s.insert(elementos[i]);
    }
    return s.size() == 9;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int instancia = 1; instancia <= N; instancia++) {
        // Alocação dinâmica da matriz 9x9
        int** mat = new int*[9];
        for (int i = 0; i < 9; i++) {
            mat[i] = new int[9];
            for (int j = 0; j < 9; j++) {
                cin >> mat[i][j];
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

        cout << "Instancia " << instancia << "\n";
        cout << (valido ? "SIM" : "NAO") << "\n";
        if (instancia < N) cout << "\n";

        // Liberar memória
        for (int i = 0; i < 9; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    return 0;
}
