#include <iostream>

using namespace std;

#define MAX_N 100000

/*
    count number of inversions

    number of inversions must be divisible by 2 to be able to solve
    otherwise impossible

    store sorted permutation in rank[1...100001]
    rank[num] = pos in sorted permutation

    count number of inversions using merge sort
    when comparing elem, compare their ranks -->
    a w/ lower rank than b means a goes before b
*/

int RANK[MAX_N + 1];
int A[MAX_N + 1];

int inversions = 0;

void merge_sort(int l, int r){
    if(l >= r){
        return;
    }

    int m = l + (r - l) / 2;

    // produces sorted A[l..m] and A[m + 1..r]
    merge_sort(l, m);
    merge_sort(m + 1, r);

    // merge
    int L[m - l + 1],
        R[r - (m + 1) + 1];

    int L_len = m - l + 1,
        R_len = r - (m + 1) + 1;

    for(int i = 0; i < L_len; i++) L[i] = A[l + i];
    for(int i = 0; i < R_len; i++) R[i] = A[m + 1 + i];

    int i = 0, j = 0;

    while(i < L_len && j < R_len){
        if(RANK[R[j]] < RANK[L[i]]){
            A[l + i + j] = R[j];
            inversions += (L_len - i);
            j += 1;
        } else{
            A[l + i + j] = L[i];
            i += 1;
        }
    }

    while(i < L_len){
        A[l + i + j] = L[i];
        i += 1;
    }

    while(j < R_len){
        A[l + i + j] = R[j];
        j += 1;
    }
}

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) cin >> A[i];

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        RANK[a] = i;
    }

    merge_sort(0, n - 1);
    
    if(inversions % 2 == 0) cout << "Possible";
    else cout << "Impossible";

    return 0;
}