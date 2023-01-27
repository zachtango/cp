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

    int l = 0, r = 1;
    for(int i = 0; i < n; i++) {
        if(abs(a[i] - a[(i + 1) % n]) < abs(a[l] - a[r])) {
            l = i, r = (i + 1) % n;
        }
    }

    cout << (l + 1) << ' ' << (r + 1);

    return 0;
}