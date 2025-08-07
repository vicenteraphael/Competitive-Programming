// 2024, level 2, phase 2 (B shift) question: Salada de Frutas
#include <iostream>
#include <set>

#define MAX 101

int main() {
    int r, n, type, price, ans=0;
    scanf ("%d %d", &r, &n);
    int prices[MAX]; for (int i=0; i<MAX; ++i) prices[i] = MAX;
    std::set<int> orderedPrices;
    for (int i=0; i<n; ++i) {
        scanf ("%d %d", &type, &price);
        if (price < prices[type]) prices[type] = price;
    }
    for (int i=0; i<MAX; ++i) if (prices[i] != MAX) orderedPrices.insert(prices[i]);
    for (int price : orderedPrices) {
        r -= price;
        if (r < 0) break;
        ans++;
    }
    printf ("%d\n", ans);
    return 0;
}
