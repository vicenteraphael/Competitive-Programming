//2024, level 2, phase 2 (B shift) question: Trio de Palitinhos
#include <iostream>
#include <algorithm>

int binarySearch (int a, int b, int v[], int n) {
    int start = b+1, end = n-1, half, ans = 0;
    while (start <= end) {
        half = (start+end)/2;
        if (v[a] + v[b] > v[half]) {
            ans = half-b;
            start = half+1;
        } 
        else end = half-1;
    }
    return ans;
}

int main() {
    int n, ans=0;
    scanf ("%d", &n);
    int v[n];
    for (int i=0; i<n; ++i) scanf ("%d", &v[i]);
    std::sort(v, v+n);
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            ans += binarySearch(i, j, v, n);
        }
    }
    printf ("%d\n", ans);
}
