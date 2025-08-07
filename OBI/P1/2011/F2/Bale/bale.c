#include <stdio.h>
#include <stdlib.h>

int cnt=0;

void merge (int *arr, int start, int half, int end) {
    int *sorted = (int*)malloc((end-start+1)*sizeof(int));
    int lPter = start, rPter = half+1, sPter = 0;
    while (lPter <= half && rPter <= end) {
        if (arr[lPter] <= arr[rPter]) {
            sorted[sPter] = arr[lPter];
            ++lPter; 
        } else {
            sorted[sPter] = arr[rPter];
            ++rPter; cnt += half-lPter+1;
        }
        ++sPter;
    }
    while (lPter <= half) {
        sorted[sPter] = arr[lPter];
        ++sPter; ++lPter;
    }
    while (rPter <= end) {
        sorted[sPter] = arr[rPter];
        ++sPter; ++rPter;
    }
    for (int i=start;i<=end;++i) arr[i] = sorted[i-start];
    free(sorted);
}

void mergeSort (int *arr, int start, int end) {
    if (start < end) {
        int half = start+(end-start)/2;
        mergeSort(arr, start, half);
        mergeSort(arr, half+1, end);
        merge(arr, start, half, end);
    }
}

int main() {
    int n;
    scanf ("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) scanf ("%d", &arr[i]);
    mergeSort (arr, 0, n-1);
    printf ("%d\n", cnt);
    return 0;
}
