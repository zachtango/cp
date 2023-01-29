#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    
    int m, n;

    cin >> m >> n;

    vector<int> a(m);
    set<int> left;
    set<int, greater<int>> right;

    int sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
        left.insert(sum);
    }

    sum = 0;
    for(int i = m - 1; i >= 0; i--) {
        sum += a[i];
        right.insert(sum);
    }

    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;
        
        if(q == 0) {
            cout << "Yes\n";
            continue;
        }

        if(q > *right.begin()) {
            cout << "No\n";
            continue;
        }

        if(left.count(q) != 0 || right.count(q) != 0) {
            cout << "Yes\n";
            continue;
        }

        for(auto it = left.begin(); it != left.end(); it++) {
            int s = q - *it;

            if(s < 0) {
                cout << "No\n";
                break;
            }

            if(right.count(s) != 0) {
                cout << "Yes\n";
                break;
            }
        }
    }
    
    return 0;
}