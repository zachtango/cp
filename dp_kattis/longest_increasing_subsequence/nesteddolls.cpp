#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int LIS(int *A, int n, bool strict) {
    int k = 0;
    
    vi L(n, 0);

    for(int i = 0; i < n; i++) {
        int pos;

        if(strict)
            pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        else
            pos = upper_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        L[pos] = A[i];
        
        if(pos == k) {
            k = pos + 1;
        }
        // cout << pos << ' ' << L[pos].first << ' ' << L[pos].second << endl;
    }

    return k;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int m;
        
        cin >> m;

        vector<pair<int, int>> dolls;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            dolls.push_back({a, b});
        }
        sort(dolls.begin(), dolls.end(), [](auto const &a, auto const &b) {
            if(a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        });
        
        int A[m];
        for(int i = 0; i < m; i++) {
            A[i] = dolls[i].second;
        }

        int lds_sz = LIS(A, m, false);

        cout << lds_sz << endl;
    }

    return 0;
}