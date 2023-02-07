#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {

    int n, k;

    cin >> n >> k;

    unordered_map<int, int> e_count;
    deque<int> q;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.push_back(num);
        e_count[num] += 1;
        // cout << "num: " << num << endl;
    }

    if(e_count.size() == 1) {
        cout << 0;
        return 0;
    }

    int o = 0;
    for(int i = 0; i < n; i++) {
        e_count[q[0]] -= 1;
        e_count[q[k - 1]] += 1;

        if(e_count[q[0]] == 0)
            e_count.erase(q[0]);

        q.push_back(q[k - 1]);
        q.pop_front();

        // cout << q[n - 1] << endl;

        o += 1;
        if(e_count.size() == 1) {
            cout << o;
            return 0;   
        }
    }

    cout << -1;
    return 0;
}