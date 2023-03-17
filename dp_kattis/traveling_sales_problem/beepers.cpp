#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

int graph[11][11];
unordered_map<int, unordered_map<int, int>> memo;

int LSOne(int m) {
    return m & (-m);
}

int tsp(int u, int mask) {
    // go back to start
    if(mask == 0)
        return graph[u][0];
    
    if(memo[u].count(mask) != 0) {
        return memo[u][mask];
    }

    int ans = INT32_MAX;
    int m = mask;
    // cout << "u: " << u << endl;
    while(m) {
        int ls_one = LSOne(m);
        
        int v = __builtin_ctz(ls_one) + 1;
        ans = min(ans, graph[u][v] + tsp(v, mask ^ ls_one));
        // cout << u << ' ' << v << ' ' << ans << endl;

        m ^= ls_one;
    }

    return memo[u][mask] = ans;
}

int main() {

    int t;
    cin >> t;
    
    while(t--) {
        int beepers[11][2];

        int n, r, c;
        cin >> r >> r >> 
            beepers[0][0] >> beepers[0][1] >> n; // don't need size of world

        for(int i = 1; i <= n; i++) {
            cin >> beepers[i][0] >> beepers[i][1];
        }
        // construct graph
        for(int i = 0; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int d = abs(beepers[i][0] - beepers[j][0]) +
                        abs(beepers[i][1] - beepers[j][1]);
                graph[i][j] = d;
                graph[j][i] = d;
            }
        }

        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= n; j++) {
        //         cout << graph[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        cout << tsp(0, (1 << n) - 1) << endl;

        memo.clear();
    }

    return 0;
}