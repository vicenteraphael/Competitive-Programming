#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

static int BIT[MAXN], arr[MAXN];
int n;

void update (int i, int dt) {
    for (; i <= n; i += (i&-i)) BIT[i] += dt;
}

int sum (int k) {
    int ans = 0;
    for (; k > 0; k -= (k&-k)) ans += BIT[k];
    return ans;
}

int main() {
    int q, op, i, k;
    scanf ("%d %d", &n, &q);
    for (int i=1;i<=n;++i) {
        scanf ("%d", &arr[i]);
        update (i, arr[i]);
    }
    while (q--) {
        scanf ("%d", &op);
        if (op == 1) {
            scanf (" %d", &k);
            printf ("%d\n", sum(k));
        } else {
            scanf (" %d %d", &i, &k);
            update(i, k-arr[i]);
            arr[i] = k;
        }
    }
    return 0;
}
