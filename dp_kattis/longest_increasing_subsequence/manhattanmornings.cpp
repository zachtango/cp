#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int LIS(int *A, int n) {
    int k = 0;
    vi L(n, 0);

    for(int i = 0; i < n; i++) {
        int pos = upper_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        L[pos] = A[i];
        if(pos == k) {
            k += 1;
        }
    }

    return k;
}

int main() {
    
    int n;

    cin >> n;

    int x_h, y_h, x_w, y_w;
    cin >> x_h >> y_h >> x_w >> y_w;
    /*
        h w cases:
        
                w
            h
            h
                w
            w
                h
                h
            w
    */
    bool flip_x = false, flip_y = false;
    if(x_h > x_w) {
        int x_offset = 2 * (x_h - x_w);
        x_w += x_offset;
        flip_x = true;
    }
    if(y_h > y_w) {
        int y_offset = 2 * (y_h - y_w);
        y_w += y_offset;
        flip_y = true;
    }

    // cout << x_h << ' ' << y_h << ' ' << x_w << ' ' << y_w << endl;

    vector<pair<int, int>> errands;
    while(n--) {
        int x, y;
        cin >> x >> y;

        if(flip_x) {
            int x_offset = 2 * (x_h - x);
            x += x_offset;
        }

        if(flip_y) {
            int y_offset = 2 * (y_h - y);
            y += y_offset;
        }
        
        if(x >= x_h && x <= x_w && y >= y_h && y <= y_w) {
            // cout << x << ' ' << y << endl;
            errands.push_back({x, y});
        }
    }

    sort(errands.begin(), errands.end(), [](auto const &a, auto const &b) {
        if(a.first == b.first)
            return a.second < b.second;

        return a.first < b.first;
    });

    n = errands.size();
    int A[n];
    for(int i = 0; i < n; i++) {
        A[i] = errands[i].second;
        // cout << A[i] << ' ';
    }
    // cout << endl;
    
    cout << LIS(A, n);
    
    return 0;
}