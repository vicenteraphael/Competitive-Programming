//2024, level 2, phase 2 question (B turn) question: Game Show
#include <stdio.h>

int main() {
    int n, ans=1;
    scanf ("%d", &n);
    char inp;
    while (n--) {
        scanf (" %c", &inp);
        if (inp == 'E') ans *= 2;
        else ans = ans*2+1;
    }
    printf ("%d\n", ans);
    return 0;
}
