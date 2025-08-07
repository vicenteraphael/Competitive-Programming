//level 2, 2024, phase 2 (B shift) question: Remove Dígitos
#include <stdio.h>

int maxDigit (int x) {
    int ans = 0, d;
    while (x > 0) {
        d = x%10; x /= 10;
        if (d > ans) ans = d;
    }
    return ans;
}

int main() {
    int n, ans = 0;
    scanf ("%d", &n);
    while (n > 0) {
        n -= maxDigit(n);
        ++ans;
    }
    printf ("%d\n", ans);
    return 0;
}
