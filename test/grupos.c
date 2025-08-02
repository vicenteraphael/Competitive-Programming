#include <stdio.h>
#include <stdlib.h>

#define MAX 9999999

int together[MAX][2], ntogether[MAX][2], group[MAX];

int main() {
    int s, tg, ntg;
    int s1, s2, s3, cnt=0;
    scanf ("%d %d %d", &s, &tg, &ntg);
    for (int i=0; i<tg; ++i) {
        scanf ("%d %d", &together[i][0], &together[i][1]);
    }
    for (int i=0; i<ntg; ++i) {
        scanf ("%d %d", &ntogether[i][0], &ntogether[i][1]);
    }
    for (int i=0; i<s/3; ++i) {
        scanf ("%d %d %d", &s1, &s2, &s3);
        group[s1] = group[s2] = group[s3] = i;
    }
    for (int i=0; i<tg; ++i) {
        s1 = together[i][0];
        s2 = together[i][1];
        if (group[s1] != group[s2]) ++cnt;
    }
    for (int i=0; i<ntg; ++i) {
        s1 = together[i][0];
        s2 = together[i][1];
        if (group[s1] == group[s2]) ++cnt;
    }
    printf ("%d\n", cnt);
    return 0;   
}
