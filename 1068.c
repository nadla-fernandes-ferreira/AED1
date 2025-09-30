#include <stdio.h>
#include <string.h>

int main() {
    char expr[1001];
    
    while (scanf("%s" , expr) != EOF) {
        int pilha = 0;
        int correto = 1;
        int len = strlen(expr);
        
        for (int i = 0; i < len; i++) {
            if(expr[i] == '(') {
                pilha++;
            } else if (expr[i] == ')') {
                if (pilha > 0) {
                    pilha--;
                } else {
                    correto = 0;
                    break;
                }
            }
        }
        if (correto && pilha == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}
