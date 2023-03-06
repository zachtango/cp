#include <iostream>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    int C[n];
    for(int i = 0; i < n; i++) {
        cin >> C[i];
        C[i] *= 100;
    }

    int D[n - 1];
    for(int i = 0; i < n - 1; i++) {
        D[i] = C[i] - C[i + 1];
    }

    /*
        reverse this into maximum subarray sum
        M[i][0] = max(M[i - 1][0] + D[i] - k * (i - M[i - 1][0] + 1), D[i])
    */
    int m = 0;
    int M[n - 1][2];
    M[0][0] = D[0] - k * 2;
    M[0][1] = 0;
    // cout << D[0] << ' ';
    for(int i = 1; i < n - 1; i++) {
        // cout << D[i] << ' ';
        int a = M[i - 1][0] + D[i] - k,
            b = D[i] - k * 2;
        M[i][0] = max(a, b);

        if(a > b)
            M[i][1] = i - 1;
        else
            M[i][1] = i;

        m = max(m, M[i][0]);
    }
    // cout << endl;

    cout << m;

    return 0;
}