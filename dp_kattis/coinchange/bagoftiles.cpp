#include <iostream>
#include <unordered_map>
#include <numbers>
#include <random>
#include <vector>

using namespace std;

unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;

int coins[30];

int binomial_coefficient(int n, int k) {
    std::vector<int> row(k + 1, 1);
    for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= k; j++) {
            row[j] += row[j - 1];
        }
    }
    return row[k];
}

int num_ways(int i, int t, int num_coins, int n, int m) {
    if(t < 0 || num_coins > n)
        return 0;

    if(num_coins == n && t == 0)
        return 1;

    if(i == m)
        return 0;

    // cout << i << ' ' << t << ' ' << num_coins << ' ' << memo[i][t].count(num_coins) << endl;
    if(memo[i][t].count(num_coins) != 0)
        return memo[i][t][num_coins];

    int &ans = memo[i][t][num_coins];

    int skip = num_ways(i + 1, t, num_coins, n, m),
        take = num_ways(i + 1, t - coins[i], num_coins + 1, n, m);

    return ans = skip + take;
}

int main() {
    int g;

    cin >> g;

    for(int i = 1; i <= g; i++) {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++) {
            cin >> coins[j];
        }

        int n, t;
        cin >> n >> t;

        int total_ways = binomial_coefficient(m, n);
        int w = num_ways(0, t, 0, n, m);
        cout << "Game " << i << " -- " 
                << w << " : " << total_ways - w << endl;
        
        memo.clear();
    }

    return 0;
}
