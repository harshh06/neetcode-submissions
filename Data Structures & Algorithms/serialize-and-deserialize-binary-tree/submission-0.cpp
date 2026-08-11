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

class Codec {
public:

    void dfs(TreeNode* root, string& s) {
        if(!root) {
            s+= "#,"; return;
        }
        s += to_string(root -> val);
        s += ",";
        dfs(root -> left, s);
        dfs(root -> right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        dfs(root, s);
        cout << s << "\n";
        return s;
    }

    vector<string> tokenize(string& data) {
        vector<string> tokens;
        string token;
        stringstream ss(data);
        while(getline(ss, token, ',')) tokens.push_back(token);
        return tokens;
    }

    TreeNode* buildTree(vector<string>& tokens, int& i) {
        if(tokens[i] == "#") {
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(tokens[i++]));
        root -> left = buildTree(tokens, i);
        root -> right = buildTree(tokens, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<string> tokens = tokenize(data);
        int index = 0;
        TreeNode* root = buildTree(tokens, index);
        return root;
    }
};
