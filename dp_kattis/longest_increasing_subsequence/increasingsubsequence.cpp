#include <iostream>

using namespace std;

void solve(int *A, int n) {

    int LDS[n][2];
    LDS[0][0] = 1;
    LDS[0][1] = 0;

    int m = 0;
    for(int i = 1; i < n; i++) {
        LDS[i][0] = 1;
        LDS[i][1] = i;
        for(int j = 0; j < i; j++) {
            if(A[j] > A[i] && LDS[i][0] < LDS[j][0] + 1) {
                LDS[i][0] = LDS[j][0] + 1;
                LDS[i][1] = j;
            }
        }

        if(LDS[i][0] > LDS[m][0])
            m = i;
    }
    
    cout << LDS[m][0];

    int i = m;
    while(i != LDS[i][1]) {
        cout << ' ' << A[i];
        i = LDS[i][1];
    }
    
    cout << ' ' << A[i];

    cout << endl;

}

int main() {
    /*
        LDS ending at i (count)
        LDS[i][0] = max(LDS[j][0] + 1, 1) for j < i if A[j] > A[i]

        if LDS[i][0] == LDS[j][0] + 1:
            a = LDS[i][1]
            b = j

            while A[a] == A[b] and a != LDS[a][1]:
                a = LDS[a][1]
                b = LDS[b][1]

            if A[a] > A[b]:
                LDS[i][1] = j
    */

    int n;
    
    while(cin >> n, n) {
        int A[n];
        for(int i = n - 1; i >= 0; i--) {
            cin >> A[i];
        }
        solve(A, n);
    }



    return 0;
}