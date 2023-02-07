#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int d = v[n - 1] - v[0];
    int l = 0, r = n - 1;

    if(d == 0) {
        cout << d << ' ' << ((long long) n * (n - 1) / 2);
        return 0;
    }
    int i = l, j = r;

    while(v[i] == v[l]) i += 1;
    while(j >= 0 && v[j] == v[r]) j -= 1;

    long long counter = ((long long)(i - l) * (r - j));
    cout << d << ' ' << counter;
    
    return 0;
}