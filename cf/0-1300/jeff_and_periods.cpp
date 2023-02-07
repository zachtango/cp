#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector<int> vi;

int main() {
    
    int n;
    cin >> n;

    map<int, vi> m;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    vector<pair<int, int>> valid;
    for(auto &p : m) {
        int x = p.first;

        if(p.second.size() == 1) {
            valid.push_back({x, 0});
            continue;
        }

        sort(p.second.begin(), p.second.end());

        int d = p.second[1] - p.second[0];

        bool ok = true;
        int prev = p.second[0] - d;
        for(auto const &a : p.second) {
            if(a - prev != d) {
                ok = false;
                break;
            }
            prev = a;
        }

        if(ok) 
            valid.push_back({x, d});
    }

    cout << valid.size() << endl;
    for(auto const &v : valid) {
        cout << v.first << ' ' << v.second << endl;
    }

    return 0;
}