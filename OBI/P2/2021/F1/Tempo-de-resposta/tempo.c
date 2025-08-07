#include <stdio.h>

#define MAX 101

int isWaiting[MAX], time[MAX];

void update (int val) {
    for (int i=0; i<=MAX; ++i) if (isWaiting[i]==1) time[i] += val;
}

int main() {
    for (int i=0; i<MAX; ++i) isWaiting[i] = -1;
	int cases, frend, cnt = 0; char action;
	scanf ("%d", &cases);
	while (cases--) {
	    scanf (" %c %d", &action, &frend);
        if (action == 'T') update(frend);
	    else if (cnt % 2 != 0) {update(1); ++cnt;}
        if (action == 'R') isWaiting[frend] = 1;
        else isWaiting[frend] = 0;
	    ++cnt;
	}
    for (int i=0; i<MAX; ++i) {
        if (isWaiting[i]==1) printf("%d -1\n", i);
        else if (isWaiting[i] == 0 && time[i] != 0) printf("%d %d\n", i, time[i]);
    }
	return 0;
}
