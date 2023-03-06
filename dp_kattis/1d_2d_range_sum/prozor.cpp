#include <iostream>

using namespace std;

int dp[100][100];

int main() {
    /*
        for a square with length of k
            find the k by k square in the window
            with the most *
        
        can calculate vertically, the segments
            of length k
        
        now you have an R / k by S grid
            for each row, (represents k vertical rows)
            calculate k segments that has max sum,
            this is your answer
    */

    char grid[100][100];

    int r, s, k;
    cin >> r >> s >> k;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < s; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i < r - 1; i++) {
        for(int j = 1; j < s - 1; j++) {
            if(grid[i][j] == '*')
                dp[i][j] = 1;
        }
    }

    for(int i = 1; i < r - 1; i++) {
        for(int j = 1; j < s - 1; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    
    int m = -1;
    int x, y;
    for(int i = 0; i < r - k + 1; i++) {
        for(int j = 0; j < s - k + 1; j++) {
            int su = dp[i + k - 2][j + k - 2] - 
                    dp[i + k - 2][j] - dp[i][j + k - 2] +
                    dp[i][j];
            
            if(su > m) {
                m = su;
                x = i;
                y = j;
                // cout << x << ' ' << y << endl;
            }
        }
    }

    cout << m << endl;
    
    int z = x + k - 1, w = y + k - 1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < s; j++) {
            if(m == 0) {
                cout << grid[i][j];
                continue;
            }

            if(i == x && j == y ||
                i == x && j == w ||
                i == z && j == y ||
                i == z && j == w
            ) {
                cout << '+';
            } else if(j > y && j < w && (i == x || i == z)) {
                cout << '-';
            } else if(i > x && i < z && (j == y || j == w)) {
                cout << '|';
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}