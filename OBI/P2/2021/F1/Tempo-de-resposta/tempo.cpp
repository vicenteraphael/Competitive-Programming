#include <iostream>
#include <map>

std::map<int, int> Time;
bool isWaiting[101];

void ins (int frend) {
    auto it = Time.find(frend);
    if (it == Time.end()) Time[frend] = 0;
}

void update_time (int amount) {
    for (auto it : Time) if (isWaiting[it.first]) Time[it.first] += amount;
}

int main() {
	int cases, frend, cnt = 0;
	char action;
	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i) {
	    scanf(" %c %d", &action, &frend);
	    if (action == 'T') update_time(frend);
	    else if (cnt % 2 != 0) {update_time(1); ++cnt;}
	    if (action == 'R') {
	        ins(frend);
	        isWaiting[frend] = true;
	    }
        else isWaiting[frend] = false;
	    ++cnt;
	}
	for (auto it : Time) {
	    (isWaiting[it.first]) ? printf("%d -1\n", it.first) : printf("%d %d\n", it.first, it.second);
	}
	return 0;
}
