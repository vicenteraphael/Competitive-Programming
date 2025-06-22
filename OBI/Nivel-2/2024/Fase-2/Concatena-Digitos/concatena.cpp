#include <iostream>

int main() {
    int n, q, l, r;
    scanf ("%d %d", &n, &q);
    int lista[n], somas[n+1];
    somas[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &lista[i]);
        somas[i+1] = somas[i] + lista[i];
    }
    while (q--) {
        scanf ("%d %d", &l, &r);
        printf ("%d\n", 11*(r-l)*(somas[r]-somas[l-1]));
    }
    return 0;
}