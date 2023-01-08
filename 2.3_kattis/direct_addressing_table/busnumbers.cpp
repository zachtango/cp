#include <iostream>

#define STOP_MAX 1000

bool stops[STOP_MAX + 1];

int main() {
    int n;
    
    std::cin >> n;

    while(n--) {
        int s;
        std::cin >> s;

        stops[s] = true;
    }

    int i = 1;

    while(i <= STOP_MAX) {
        while(i <= STOP_MAX && !stops[i]) i += 1;

        if(i == STOP_MAX + 1) break;

        int start = i;

        while(i <= STOP_MAX && stops[i]) i += 1;
        int stop = i;

        std::cout << start;

        if( (stop - start) > 2 ) 
            std::cout << '-' << (stop - 1);
        else if ( (stop - start) == 2 ) 
            std::cout << ' ' << (stop - 1);

        std::cout << ' ';
    }

    return 0;
}