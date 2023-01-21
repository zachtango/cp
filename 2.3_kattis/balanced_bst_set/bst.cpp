#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

#define MAX_N 300010

typedef long long ll;

ll depth[MAX_N] = {0};

int main() {

    int n;
    set<ll> bst;
    bst.insert(MAX_N);

    cin >> n;

    ll cost = 0;
    for(int i = 0; i < n; i++) {
        ll v;
        cin >> v;

        bst.insert(v);
        auto it = bst.find(v);
        
        ll d = 0;
        if(i != 0) {
            if(it != bst.begin()) {
                auto prev = it;
                prev--;

                ll k = *prev;
                // cout << "k1: " << k << endl;
                // cout << "k1 val: " << depth[k] << endl;
                d = depth[k] + 1;
            }

            if(it != bst.end()) {
                auto next = it;
                next++;

                ll k = *next;
                // cout << "k2: " << k << endl;
                // cout << "k2 val: " << depth[k] << endl;
                d = max(d, depth[k] + 1);
            }
        }
        
        depth[v] = d;
        cost += d;

        cout << cost << endl;
    }

    return 0;
}