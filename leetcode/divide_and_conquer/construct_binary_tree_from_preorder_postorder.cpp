#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        
    }

    TreeNode* _recursive_helper(vector<int>& preorder, vector<int>& postorder, int l, int r) {
        if(l > r)
            return nullptr;
        else if(l == r)
            return new TreeNode(preorder[l]);

        TreeNode* root = new TreeNode(preorder[l]);

        auto it = find(postorder.begin(), postorder.end(), preorder[l + 1]);
        
        

    }

};