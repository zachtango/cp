#include <iostream>
#include <set>



int main() {
    int n;
    std::set<int> bst;

    std::cin >> n;

    int c = 0;
    while(n--) {
        int node;
        std::cin >> node;

        bst.insert(node);
        
        auto it = bst.find(node);
        
    }

    return 0;
}