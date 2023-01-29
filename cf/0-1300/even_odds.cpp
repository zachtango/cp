#include <iostream>

using namespace std;

int main() {
    long long n, k;

    cin >> n >> k;

    long long m = (n % 2 == 0) ? n : n + 1;

    if(k > m / 2) {
        k = k - m / 2;
        cout << (2 * k);
    } else {
        cout << (2 * k - 1);
    }

    return 0;
}