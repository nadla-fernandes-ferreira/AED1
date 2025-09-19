#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // Alocação dinâmica do vetor
    int *valores = (int *) malloc(N * sizeof(int));
    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int i, menor, posicao;

    // Leitura dos valores
    for (i = 0; i < N; i++) {
        scanf("%d", &valores[i]);
    }

    // Inicializa com o primeiro valor do vetor
    menor = valores[0];
    posicao = 0;

    // Procura o menor valor e sua posição
    for (i = 1; i < N; i++) {
        if (valores[i] < menor) {
            menor = valores[i];
            posicao = i;
        }
    }

    // Impressão do resultado
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    // Libera a memória alocada
    free(valores);

    return 0;
}
