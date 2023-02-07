#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int max_happiness = 0;

    int g[6][6];

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> g[i][j];
            // cout << g[i][j] << ' ';
        }
        // cout << endl;
    }

    vector<int> v{1, 2, 3, 4, 5};

    do {
        // cout << v[0] << v[1] << v[2] << v[3] << v[4] << endl;
        int happiness = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = i; j < 4; j += 2) {
                happiness += g[v[j]][v[j + 1]] 
                            + g[v[j + 1]][v[j]];
            }
        }

        max_happiness = max(max_happiness, happiness);
    } while(next_permutation(v.begin(), v.end())); 

    cout << max_happiness;

    return 0;
}