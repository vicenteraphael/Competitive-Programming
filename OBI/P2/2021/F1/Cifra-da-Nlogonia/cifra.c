#include <stdio.h>

char vowel[] = {'a', 'e', 'i', 'o', 'u'};

int isVogal (char let) {
    for (int i=0; i<5; ++i) if (let == vowel[i]) return 1;
    return 0;
}

char nextVowel (char let) {
    int minDis = 1e9, dis;
    int currLet = let-'a';
    char next;
    for (int i=0; i<5; ++i) {
        dis = currLet-(vowel[i]-'a');
        if (dis < 0) dis *= -1;
        if (dis < minDis) {
            minDis = dis;
            next = vowel[i];
        }
    }
    return next;
}

void encrypt (char letMess) {
    putchar(letMess);
    if (isVogal(letMess)) return;
    putchar(nextVowel(letMess));
    char next = letMess;
    if (letMess != 'z') ++next;
    if (next == 'w' || next == 'y') ++next;
    putchar(isVogal(next) ? next+1 : next);
}

int main() {
    char message[31]; scanf ("%s", message);
    for (int i=0; message[i] != '\0'; ++i) encrypt(message[i]);
    puts("");
    return 0;
}
