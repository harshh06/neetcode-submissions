/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root, bool& balanced) {
        if(!root || !balanced) return 0;
        int lh = solve(root -> left, balanced);
        int rh = solve(root -> right, balanced);
        if(abs(lh-rh) > 1) balanced = false;
        return max(lh, rh) + 1;

    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        solve(root, balanced);
        return balanced;
    }
};
