#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;

int n, m;
int dots = 0, captured_dots = 0;
char grid[100][100];

pii get_start(const pii &entrance, int n, int m) {
    if(entrance.first == 0) {
        return {1, entrance.second};
    }

    if(entrance.first == n - 1) {
        return {n - 2, entrance.second};
    }

    if(entrance.second == 0) {
        return {entrance.first, 1};
    }

    if(entrance.second == m - 1) {
        return {entrance.first, m - 2};
    }

    return {-1, -1};
}

bool dfs(int x, int y) {
    // cout << x << ' ' << y << endl;
    bool captured = false;
    if(grid[x][y] == '.') {
        captured_dots += 1;
        captured = true;
    }
    
    grid[x][y] = '#';
    
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    for(auto d : directions) {
        int new_x = x + *d;
        int new_y = y + *(d + 1);
        // cout << n << ' ' << m << ' ' << new_x << ' ' << new_y << ' ' << grid[new_x][new_y] << endl;
        if(
            (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) &&
            (grid[new_x][new_y] == ' ' || grid[new_x][new_y] == '.')
        ) {
            // cout << "DFS: " << new_x << ' ' << new_y << endl;
            captured = dfs(new_x, new_y) || captured;
        }
    }
    return captured;
}

int main() {
    /*
        DFS from all the entrances
        
        if starting from an entrance you run into visited
        square, stop DFS and don't count this entrance
        towards minimum players

        count how many dots captured
        count how many dots total
    */

    cin >> n >> m;
    // cout << n << ' ' << m << endl;
    vpii entrances;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c = getchar();
            
            if(c == '\n')
                c = getchar();
            
            grid[i][j] = c;
            if(grid[i][j] == '.') {
                dots += 1;
            } else if(grid[i][j] != 'X' && grid[i][j] != ' ') {
                entrances.push_back({i, j});
            }
        }
    }
    // cout << "Dots: " << dots << endl;
    int min_players = 0;
    for(const auto &entrance : entrances) {
        pii start = get_start(entrance, n, m);
        // cout << start.first << ' ' << start.second<< endl;

        char c = grid[start.first][start.second];
        if(c == '.' || c == ' ') {
            if(dfs(start.first, start.second)) {
                min_players += 1;
            }
            // cout << "end\n";
        }
    }
    // cout << "Captured: " << captured_dots << endl;
    cout << min_players << ' ' << (dots - captured_dots) << endl;

    return 0;
}