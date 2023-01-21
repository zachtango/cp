#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

unordered_map<int, int> um;
vector<int> v;

int main() {
    /*
    6
    5
    1
    1
    2
    2
    7
    */

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        um[x] += 1;
        v.push_back(x);
    }

    set<int> leaf_nodes;

    for(int i = 1; i <= n; i++) {
        if(um.count(i) == 0)
            leaf_nodes.insert(i);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int node = v[i];
        
        um[node] -= 1;

        if(leaf_nodes.size() == 0) {
            cout << "Error";
            return 0;
        }
        // cout << *leaf_nodes.begin() << endl;
        ans.push_back(*(leaf_nodes.begin()));
        leaf_nodes.erase(leaf_nodes.begin());

        if(um[node] == 0) {
            um.erase(node);
            leaf_nodes.insert(node);
        }
    }

    for(auto a : ans) cout << a << endl;

    return 0;
}