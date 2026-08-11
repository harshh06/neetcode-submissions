class TrieNode{
    public:
    TrieNode* child[26] = {};
    string word = "";
};

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(vector<vector<char>>& board, vector<string>& ans, TrieNode* node, int i, int j) {
        char c = board[i][j];
        if(c == '#' || !(node->child[c-'a'])) return;
        node = node->child[c - 'a'];

        if(node->word != "") {
            ans.push_back(node->word);
            node->word="";
        }
        board[i][j] = '#';
        for(int k=0; k<4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size()) {
                dfs(board, ans, node, x, y);
            }
        }
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build trie
        TrieNode* root = new TrieNode();
        for(string& word: words) {
            TrieNode* cur = root;
            for(char& c: word) {
                if(!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur -> child[c-'a'];
            }
            cur->word = word;
        }
        vector<string> ans;
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dfs(board, ans, root, i, j);
            }
        }
        return ans;
    }
};
