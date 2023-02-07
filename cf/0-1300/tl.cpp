#include <iostream>
#include <math.h>

using namespace std;

int main() {
    /*
    a <= v
    2a <= v extra time
    */

    int n, m;

    cin >> n >> m;

    int min_a = INT32_MAX;
    int max_a = 0;
    int b = INT32_MAX;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        min_a = min(min_a, num);
        max_a = max(max_a, num);
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        b = min(b, num);
    }

    int v = b - 1;
    // cout << min_a << ' ' << max_a << ' ' << b << endl;
    if( !(2 * min_a <= v && max_a <= v) ) {
        cout << -1;
        return 0;
    }

    for(v = 2 * min_a; v < b; v += 1) {
        if( max_a <= v && b > v ) {
            cout << v;
            break;
        }
    }

    return 0;
}