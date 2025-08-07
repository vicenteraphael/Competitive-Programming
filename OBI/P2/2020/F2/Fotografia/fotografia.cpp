//accepted 100%
#include <iostream>

int main() {
    int a, l, num, x, y;
    std::cin>>a>>l>>num;
    int Lwaste, Cwaste, ans = -1;
    Lwaste = 10e6;
    for (int i = 0; i < num; ++i) {
        std::cin>>x>>y;
        if ((x >= a && y >= l) || (x >= l && y >= a)) {
            Cwaste = x*y-a*l;
            if (Cwaste < Lwaste) {
                Lwaste = Cwaste;
                ans = i+1;
            }
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}