//accepted 100%
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> letters, attLetters;

//checks if the supposed root is an anagram of the rest of the subdivisions
bool checkRoot (std::string word, int n, int q) {
    for (int i = q; i < n; i += q) {
        attLetters.clear();
        for (int j = 0; j < q; ++j) ++attLetters[word[i+j]]; //maps the frequency of the subdivision's letters
        if (letters != attLetters) return false;
    }
    return true;
}

std::string findRoot(std::string word, int n) {    
    char let;
    std::string root;
    for (int i = 0; i < n/2; ++i) { //the length of the root is, at most, half the polygram. Doesn't it make sense?
        let = word[i];
        ++letters[let]; //maps the frequency of the root's letters
        root += let;
        if (n%(i+1) == 0) { //check if we can split the word by the supposed root's length
            if (checkRoot(word, n, i+1)) return root; //checks if the root is valid
        }
    }
    return "*";
}

int main() {
    std::string word;
    int n;
    std::cin>>n>>word;
    std::cout<<findRoot(word, n)<<"\n";
    return 0;
}