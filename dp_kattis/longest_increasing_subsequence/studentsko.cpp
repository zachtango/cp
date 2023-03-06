#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

unordered_map<int, int> grp;

int LIS(vi &A, int n) {
    int k = 0;

    vi L(n, 0);

    for(int i = 0; i < n; i++) {
        int a = grp[A[i]];

        int pos = upper_bound(L.begin(), L.begin() + k, a) - L.begin();
        L[pos] = a;
        if(pos == k) {
            k += 1;
        }
    }

    return k;
}

int main() {

    int n, k;
    cin >> n >> k;

    vi v(n), sorted_v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sorted_v[i] = v[i];
    }
    sort(sorted_v.begin(), sorted_v.end());

    for(int i = 0; i < n; i++) {
        int g = i / k;
        grp[sorted_v[i]] = g;
    }

    // get LIS
    cout << n - LIS(v, n);

    return 0;
}