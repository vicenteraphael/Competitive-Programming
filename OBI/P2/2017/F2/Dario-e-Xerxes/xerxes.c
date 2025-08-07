//Level 2, 2017, phase 2 question: Dario e Xerxes
#include <stdio.h>

int main() {
    int cases, r1=0, r2=0, p1=0, p2=0;
    scanf ("%d", &cases);
    while (cases--) {
        scanf ("%d %d", &r1, &r2);
        if (r2 == (r1+1)%5 || r2 == (r1+2)%5) ++p1;
        else ++p2;
    }
    p1 > p2 ? puts ("dario") : puts ("xerxes");
    return 0;
}
