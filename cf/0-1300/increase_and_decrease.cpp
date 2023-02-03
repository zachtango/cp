#include <iostream>

#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n - 1; i++) {
        if(a[i] != a[0]) {
            int d = a[i] - a[0];
            a[i] -= d;
            a[i + 1] += d;
        }
    }

    if(a[n - 1] == a[0])
        cout << n;
    else {
        if( (a[n - 1] - a[0]) % n == 0) {
            cout << n;
        } else {
            cout << n - 1;
        }
    }

    return 0;
}