#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int LIS(vi &A) {
    int n = A.size(), k = 0;

    vi L(n);

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if(pos == k)
            k += 1;
    }

    return k;
}

int main() {
    
    int n;
    cin >> n;

    if(n == 0 || n == 1) {
        cout << n;
        return 0;
    }

    int A[n];

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    /*
        for each i
            find elements [i + 1...n] n
                greater than
                less than
            for elements greater than get LIS nlogk
            for elements less than get LDS nlogk
    */

    int m = 1;
    for(int i = 0; i < n - 1; i++) {
        vi lo, hi;
        for(int j = i + 1; j < n; j++) {
            if(A[j] < A[i]) {
                lo.push_back(A[j]);
            } else {
                hi.push_back(A[j]);
            }
        }

        reverse(lo.begin(), lo.end());

        m = max(m, LIS(lo) + LIS(hi) + 1);
    }
    
    cout << m << endl;

    return 0;
}