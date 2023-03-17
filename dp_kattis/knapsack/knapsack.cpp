#include <iostream>
#include <vector>

using namespace std;

int dp[2001][2001];
bool take[2001][2001];
int V[2001], W[2001];
int n, w;

int main() {

    while(cin >> w) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i < w; i++) {
            dp[0][i] = 0;
        }

        for(int i = 0; i < n; i++) {
            cin >> V[i] >> W[i];
        }

        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= w; j++)
        //         cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= w; j++) {
                // cout << "w: " << W[i - 1] << ' ';
                if(W[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                    take[i][j] = false;
                    continue;
                }

                int take_v = dp[i - 1][j - W[i - 1]] + V[i - 1];

                if(take_v > dp[i - 1][j]) {
                    // cout << "ya ";
                    take[i][j] = true;
                    dp[i][j] = take_v;
                } else {
                    // cout << "nb ";
                    take[i][j] = false;
                    dp[i][j] = dp[i - 1][j];
                }
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        // cout << w << endl;
        vector<int> p;
        for(int i = n; i >= 1; i--) {
            // cout << dp[i][w] << endl;
            if(take[i][w]) {
                p.push_back(i - 1);
                w -= W[i - 1];
            }
        }

        cout << p.size() << endl;
        if(p.size() > 0) {
            for(int i : p)
                cout << i << ' ';
            cout << endl;
        }
    }

    return 0;
}