//Level 1, phase 1, 2017 question: Segredo do Cofre
//incrementation of prefix sums:
//table of frequency of each digit of each 1..i interval
#include <stdio.h>

#define MAXN 100000

static int freq[MAXN], prefixSum[10][MAXN+1];

int main() {
    int n, m, l, r, el;
    scanf ("%d %d", &n, &m);
    for (int i=1;i<=n;++i) {
        scanf ("%d", &el);
        prefixSum[el][i] = prefixSum[el][i-1]+1;
        for (int j = el-1; j >= 0; --j) {
            prefixSum[j][i] = prefixSum[j][i-1];
        }
        for (int j = el+1; j < 10; ++j) {
            prefixSum[j][i] = prefixSum[j][i-1];
        }
    }
    scanf ("%d", &l);
    while (--m){
        scanf ("%d", &r);
        for (int j=0;j<10;++j) {
            if (l <= r) {
                freq[j] += prefixSum[j][r-1] - prefixSum[j][l-1];
            } else {
                freq[j] += prefixSum[j][l] - prefixSum[j][r];
            }
        }
        l = r;
    }
    for (int i=0;i<10;++i) {
        freq[i] += prefixSum[i][l] - prefixSum[i][l-1];
    }
    for (int i=0;i<10;++i) printf ("%d ", freq[i]);
    printf ("\n");
}
