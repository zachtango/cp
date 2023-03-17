#include <iostream>

using namespace std;

typedef long long ll;

int S = 30000;
int n;

int memo[101][30001][2];
int w[101];

int dp(int i, int value) {
    if (value == 0) return 1;
    if ((value < 0) || (i == n)) return 0;

    int &ans = memo[i][value][0];

    if (ans != -1) return ans;
    int skip = dp(i + 1, value),
        take = dp(i, value - w[i]);
    
    if (take > 0)
        memo[i][value][1] = 1;

    if (skip > 0 && take > 0)
        return ans = 2;
    else if (skip > 0 || take > 0)
        return ans = skip ? skip : take;
    
    return ans = 0;
}

int main() {
    /*
    this is not a knapsack variant, this is more of 
    a coin change variant because you can repeat orders
    */

    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 30000; j++) {
            memo[i][j][0] = -1;
            memo[i][j][1] = 0;
        }
        
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int m;
    cin >> m;
    
    int c;
    for(int i = 0; i < m; i++) {
        cin >> c;
        
        int ways = dp(0, c);

        if (ways == 0) {
            cout << "Impossible\n";
        } else if (ways == 1) {
            int j = 0;
            while (c > 0) {
                // cout << j << ' ' << c << endl;
                for (int k = 0; k < memo[j][c][1]; k++) {
                    cout << (j + 1) << ' ';
                    c -= w[j];
                }
                
                if(memo[j][c][1] == 0)
                    j += 1;
            }
            cout << endl;
        } else if (ways >= 2){
            cout << "Ambiguous\n";
        }
    }


    return 0;
}