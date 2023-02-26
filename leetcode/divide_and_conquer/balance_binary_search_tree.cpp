#include <iostream>
#include <vector>
#include <stack>

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
    TreeNode* balanceBST(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stk;
        vector<int> a;

        stk.push({root, false});

        while(!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool done = stk.top().second;
            stk.pop();

            if(done || (node->left == nullptr && node->right == nullptr)) {
                cout << node->val << ' ';
                a.push_back(node->val);
                continue;
            }

            if(node->right != nullptr)
                stk.push({node->right, false});

            stk.push({node, true});
            
            if(node->left != nullptr)
                stk.push({node->left, false});
        }
        
        return _recursive_helper(a, 0, a.size() - 1);
    }

    TreeNode* _recursive_helper(vector<int> &nums, int l, int r) {
        if(l > r)
            return nullptr;

        int m = l + (r - l) / 2;

        TreeNode* left = _recursive_helper(nums, l, m - 1);
        TreeNode* right = _recursive_helper(nums, m + 1, r);
        TreeNode* root = new TreeNode(nums[m], left, right);

        return root;
    }
};

int main() {
    Solution soln = Solution();
    TreeNode* right_l = new TreeNode(16);
    TreeNode* right_r = new TreeNode(21);
    TreeNode* left = new TreeNode(14);
    TreeNode* right = new TreeNode(20, right_l, right_r);

    TreeNode* root = new TreeNode(15, left, right);
    soln.balanceBST(root);

    return 0;
}