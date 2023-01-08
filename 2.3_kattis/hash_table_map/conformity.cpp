#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define BIT_SIZE_MAX 10
#define NUM_COURSES 5

typedef long long ll;
typedef std::vector<int> vi;

std::unordered_map<ll, int> um;

int main() {
    int n;

    std::cin >> n;

    int m = 0;

    while(n--) {
        vi courses(NUM_COURSES);
        ll key = 0;

        for(int i = 0; i < NUM_COURSES; i++)
            std::cin >> courses[i];
    
        std::sort(courses.begin(), courses.end());

        for(int i = 0; i < NUM_COURSES; i++) {
            key |= courses[i];
            key <<= BIT_SIZE_MAX;
        }

        um[key] += 1;

        m = std::max(um[key], m);
    }

    int counter = 0;
    for(auto p : um)
        if(p.second == m)
            counter += m;
    
    std::cout << counter;

    return 0;
}


