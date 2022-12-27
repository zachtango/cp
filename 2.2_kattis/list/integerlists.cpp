#include <bits/stdc++.h>

using namespace std;

const char DELETE = 'D';
const char REVERSE = 'R';
const string ERROR = "error";

int num_deletes(string s){
    int counter = 0;
    for(auto c : s)
        if(c == DELETE)
            counter += 1;
    return counter;
}

void solve(deque<int> &nums, string s){
    // for(auto num : nums) cout << num << ' ';
    // cout << endl;

    bool is_reversed = false;

    for(auto c : s){
        if(c == REVERSE){
            is_reversed = !is_reversed;
            continue;
        }

        if(c == DELETE){
            if(is_reversed) nums.pop_back();
            else nums.pop_front();
        }
    }

    cout << '[';

    if(is_reversed){
        auto it = nums.rbegin();
        for(; it != (nums.rend() - 1); it++){
            cout << *it << ',';
        }
        cout << *it << ']';
        return;
    }

    auto it = nums.begin();
    for(; it != (nums.end() - 1); it++){
        cout << *it << ',';
    }
    cout << *it << ']';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        string s, l;
        int n;

        cin >> s >> n >> l;

        // cout << "DELETES: " << num_deletes(s) << ' ' << n << endl;
        int d = num_deletes(s);
        if(d > n) {
            cout << ERROR << endl;
            continue;
        }

        if(d == n || n == 0){
            cout << "[]" << endl;
            continue;
        }
        
        l = l.substr(1, l.size() - 2);

        stringstream ss(l);
        deque<int> nums;

        string num;
        while(getline(ss, num, ',')) nums.push_back(stoi(num));

        solve(nums, s);
        cout << endl;
    }

    return 0;
}