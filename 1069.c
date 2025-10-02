#include <stdio.h>
#include <string.h>

int main() {
    int N;
    if(scanf("%d", &N) != 1) return 0;
    while (N--) {
        char s[1005];
        scanf("%s" , s);
        int opens = 0;
        int diamantes = 0;
        for (int i = 0; s[i] != '\0' ; ++i) {
            if(s[i] == '<') {
                ++opens;
            } else if (s[i] == '>'){
                if (opens > 0) {
                    ++diamantes;
                    --opens;
                }
            }
        }
        printf("%d\n", diamantes);
    }
    return 0;
}
