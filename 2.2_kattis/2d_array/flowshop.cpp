#include <iostream>
#include <math.h>

using namespace std;

#define L_MAX 1001

int T[L_MAX][L_MAX];


int main(){
    /*
        Ti,j = max(Ti,j - 1, Ti - 1,j) + Pi,j
        T-1,j = 0
        Ti,-1 = 0
    */

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;

            T[i][j] = max(T[i][j - 1], T[i - 1][j]) + x;

            if(j == m) cout << T[i][j] << ' ';
        }



    return 0;
}