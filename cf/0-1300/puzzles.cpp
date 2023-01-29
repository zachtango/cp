#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    
    int n, m;

    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int min_diff = v[n - 1] - v[0];

    for(int i = 0; i <= v.size() - n; i++) {
        int d = v[i + n - 1] - v[i];
        
        min_diff = min(min_diff, d);
    }

    cout << min_diff;

    return 0;
}