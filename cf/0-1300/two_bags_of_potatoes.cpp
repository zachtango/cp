#include <iostream>

using namespace std;

int main() {
    int y, k, n;

    cin >> y >> k >> n;

    int counter = 0;
    int i = k - y;

    while(i < 1) {
        i += k;
    }
    // cout << i;
    for(; (i + y) <= n; i += k) {
        cout << i << ' ';
        counter += 1;
    }

    if(counter == 0)
        cout << -1;

    return 0;
}