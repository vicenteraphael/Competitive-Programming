//level 2, phase 2, 2023 question: Intervalo Distinto
#include <stdio.h>

#define MAX 100000

int occ[MAX];

int main() {
    int n, cnt=0, ans=0;
    scanf ("%d", &n);
    int el, start = 1;
    for (int i=1; i<=n; ++i ) {
        scanf ("%d", &el);
        ++cnt;
        if (start <= occ[el]) {
            cnt -= occ[el]-start+1;
            start = occ[el]+1;
        }
        occ[el] = i;
        if (cnt > ans) ans = cnt;
    }
    printf ("%d\n", ans);
    return 0;
}
