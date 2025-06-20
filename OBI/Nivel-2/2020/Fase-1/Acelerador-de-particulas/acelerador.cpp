#include <iostream>

int main() {
    int d;
    std::cin>>d;
    switch (d%8) {
        case 0:
            std::cout<<"3\n";
            break;
        case 7:
            std::cout<<"2\n";
            break;
        case 6:
            std::cout<<"1\n";
    }
    return 0;
}