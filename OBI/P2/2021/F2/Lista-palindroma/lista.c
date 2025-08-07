//accepted 100%
#include <stdio.h>

int main() {
    int len, ans = 0;
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
    int Lpter = 0, Rpter = len-1;
    while (Lpter < Rpter) {
        if (arr[Lpter] < arr[Rpter]) {
            arr[Lpter+1] += arr[Lpter];
            ++ans; ++Lpter;
        } else if (arr[Lpter] > arr[Rpter]) {
            arr[Rpter-1] += arr[Rpter];
            ++ans; --Rpter;
        } else {
            ++Lpter; --Rpter;
        }
    }
    printf("%d\n", ans);
    return 0;
}