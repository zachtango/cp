#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<char> vc;
typedef vector<int> vi;

int LIS(string &A, int n) {

    int k = 0, lis_end = 0;

    vc L(n, 0);
    vi L_id(n, 0);

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        L[pos] = A[i];
        L_id[pos] = i;

        // p[i] = pos ? L_id[pos - 1] : -1;
        if(pos == k) {
            k += 1;
            lis_end = i;
        }
    }

    return k;
}

int main() {
    
    string s;
    cin >> s;

    cout << 26 - LIS(s, s.size());

    return 0;
}