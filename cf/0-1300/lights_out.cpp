#include <iostream>

using namespace std;

int main() {
    int lights[3][3];
    
    int len = 3;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            lights[i][j] = 1;
        }
    }

    int dir[8][2] {
        {-1, 0}, {0, -1},
        {1, 0}, {0, 1}
    };

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int n;
            cin >> n;

            lights[i][j] += n;

            for(auto d : dir) {
                int x = i + d[0],
                    y = j + d[1];
                
                if(x < 0 || x >= 3 || y < 0 || y >= 3) {
                    continue;
                }

                lights[x][y] += n;
            }
        }
    }

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(lights[i][j] % 2 == 0) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }

    return 0;
}