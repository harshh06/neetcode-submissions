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
    int dfs(TreeNode* root, int& maxSum) {
        if(!root) return 0;
        int lSum = max(0, dfs(root -> left, maxSum));
        int rSum = max(0, dfs(root -> right, maxSum));
        maxSum = max(maxSum, lSum + rSum + root -> val);
        return root -> val + max(lSum, rSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = root -> val;
        dfs(root, maxSum);
        return maxSum;
    }
};
