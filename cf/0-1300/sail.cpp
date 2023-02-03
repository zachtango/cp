#include <iostream>

using namespace std;

int main() {
    int n, sx, sy, ex, ey;

    cin >> n >> sx >> sy >> ex >> ey;

    if(sx == ex && sy == ey) {
        cout << 0;
        return 0;
    }    

    int t = 0;
    char dir;
    while(n--) {
        cin >> dir;

        if(dir == 'N') {
            if(ey > sy) {
                sy += 1;
            }
        } else if(dir == 'S') {
            if(ey < sy) {
                sy -= 1;
            }
        } else if(dir == 'E') {
            if(ex > sx) {
                sx += 1;
            }
        } else {
            if(ex < sx) {
                sx -= 1;
            }
        }

        t += 1;

        if(sx == ex && sy == ey) {
            cout << t;
            return 0;
        }
    }

    cout << -1;

    return 0;
}