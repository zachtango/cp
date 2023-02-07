#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, vi> um;

int main() {
    /*
        [1, 2, 1, 3, 2]
    
        [
            [0, 2], line 1 - 2
            [1, 4], line 2 - 3
            [3] line 3 - 4
        ]

        for number 2

        current line is 2
        start at height 0

            binary search line 1 and line 2
            for next closest height > 0

            which ever is closer, 
            switch to that line 1 --> 1
                            line 2 --> line 3
            
            set height to that value

            repeat until
            binary search gets you no height
            > curr height --> current line
            is the place the permutation ends up 
    */

    int n, m;
    cin >> n >> m;

    if(n == 1) {
        cout << 1;
        return 0;
    }

    if(m == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i << endl;
        }
        return 0;
    }

    um line;
    for(int h = 0; h < m; h++) {
        int a;
        cin >> a;

        line[a].push_back(h);
    }

    // for(auto p : line) {
    //     cout << p.first << ": ";
    //     for(auto h : p.second) {
    //         cout << h << ' ';
    //     }
    //     cout << endl;
    // }

    int perm[n + 1];
    for(int l = 1; l <= n; l++) {
        // cout << l << ' ' << n << endl;
        int h = -1;

        int current_line = l;
        
        while(true) {
            int left = current_line - 1, right = current_line;
            // cout << current_line << ' ' << left << ' ' << right << endl;
            auto left_it = upper_bound(line[left].begin(), line[left].end(), h);
            auto right_it = upper_bound(line[right].begin(), line[right].end(), h);

            if(left_it == line[left].end() && right_it == line[right].end()) {
                // cout << current_line << ' ' << l << endl;
                perm[current_line] = l;
                break;
            }

            int h_left = INT32_MAX, h_right = INT32_MAX;
            if(left_it != line[left].end()) {
                h_left = *left_it;
            }

            if(right_it != line[right].end()) {
                h_right = *right_it;
            }

            current_line = (h_left < h_right ? left : right + 1);
            h = min(h_left, h_right);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << perm[i] << endl;
    }

    return 0;
}