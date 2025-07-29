//still working on it!
#include <iostream>
#include <algorithm>

int soma[100001];

void reverse (int arr[], int *newArr, int n) {
    int index = -1;
    soma[0] = 0;
    for (int i = n-1; i >= 0; --i) {
        newArr[++index] = arr[i];
        soma[index+1] = soma[index] + newArr[index];
    }
}

bool SqrCheck(int arr[], int n) {
    int Lpter = n/2-1, Rpter = n-1;
    int Lcnt = 0;
    while (Rpter - Lpter >= 3) {
        if (n == 4) break;
        if (arr[Lpter] < arr[Rpter]) {
            arr[Lpter+1] += arr[Lpter];
            ++Lcnt;
            ++Lpter;
        } else if (arr[Lpter] > arr[Rpter]) {
            arr[Rpter-1] += arr[Rpter];
            --Rpter;
        } else {
            break;
        }
    }
    // checar se somas[Lpter]-Lleft = somas[Rpter]-somas[Rpter-1]
    // printf ("somas: ");
    // for (int i = 0; i <= n; ++i) printf ("%d ", soma[i]);
    // printf ("\n%d %d\n", Lpter, Rpter);
    // printf ("%d %d %d\n", soma[Lpter-Lcnt], soma[Rpter], soma[Lpter]+1);
    if (arr[Lpter] == arr[Rpter] && soma[Lpter-Lcnt] == soma[Rpter]-soma[Lpter+1]) return true;
    return false;
}

int main() {
    int n;
    scanf ("%d", &n);
    int arr[n];
    soma[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &arr[i]);
        soma[i+1] = soma[i] + arr[i];
    } 
    if (SqrCheck(arr, n)) {
        printf ("S\n");
    } else {
        int newArr[n];
        reverse(arr, newArr, n);
        SqrCheck(newArr, n) ? printf ("S\n") : printf ("N\n");
    }
    
    return 0;
}

/*
checar se n//2 = n e a soma das duas metades é igual:
    - checar se arr[Lpter] = arr[Rpter]
    - checar se somas[Lpter]-Lleft = somas[Rpter]-somas[Rpter+1]

n = 6
10 10 2 7 7 3

n = 6
somas = [0, 3, 10, 17, 20, 30, 40]

3 7 7- 3 10 10-
3 7 _7 10- 10 10-

n = 6
somas = [0, 1, 2, 7, 11, 18, 26]
1 1 5- 4 7 8-
1 1 5_ 9- 7 8-
1 1 5_ 9- 15- 8
1 1 5_ 9- 24 8-
*/
