#include <iostream>

using namespace std;

#define A_MAX 10000001

bool p[A_MAX];

void sieve() {
    for(int i = 2; i * i < A_MAX; i++) {
        if(!p[i]) {
            for(int j = i + i; j < A_MAX; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    sieve();

    int counter = 0;
    for(int i = 2; i < A_MAX; i++) {
        if(!p[i]) {
            cout << i << ' ';
            counter += 1;
        }
        if(counter == n)
            break;
    }

    return 0;
}