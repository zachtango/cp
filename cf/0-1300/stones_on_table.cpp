#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, min_count = 51;

    cin >> n;

    char prev;
    cin >> prev;
    int counter = 0;
    for(int i = 0; i < n - 1; i++) {
        char c;
        cin >> c;

        if(prev == c) {
            counter += 1;
        } else {
            prev = c;
        }
    }

    cout << counter;

    return 0;
}