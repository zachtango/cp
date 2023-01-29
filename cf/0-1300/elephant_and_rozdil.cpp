#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    int a[n];

    int t = INT32_MAX;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        t = min(t, a[i]);
    }

    int c = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == t) {
            if(c != -1) {
                cout << "Still Rozdil";
                return 0;
            }
            c = i;
        }
    }

    cout << c + 1;

    return 0;
}