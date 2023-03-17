#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 100000000
#define MAX 2000000
int n;
vector<int> C;

int memo[101][MAX + 1];

/*
    build bottom up
    
    memo[i][t] = min number of coins to make t with [0...i] coins
    memo[i][0] = 0, 0 coins to make 0
    memo[0][j] = INF, INF coins to make j with 0 coins available

    memo[i][t] = min(memo[i][t - C[i]] + 1, memo[i - 1][t])
*/
void dp(int t) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= t; j++) {
            if(j == 0) {
                memo[i][j] = 0;
                continue;
            }

            if(i == 0) {
                memo[i][j] = INF;
                continue;
            }

            if(j - C[i - 1] < 0) {
                memo[i][j] = memo[i - 1][j];
                continue;
            }

            memo[i][j] = min(memo[i][j - C[i - 1]] + 1, memo[i - 1][j]);
            // if(memo[i][j] == 0)
            //     cout << i << ' ' << j << endl;
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= t; j++) {
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

int greedy(int t) {
    int counter = 0;
    int i = 0;
    while(i < n && t != 0) {
        if(C[i] <= t) {
            counter += t / C[i];

            t %= C[i];
        }
        i += 1;
    }

    if(t != 0)
        return INF;
    return counter;
}

int main() {
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= MAX; j++) {
            memo[i][j] = -1;
        }
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        C.push_back(c);
    }

    sort(C.begin(), C.end(), [](int a, int b){ return a > b; });

    dp(C[0] + C[1] - 1);

    for(int i = 1; i < C[0] + C[1]; i++) {
        int g = greedy(i);
        int d = memo[n][i];
        // cout << d << ' ' << g << ' ' << n << ' ' << i << endl;

        if(g == INF || d == INF)
            continue;

        if(d < g) {
            cout << "non-canonical";
            return 0;
        }
    }

    cout << "canonical";

    return 0;
}