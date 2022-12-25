#include <iostream>

using namespace std;

#define MAX_NUM 100

int A[MAX_NUM + 1],
    B[MAX_NUM + 1];

/*
    sort frequencies of nums A and B

    get max pair of A and B O(100)

    start from left of A and right of B
    1. traverse from left of A til you reach num with freq > 0
    2. traverse from left of B til you reach num with freq > 0
    3. add those nums and compare to running max
    4. if freq_A > freq_B, move B to left 1 and track f = freq_A - freq_B
    5. if freq_A < freq_B, move A to right 1 and track f = freq_B - freq_A
    6. if freq_A == freq_B, move A to right 1 and B to left 1, f = 0
    7. go to 1
*/

int solve(){
    int i = 1, j = 100;

    int freq_A = A[i],
        freq_B = A[j];

    int M = 0;

    while(i <= MAX_NUM && j >= 1){
        if(freq_A == 0) {
            i += 1;
            freq_A = A[i];
            continue;
        }
        if(freq_B == 0) {
            j -= 1;
            freq_B = B[j];
            continue;
        }

        if(freq_A == 0 && freq_B == 0) break;

        int c = min(freq_A, freq_B);
        freq_A -= c;
        freq_B -= c;

        M = max(M, i + j);
    }

    return M;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        A[a] += 1,
        B[b] += 1;

        cout << solve() << endl;
    }

    return 0;
}