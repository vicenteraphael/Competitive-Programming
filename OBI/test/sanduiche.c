//P2 2021 F2 - Sanduíche
//our level's gonna lower here
//probably accepted
#include <stdio.h>

int main() {
    int n, y; scanf ("%d %d", &n, &y);
    int forbidden[y], ans = (1<<n)-1;
    int p1, p2;
    for (int i=0; i<y; ++i) {
        scanf ("%d %d", &p1, &p2);
        forbidden[i] = (1<<(p1-1))|(1<<(p2-1));
    } 
    for (int mask=1; mask <= (1<<n)-1; ++mask)
        for (int i=0; i<y; ++i)
            if ((mask&forbidden[i]) == forbidden[i]) {
                --ans;
                break;
            }
    printf ("%d\n", ans);
    return 0;
}
