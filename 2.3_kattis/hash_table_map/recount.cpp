#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>

typedef std::unordered_map<std::string, int> um;

um vote_count;

int main() {
    
    std::string s;

    while(std::getline(std::cin, s), s != "***")
        vote_count[s] += 1;
    
    int m = 0;
    std::string majority;

    for(auto p : vote_count)
        if(p.second > m) {
            m = p.second;
            majority = p.first;
        }

    int count = 0;

    for(auto p : vote_count)
        if(p.second == m) count += 1;

    if(count > 1) std::cout << "Runoff!";
    else std::cout << majority;
    
    return 0;
}