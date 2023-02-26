#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int a[200001];
set<int> indices;

int sum_digits(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int t, n, q;
    cin >> t;
    while(t--) {
        indices.clear();
        cin >> n >> q;
        // cout << "n: " << n << " q: " << q << endl;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] >= 10)
                indices.insert(i);
        }

        while(q--) {
            int o;
            cin >> o;
            if(o == 1) {
                int l, r;
                cin >> l >> r;
                
                auto it = indices.lower_bound(l);

                while(it != indices.end() && *it <= r) {
                    int i = *it;
                    a[i] = sum_digits(a[i]);
                    if(a[i] < 10)
                        indices.erase(it++);
                    else
                        it++;
                }

            } else if(o == 2) {
                int x;
                cin >> x;
                cout << a[x] << endl;
            } else {
                throw "Error";
            }
        }
    }


    return 0;
}