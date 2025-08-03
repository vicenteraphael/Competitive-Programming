//probably accepted
#include <stdio.h>

int c1[10], c2[10];
int index1 = -1, index2 = -1;

void compare (int n1, int n2) {
    int d1, d2;
    while (n1 > 0 && n2 > 0) {
        d1 = n1%10; n1/=10;
        d2 = n2%10; n2/=10;
        if (d1 > d2) {
            c1[++index1] = d1;
        } else if (d2 > d1) {
            c2[++index2] = d2;
        } else if (d1 == d2) {
            c1[++index1] = d1;
            c2[++index2] = d2;
        }
    }
    while (n1 > 0) {
        d1 = n1%10; n1/=10;
        c1[++index1] = d1;
    }
    while (n2 > 0) {
        d2 = n2%10; n2 /= 10;
        c2[++index2] = d2;
    }
}

int main() {
    int n1, n2, r1=0, r2=0;
    scanf ("%d %d", &n1, &n2);
    compare (n1, n2);
    if (index1 > -1) {
        while (index1 >= 0) {
            r1 = r1*10+c1[index1];
            --index1;
        }
    } else {
        r1 = -1;
    }
    if (index2 > -1) {
        while (index2 >= 0) {
            r2 = r2*10+c2[index2];
            --index2;
        }
    } else {
        r2 = -1;
    }
    (r1 <= r2) ? printf ("%d %d\n", r1, r2) : printf ("%d %d\n", r2, r1);
    return 0;
}
