//I honestly dunno if this code makes any sense
#include <iostream>
#include <algorithm>

#define MAXN 100000

int main() {
    int n, palp, ans=1;
    scanf ("%d", &n);
    int arr[MAXN], cp[MAXN];
    for (int i=0;i<n;++i) {
        scanf ("%d", &arr[i]);
        cp[i] = arr[i];
    }
    std::sort(cp, cp+n);
    for (int dl=0; dl<n;++dl) {
        palp = 1;
        for (int i=0;i<n;++i) {
            if (arr[i] == cp[dl] && i != 0 && arr[i-1] >= cp[dl]) ++palp;
        }
        if (arr[n-1] != cp[dl]) ++palp;
        if (palp > ans) {
            ans = palp;
        } else {
            break;
        }
    }
    printf ("%d\n", ans);
    return 0;
}
