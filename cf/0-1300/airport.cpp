#include <iostream>
#include <math.h>

using namespace std;

int max_x(int *a, int m) {
    int s = 0;

    for(int i = 0; i < m; i++) {
        if(a[i] > a[s]) {
            s = i;
        }
    }

    return s;
}

int min_x(int *a, int m) {
    int s = 0;
    int b = INT32_MAX;

    for(int i = 0; i < m; i++) {
        if(a[i] == 0) continue;
        if(a[i] < b) {
            s = i;
            b = a[i];
        }
    }
    
    return s;
}

int main() {
    
    int n, m;
    cin >> n >> m;

    int a[m], b[m];

    for(int i = 0; i < m; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    int minimum = 0, maximum = 0;
    for(int i = 0; i < n; i++) {
        int j = min_x(a, m);
        int k = max_x(b, m);
        // cout << j << ' ' << k << endl;
        minimum += a[j];
        maximum += b[k];

        a[j] -= 1;
        b[k] -= 1;
    }

    cout << maximum << ' ' << minimum;

    return 0;
}