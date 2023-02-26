#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<char> nums;

    char c;
    while(cin >> c) {
        if(c == '+')
            continue;
        nums.push_back(c);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << '+';
    }

    cout << nums[nums.size() - 1];

    return 0;
}