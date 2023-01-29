#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool done = false;
    int last;
    while(!done) {
        done = true;
        for(int i = 0; i < n; i++) {
            if(a[i] <= 0) continue;

            a[i] -= m;
            if(a[i] <= 0) {
                last = i;
            } else {
                done = false;
            }
        }
    }

    cout << (last + 1);

    return 0;
}