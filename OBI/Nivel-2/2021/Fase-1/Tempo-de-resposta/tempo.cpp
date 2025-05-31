#include <iostream>
#include <map>

void ins (std::map <int, int>& ftimes, int el) {
    auto it = ftimes.find(el);
    if (it == ftimes.end()) ftimes[el] = 0;
}

void update_time (std::map<int, int>& ftimes, bool iswaiting[], int amount) {
    for (auto it : ftimes) {
        if (iswaiting[it.first]) ftimes[it.first] += amount;
    }
}

int main() {
	int cases, frend, cnt = 0;
	char action;
	std::map<int, int> ftimes;
	bool iswaiting[101];
	for (int i = 0; i < 101; ++i) iswaiting[i] = false;
	std::cin>>cases;
	for (int i = 0; i < cases; ++i) {
	    std::cin>>action>>frend;
	    if (action == 'T') {
	        update_time(ftimes, iswaiting, frend);
	    }
	    else if (cnt % 2 != 0) {
	        update_time(ftimes, iswaiting, 1);
	        ++cnt;
	    }
	    if (action == 'R') {
	        ins(ftimes, frend);
	        iswaiting[frend] = true;
	    } else {
	        iswaiting[frend] = false;
	    }
	    ++cnt;
	}
	for (auto it : ftimes) {
	    if (iswaiting[it.first]) {
	        std::cout<<it.first<<" -1\n";   
	    } else {
	        std::cout<<it.first<<" "<<it.second<<"\n";
	    }
	}
	return 0;
}