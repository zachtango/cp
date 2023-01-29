#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    
    int s, n;

    cin >> s >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for(auto const &p : v) {
        if(s <= p.first) {
            cout << "NO";
            return 0;
        }
        s += p.second;
    }

    cout << "YES";

    return 0;
}