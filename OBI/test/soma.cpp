//probably accepted using frequency of prefix sums
#include <stdio.h>
#include <unordered_map>

int main() {
    int n, k, x;
    long long sum = 0, ans=0;
    std::unordered_map<long long, long long> map;
    scanf ("%d %d", &n, &k); map[0] = 1;
    while (n--) {
        scanf ("%d", &x);
        sum += x;
        ans += map[sum-k];
        ++(map[sum]);
    }
    printf ("%lld\n", ans);
}
