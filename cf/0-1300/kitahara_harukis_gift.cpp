#include <iostream>

using namespace std;

int main() {
    int n;

    int a = 0, b = 0;
    cin >> n;
    while(n--) {
        int w;
        cin >> w;
        if(w == 100) a += 1;
        else b += 1;
    }

    if(b % 2 == 1) a -= 2;
    // cout << a << ' ' << b << endl;
    cout << (a >= 0 && a % 2 == 0 ? "YES" : "NO");

    return 0;
}