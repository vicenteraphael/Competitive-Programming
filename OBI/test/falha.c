//P2 2021 F3 - Falha de segurança
//TLE and MLE ;-; (10/100)
//one day i'm gonna be able to solve it
#include <stdio.h>
#include <string.h>

#define MAX 20000

int check (char string[], char password[]) {
    int p=0, sLen = strlen(string), pLen = strlen(password);
    for (int s=0; s<sLen; ++s) {
        if (string[s] == password[p]) ++p;
        if (p == pLen) return 1;
    }
    return 0;
}
int main() {
    int n, ans=0; scanf ("%d", &n);
    char passwords[n][MAX];
    for (int i=0; i<n; ++i) scanf ("%s", passwords[i]);
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            ans += check(passwords[i], passwords[j]);
            ans += check(passwords[j], passwords[i]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}
