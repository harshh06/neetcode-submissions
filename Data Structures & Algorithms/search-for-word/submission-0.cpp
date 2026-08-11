class Solution {
public:

    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    bool isInRange(int i, int j, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m);
    }


    bool solve(vector<vector<char>>& board, int n, int m, string& word, int i, int j, int wi) {
        if(wi == word.size()) return true;
        char ch = board[i][j];
        board[i][j] = '#';
        for(int k=0; k<4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(isInRange(x,y,n,m) && board[x][y]==word[wi]) {
                if(solve(board, n, m, word, x, y, wi+1)) return true;
            }
        }
        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i =0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]){
                    char ch = board[i][j];
                    board[i][j] = '#';
                    if(solve(board, n, m, word, i, j, 1)) return true;
                    board[i][j] = ch;
                }
            }
        }
        return false;
    }
};
