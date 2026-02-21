#include <stdio.h>

int main() {
    int l, r, ans=0; scanf ("%d %d", &l, &r);
    int i = 1, factor = 1;
    while (factor <= r) {
        if (factor >= l) ++ans;
        ++i; factor = i*i*i*i*i*i;
    }
    printf ("%d\n", ans);
    return 0;
}

/*
Yes, the code is simple.

You only need to note that if
a numbers A exists such that A = x² and A = y³,
then, mandatorily, x² = y³.

One way out of this equation is to imply a number
z such that z³ = x² and z² = y³. So:

(z³)² = (z²)³ = z^6 = A.

The goal of this code is to find how many z's exist
such as z^6 = A and l <= A <= r.
*/
