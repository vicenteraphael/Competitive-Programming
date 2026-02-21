#include <iostream>
#include <string>

char closest_vogal (char ch, std::string alphabet) {
    char closest;
    int pLeft = ch-97, pRight = ch-97;
    while (pLeft >= 0 || pRight <= 23) {
        if (pLeft >= 0) {
            closest = alphabet[--pLeft];
            if (closest == 'a' || closest == 'e' || closest == 'i' || closest == 'o' || closest == 'u') return closest;
        }
        if (pRight <= 23) {
            closest = alphabet[++pRight];
            if (closest == 'a' || closest == 'e' || closest == 'i' || closest == 'o' || closest == 'u') return closest;
        }
    }
    return closest;
}

char next_consonant (char ch, std::string alphabet) {
    char closest;
    int z = ch-96;
    if (ch == 'x') {
        z = 23;
    }
    for (int i = z; i <= 23; ++i) {
        closest = alphabet[i];
        if (closest != 'a' && closest != 'e' && closest != 'i' && closest != 'o' && closest != 'u') return closest;
    }
    return ch;
}

std::string encrypt (std::string message) {
    std::string encrypted;
    std::string alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'z'};
    for (char ch : message) {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            encrypted += ch;
            encrypted += closest_vogal(ch, alphabet);
            encrypted += next_consonant(ch, alphabet);
            continue;
        }
        encrypted += ch;
    }
    return encrypted;
}

int main() {
    std::string message;
    std::cin>>message;
    std::cout<<encrypt(message);

    return 0;
}