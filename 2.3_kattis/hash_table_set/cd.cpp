#include <iostream>
#include <unordered_set>

int main() {

    std::unordered_set<int> jacks_cds;

    int n, m;

    while(
        std::cin >> n >> m,
        n && m
    ) {
        jacks_cds.clear();
        int cd;

        while(n--) {
            std::cin >> cd;
            jacks_cds.insert(cd);
        }

        int shared = 0;
        while(m--) {
            std::cin >> cd;
            if(jacks_cds.count(cd) != 0) shared += 1;
        }

        std::cout << shared << std::endl;
    }

    return 0;
}