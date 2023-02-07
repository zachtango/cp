#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> v(12);
    for(int i = 0; i < 12; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int s = 0;
    for(int i = v.size() - 1; i >= 0; i--) {
        s += v[i];
        if(s >= n) {
            cout << (12 - i);
            return 0;
        }
    }

    cout << -1;

    return 0;
}