#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:

    int helper(vector<int> &nums, set<int> &levels) {
        map<int, int> dp;

        for(int num : nums) {
            int m = INT32_MAX;
            for(int level : levels) {
                m = min(m, dp[level] + abs(num - level));
                dp[level] = m;
            }
            cout << "num: " << num << endl;
            for(auto p : dp) {
                cout << p.first << ", " << p.second << endl;
            }
        }

        return dp[*--levels.end()];
    }

    int convert_array(vector<int> &nums) {
        set<int> levels(nums.begin(), nums.end());

        int a = helper(nums, levels);

        reverse(nums.begin(), nums.end());
        return helper(nums, levels);
    }

};

int main() {
    Solution sol = Solution();

    vector<int> nums {3, 2, 4, 5, 0};
    sol.convert_array(nums);

    return 0;
}