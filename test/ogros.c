//level 2, 2008, phase 1 question: Ogros
//propably accepted
#include <stdio.h>

#define MAX 10000

int binarySearch (int ranges[], int n, int result) {
    int start = 0, end = n-1, half;
    if (result > ranges[end]) return end+1;
    if (result < ranges[start]) return start;
    while (start <= end) {
        half = (start+end)/2;
        if (ranges[half] == result || (result > ranges[half] && result < ranges[half+1])) return half+1;
        if (result < ranges[half]) {
            start = half+1;
        }
        else end = half-1;
    }
    return -1;
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
    printf ("\n");
    return 0;
}
