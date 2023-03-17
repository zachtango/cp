#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 10

int graph[MAX_N][MAX_N];
unordered_map<int, unordered_map<int, int>> memo;

int tps(int u, int mask) {
    if(mask == 0)
        return (graph[u][0] == 1 ? 1 : 0);

    if(memo[u].count(mask) != 0)
        return memo[u][mask];

    int m = mask;
    int count = 0;
    while(m) {
        int ls_one = m & -m;
        int v = __builtin_ctz(ls_one) + 1;
        if(graph[u][v] == 1) {
            int cycles = tps(v, mask ^ ls_one);
            count += cycles;
            // cout << u << ' ' << v << ' ' << cycles << endl;
        }

        m ^= ls_one;
    }
    
    return memo[u][mask] = count;
}

int main() {
    /*
        to count how many hamiltonian cycles there are,
        we lock one vertice as the starting vertex

        recursively solve this problem
        try to go to neighboring vertices
            - if the adjacent edge is INF, skip
        base case is the mask (represents sets of visited vertices)
            is 0 --> return 1 for 1 cycle
    */

    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        // reset variables
        memo.clear();
        for(int i = 0; i < MAX_N; i++) {
            for(int j = 0; j < MAX_N; j++) {
                graph[i][j] = 1;
            }
        }

        int n, k;
        cin >> n >> k;

        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = -1;
            graph[v - 1][u - 1] = -1;
        }

        int count = tps(0, (1 << (n - 1)) - 1);

        cout << "Case #" << c << ": " << (count / 2) % 9901 << endl;
    }


    return 0;
}