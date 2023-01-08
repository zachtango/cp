#include <iostream>
#include <unordered_map>
#include <math.h>

int main() {
    /*
        n
        next n lines are guests and the language they speak
            guest i as at position i in the ordered sequence
            and speaks whatever language val there is there

        keep hash table of languages spoken mapping to their
        most recent position

        keep another hash table of languages mapping to awkwardness
        level of each language
    */

    int n;
    std::cin >> n;
    std::unordered_map<int, int> position;

    int awk = n;
    for(int i = 0; i < n; i++) {
        int l;
        std::cin >> l;

        if(position.count(l) != 0) {
            awk = std::min(awk, i - position[l]);
        }

        position[l] = i;
    }

    std::cout << awk;

    return 0;
}