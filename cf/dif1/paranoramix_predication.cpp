#include <iostream>

using namespace std;

bool is_prime(int n) {

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main() {

    int n, m;
    cin >> n >> m;

    for(int i = n + 1; i < m; i++) {
        if(is_prime(i)) {
            cout << "NO";
            return 0;
        }
    }

    cout << (is_prime(m) ? "YES" : "NO");

    return 0;
}