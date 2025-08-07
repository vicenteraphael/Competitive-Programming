#include <iostream>
#include <unordered_map>

bool check (std::unordered_map<char, int> alphabet, char letter, int Mchar) {
    for (int i = 0; i < Mchar; ++i) {
        letter = getchar();
        if (!alphabet[letter] == true) return false;
    }
    return true;
}

int main() {
    int Achar, Mchar;
    scanf ("%d %d", &Achar, &Mchar);
    char letter;
    std::unordered_map<char, int> alphabet;
    fflush(stdin);
    for (int i = 0; i < Achar; ++i) {
        letter = getchar();
        alphabet[letter] = true;
    }
    fflush(stdin);
    (check(alphabet, letter, Mchar)) ? printf ("S\n") : printf ("N\n");
    return 0;
}