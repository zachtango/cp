#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int left = 0, right = 0;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        if(l) {
            left += 1;
        }
        if(r) {
            right += 1;
        }
    }

    int t = min(left, n - left) + min(right, n - right);

    cout << t;

    return 0;
}