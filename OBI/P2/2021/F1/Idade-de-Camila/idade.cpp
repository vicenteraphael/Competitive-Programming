#include <iostream>

int main() {
    int i1, i2, i3;
    std::cin>>i1>>i2>>i3;
    if ((i1 >= i2 || i1 >= i3) && (i1 <= i3 || i1 <= i2)) {
        std::cout<<i1;
    } else if ((i2 >= i1 || i2 >= i3) && (i2 <= i1 || i2 <= i3)) {
        std::cout<<i2;
    } else {
        std::cout<<i3;
    }
}