#include <iostream>

#define DAY_MAX 365

bool freefood[DAY_MAX + 1];

int main() {
    int n;

    std::cin >> n;

    while(n--) {
        int s, t;
        std::cin >> s >> t;

        for(int i = s; i <= t; i++) freefood[i] = true;
    }

    int counter = 0;

    for(int i = 1; i <= DAY_MAX; i++)
        if(freefood[i]) counter += 1;

    std::cout << counter;

    return 0;
}