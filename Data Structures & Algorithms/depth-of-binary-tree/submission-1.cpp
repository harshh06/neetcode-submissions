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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        // return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
        // queue<TreeNode*> q;
        // q.push(root);
        // int h = 0;
        // while(q.size()) {
        //     int sz = q.size();
        //     h++;
        //     for(int i=0; i< sz; i++) {
        //         TreeNode* cur = q.front();
        //         q.pop();
        //         if(cur -> left) q.push(cur -> left);
        //         if(cur -> right) q.push(cur -> right);
        //     }
        // }
        // return h;
        int h = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while(st.size()) {
            auto [node, depth] = st.top();
            st.pop();
            h = max(h, depth);
            if(node -> left) st.push({node -> left, depth+1});
            if(node -> right) st.push({node -> right, depth+1});
        }
        return h;
    }
};
