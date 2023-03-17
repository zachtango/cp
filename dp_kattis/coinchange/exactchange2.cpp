#include <iostream>

using namespace std;

#define MAX_C 20000
#define MAX_N 100
#define INF 100000000

int dp[MAX_N + 1][MAX_C + 1];
int C[MAX_N + 1];
int c, n;
/*
    perform bottom up dp
    dp[i][0] = 0
    dp[0][j] = INF

    dp[i][j] = min(dp[i][j - C[i]] + 1, dp[i - 1][j])
*/
void min_c(int &val, int &coins) {
    int m = INF;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= MAX_C; j++) {
            if(j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if(i == 0) {
                dp[i][j] = INF;
                continue;
            }

            if(j - C[i] < 0) {
                dp[i][j] = dp[i - 1][j]; 
                continue;
            }

            dp[i][j] = min(dp[i - 1][j - C[i]] + 1, dp[i - 1][j]);

            if(j >= c && dp[i][j] != INF) {
                if(j < m) {
                    val = j;
                    coins = dp[i][j];
                    m = j;
                } else if(j == m) {
                    coins = min(coins, dp[i][j]);
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> c >> n;

        for(int i = 1; i <= n; i++) {
            cin >> C[i];
        }

        int val, coins;
        min_c(val, coins);

        cout << val << ' ' << coins << endl;
    }

    

    return 0;
}