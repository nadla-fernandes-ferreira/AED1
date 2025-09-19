#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // lê o número de elementos
    
    int valores[N]; // vetor para armazenar os valores
    int i, menor, posicao;

    // leitura dos valores
    for (i = 0; i < N; i++) {
        scanf("%d", &valores[i]);
    }

    // inicializa menor e posição
    menor = valores[0];
    posicao = 0;

    // procura o menor valor
    for (i = 1; i < N; i++) {
        if (valores[i] < menor) {
            menor = valores[i];
            posicao = i;
        }
    }

    // saída
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
