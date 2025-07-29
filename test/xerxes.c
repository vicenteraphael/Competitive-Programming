//probably accepted
#include <stdio.h>

int main() {
    int cases, r1=0, r2=0, p1=0, p2=0;
    scanf ("%d", &cases);
    for (int i=0;i<cases;++i) {
        scanf ("%d %d", &r1, &r2);
        if (r2 == (r1+1)%5 || r2 == (r1+2)%5) {++p1;}
        else {++p2;}
    }
    p1 > p2 ? printf ("dario\n") : printf ("xerxes\n");
    return 0;
}
