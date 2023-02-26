#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return _iterative_helper(nums);
    }

    TreeNode* _recursive_helper(vector<int> &nums, int l, int r) {
        if(l > r)
            return nullptr;

        auto it = max_element(nums.begin() + l, nums.begin() + r + 1);
        int i = it - nums.begin();

        TreeNode* left = _recursive_helper(nums, l, i - 1);
        TreeNode* right = _recursive_helper(nums, i + 1, r);

        TreeNode* root = new TreeNode(nums[i], left, right);
        
        return root;
    }

    TreeNode* _iterative_helper(vector<int> &nums) {
        stack<pair<TreeNode*, pair<int, int>>> stk;

        int l = 0, r = nums.size() - 1;
        TreeNode* root = new TreeNode();
        
        stk.push({root, {l, r}});
        while(!stk.empty()) {
            TreeNode* node = stk.top().first;
            auto p = stk.top().second;
            stk.pop();
            
            l = p.first;
            r = p.second;

            auto it = max_element(nums.begin() + p.first, nums.end() + p.second + 1);
            int i = it - nums.begin();
            node->val = nums[i];

            if(l <= i - 1) {
                TreeNode* left = new TreeNode();
                stk.push({left, {l, i - 1}});
            }

            if(r >= i + 1) {
                TreeNode* right = new TreeNode();
                stk.push({right, {i + 1, r}});
            }
        }

        return root;
    }
};


int main(){
    Solution soln = Solution();
    vector<int> nums {0, 1, 2};
    
    soln.constructMaximumBinaryTree(nums);


    return 0;
}

