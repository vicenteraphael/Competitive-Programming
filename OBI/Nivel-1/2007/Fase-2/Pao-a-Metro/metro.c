//level 1, 2007, phase 2 exercise: Pão a Metro
#include <stdio.h>

#define MAX 10000

int arr[MAX], n, k;

int isDivisible (int size) {
    int qnt = 0;
    for (int i=0;i<k;++i) {
        qnt += arr[i] / size;
    }
    return qnt >= n;
}

int binarySearch(int palp) {
    int start = 0, end = palp*2, half, ans=1; 
    while (start <= end) {
        half = (start+end)/2;
        if (isDivisible(half)) {
            ans = half; 
            start = half+1;
        }
        else end = half-1;
    }
    return ans;
}

int main() {
    int Sum = 0;
    scanf ("%d %d", &n, &k);
    for (int i=0; i<k; ++i) {
        scanf ("%d", &arr[i]);
        Sum += arr[i];
    }
    printf ("%d\n", binarySearch(Sum/k));
    return 0;
}
