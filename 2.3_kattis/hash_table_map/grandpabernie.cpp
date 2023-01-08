#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<int> vi;


int main() {
    /*
        n number of trips
        next n lines containing
            s name of country and y year
        q number of queries
        next q lines containing
            s name of country and k representing query
            for the kth time grandpa went to country s

    */

    int n, q;

    std::cin >> n;

    std::string s;
    int y;
    std::unordered_map<std::string, vi> countries;

    for(int i = 0; i < n; i++) {
        std::cin >> s >> y;
        countries[s].push_back(y);
    }

    for(auto it = countries.begin(); it != countries.end(); it++)
        std::sort(it->second.begin(), it->second.end());

    std::cin >> q;
    
    int k;
    for(int i = 0; i < q; i++) {
        std::cin >> s >> k;

        std::cout << countries[s][k - 1] << '\n';
    }

    return 0;
}
