#include <iostream>

int soma_digitos (int n) {
    int soma = 0;
    while (n != 0) {
        soma += n%10;
        n /= 10;
    }
    return soma;
}

int main() {
    int s, a, b, ans=0;
    std::cin>>s>>a>>b;
    for (int i = a; i <= b; ++i) {
        if (soma_digitos(i) == s) ++ans;
    }
    std::cout<<ans<<"\n";
    return 0;
}