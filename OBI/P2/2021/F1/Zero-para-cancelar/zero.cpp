#include <iostream>

int main() {
    int num, len, head = 0, sum = 0;
    std::cin>>len;
    int arr[len];
    for (int i = 0; i < len; ++i) {
        std::cin>>num;
        if (num == 0) {
            sum -= arr[--head];
            continue;
        }
        arr[head++] = num;
        sum += num;
    }
    std::cout<<sum;
}