#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    
    int x[n], y[n];

    int min_x = INT32_MAX, max_y = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        min_x = min(min_x, x[i]);
        max_y = max(max_y, y[i]);
    }

    for(int i = 0; i < n; i++) {
        if(x[i] == min_x && y[i] == max_y) {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}