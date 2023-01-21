#include <iostream>
#include <string>
#include <set>
#include <vector>

typedef std::set<std::string> ss;
typedef std::vector<std::string> vs;

int main() {

    ss concat_words;
    vs words;

    std::string s;

    while(std::cin >> s)
        words.push_back(s);

    int n = words.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            concat_words.insert(words[i] + words[j]);
        }
    }

    for(auto s : concat_words) {
        std::cout << s << '\n';
    }
    
    return 0;
}