#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    /*
        kth occurence of an integer v
    */

    unordered_map< int, vector<int> > um;

    int i = 1;
    while(n--) {
        int a;
        cin >> a;
        um[a].push_back(i);
        i += 1;
    }
    
    while(m--) {
        int k, v;

        cin >> k >> v;
        // cout << "size: " << um[v].size() << endl;
        // for(auto i : um[v]) cout << i << ' ';
        // cout << endl;
        // cout << k << endl;
        if(um[v].size() >= k) {
            cout << um[v][k - 1] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}