//level 2, 2008, phase 1 question: Ogros
#include <stdio.h>

#define MAX 10000

int binarySearch (int ranges[], int n, int result) {
    int start = 0, end = n-1, half;
    while (start <= end) {
        half = (start+end)/2;
        if (result < ranges[half]) {
            end = half-1;
        }
        else start = half+1;
    }
    return start;
}

int main() {
    int n, m;
    int ranges[MAX-1], awards[MAX], ogre;
    scanf ("%d %d", &n, &m);
    for (int i=0; i < n-1; ++i) scanf ("%d", &ranges[i]);
    for (int i=0; i < n; ++i) scanf ("%d", &awards[i]);
    while (m--) {
        scanf ("%d", &ogre);
        printf ("%d ", awards[binarySearch(ranges, n-1, ogre)]);
    }
    putchar ('\n');
    return 0;
}
