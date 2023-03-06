#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int LIS(int *A, int n, vi &lis) {
    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0), p(n, -1);

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        L[pos] = A[i];
        L_id[pos] = i;

        p[i] = pos ? L_id[pos - 1] : -1;
        if(pos == k) {
            k += 1;
            lis_end = i;
        }
    }

    int i = lis_end;
    int j = k - 1;
    while(p[i] != -1) {
        lis[j] = i;
        n -= 1;
        j -= 1;
        i = p[i];
    }
    lis[j] = i;

    return k;
}

int main() {

    vi lis(100001);
    int A[100001];

    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> A[i];
        
        int sz = LIS(A, n, lis);
        cout << sz << endl;
        for(int i = 0; i < sz; i++)
            cout << lis[i] << ' ';
        cout << endl;
    }

    return 0;
}