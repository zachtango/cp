/*
Given n objects with weights and values
    W[n], V[n]

    minimize the weight taken to get a value v

    i objects, j value

    base cases:
        (0, j >= 1) = inf bc can't ever reach j
        (i, 0) = 0 bc reach j with empty subset

    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - V[i]] + W[i])
*/
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <vector>

using namespace std;

int V[2017], // num delegates you can win for state i
    W[2017]; // num voters needed for state i

int n;
int total_delegates = 0;
int total_votes = 0;

void print_array(int *A) {
    for(int i = 1; i <= n; i++)
        cout << A[i] << ' ';
    cout << endl;
}

int main() {

    cin >> n;

    // pre process input
    for(int i = 1; i <= n; i++) {
        int d, c, f, u;

        cin >> d >> c >> f >> u;

        if( c > (f + u) ) {
            V[i] = d;
            W[i] = 0;
        } else if( f >= (c + u) ) {
            V[i] = 0;
            W[i] = 0;
        } else {
            V[i] = d;
            
            int left;
            int diff = f - c;
            if(diff > 0) {
                left = u - diff;
                W[i] = diff + left / 2 + 1;
            } else {
                left = u + diff;
                W[i] = left / 2 + 1;
            }
            
            total_votes += W[i];
        }

        total_delegates += d;
    }

    int INF = 1000000000;
    int dp[n + 1][2017];
    int min_votes = INF;
    // knapsack
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= total_delegates; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if(i == 0) {
                dp[i][j] = INF;
                continue;
            }

            if(j == 0) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = min(
                dp[i - 1][max(j - V[i], 0)] + W[i],
                dp[i - 1][j]
            );

            if(j > (total_delegates / 2))
                min_votes = min(min_votes, dp[i][j]);
        }
    }
    
    // cout << "V\n";
    // print_array(V);
    // cout << "W\n";
    // print_array(W);

    if(min_votes == INF)
        cout << "impossible";
    else
        cout << min_votes;

    return 0;
}
