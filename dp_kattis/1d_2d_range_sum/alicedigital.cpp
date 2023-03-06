#include <iostream>

using namespace std;

int main() {
    int t, n, m;

    cin >> t;

    /*
        store prefix sum
        store last two index
        store last start index

        curr val = 
            prefix sum[curr i] - prefix sum[start index - 1]
    */

    while(t--) {
        cin >> n >> m;
        int A[n + 1], P[n + 1];
        A[0] = 0;
        P[0] = 0;

        for(int i = 1; i <= n; i++) {
            cin >> A[i];
            P[i] = P[i - 1] + A[i];
        }

        int start_i = 1;
        int last_m = 0;

        int max_w = 0;
        for(int i = 1; i <= n; i++) {
            if(A[i] == m) {
                if(last_m > 0) {
                    start_i = last_m + 1;
                }
                last_m = i;
            } else if(A[i] < m) {
                start_i = i + 1;
                last_m = 0;
                continue;
            }
            // cout << P[i] << endl;
            if(last_m > 0)
                max_w = max(max_w, P[i] - P[start_i - 1]);
        }

        cout << max_w << endl;
    }

    return 0;
}