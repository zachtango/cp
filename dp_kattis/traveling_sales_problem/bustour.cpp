#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

#define INF 100000000

int path[20][1 << 20];
int graph[20][20];
int n;
unordered_map<int, unordered_map<int, int>> memo;

int LSOne(int m) {
    return m & -m;
}

int tsp(int u, int mask, int end) {
    // return weight to end
    if(mask == 0)
        return graph[u][end];

    if(memo[u].count(mask) != 0)
        return memo[u][mask];
    
    int ans = INF;
    int next = u;

    int m = mask;

    while(m) {
        int ls_one = LSOne(m);

        int v = __builtin_ctz(ls_one) + 1;
        
        int cost = graph[u][v] + tsp(v, mask ^ ls_one, end);
        if(cost < ans) {
            ans = cost;
            path[u][mask] = v;
        }

        m ^= ls_one;
    }

    return memo[u][mask] = ans;
}

int get_first_hotels_bit_mask() {
    int mask = (1 << (n - 2)) - 1;

    int u = 0;
    
    int half = (n - 2) / 2; // h / 2 floored
    int i = 0;
    
    int hotel_mask = 0;
    while(i < half) {
        u = path[u][mask];
        
        hotel_mask |= 1 << (u - 1);

        mask ^= 1 << (u - 1);
        i += 1;
    }

    return hotel_mask;
}

void print_path(int start, int end, int mask = (1 << (n - 2)) - 1) {
    int u = start;
    cout << u << ' ';
    while(mask) {
        u = path[u][mask];
        mask ^= 1 << (u - 1);
        cout << u << ' ';
    }
    cout << end << endl;
}

int main() {

    int m;
    int counter = 1;
    while(cin >> n >> m) {
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                if(i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = INF;
            }
        }

        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], 
                                        graph[i][k] + graph[k][j]);
                }
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << graph[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        int mask = (1 << (n - 2)) - 1;
        int to_attr = tsp(0, mask, n - 1);
        
        unsigned int first_hotel_mask = get_first_hotels_bit_mask();    
        unsigned int second_hotel_mask = (~first_hotel_mask << (32 - (n - 2))) >> (32 - (n - 2));

        // bitset<5> a(first_hotel_mask),
        //             b(second_hotel_mask);
        // cout << a << ' ' << b << endl;

        int to_start = INF;
        m = second_hotel_mask;
        while(m) {
            memo.clear();

            int ls_one = LSOne(m);

            int end = __builtin_ctz(ls_one) + 1;

            // tsp(n - 1, first_hotel_mask, end);
            // cout << "first: ";
            // print_path(n - 1, end, first_hotel_mask);

            // tsp(end, second_hotel_mask ^ end, 0);
            // cout << "second: ";
            // print_path(end, 0, second_hotel_mask ^ end);

            int a = tsp(n - 1, first_hotel_mask, end);

            memo.clear();
            
            int b = tsp(end, second_hotel_mask ^ end, 0);
            
            to_start = min(to_start, a + b);

            m ^= ls_one;
        }

        cout << "Case " << counter << ": " << to_attr + to_start << endl;
        counter += 1;
    }

    return 0;
}