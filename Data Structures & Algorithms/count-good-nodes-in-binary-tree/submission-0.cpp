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
    void dfs(TreeNode* root, int maxEle, int& ans) {
        if(!root) return;
        if(root -> val >= maxEle) {
            ans++;
            maxEle = root -> val;
        }
        dfs(root -> left, maxEle, ans);
        dfs(root -> right, maxEle, ans);
    }
    int goodNodes(TreeNode* root) {
        int maxEle = -101;
        int ans=0;
        dfs(root, maxEle, ans);
        return ans;
    }
};
