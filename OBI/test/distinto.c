//2025 P2 F2 question: Intervalo muito distinto
//O(p * log n) solution

#include <stdio.h>

long long gauss (int a1, int an, int n) {
    return (a1+an)*n/2;
}

long long binSearch (long long l, long long a, long long b) {
    long long start = a, mid, n, ans, sum;
    while (start <= b) {
        mid = start + (b-start+1)/2;
        n = mid-a+1;
        sum = gauss(a, mid, n);
        if (sum >= l) {
            ans = n;
            b = mid-1;
        } else start = mid+1;
    }
    return ans;
}

int main() {
    int p;
    long long l, a, b;
    scanf ("%d", &p);
    while (p--) {
        scanf ("%lld %lld %lld", &l, &a, &b);
        gauss(a, b, b-a+1) < l ? printf("%lld\n", b-a+1) : printf("%lld\n", binSearch(l, a, b));
    }
}
