//level 2, 2023, phase 2 question: Código de compressão
//probably accepted
#include <stdio.h>

int main() {
    char let, ant; int n, cnt=1;
    scanf ("%d %c", &n, &ant);
    while (--n) {
        scanf ("%c", &let);
        if (let == ant) ++cnt;
        else {
            printf ("%d %c ", cnt, ant);
            cnt = 1;
        }
        ant = let;
    }
    printf ("%d %c\n", cnt, ant);
    return 0;
}
