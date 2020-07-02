class Solution {
public:
    void markRegions(vector<vector<char>>& board, int r, int c) {
        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        board[r][c] = '?';
        int x = 0, y = 0;
        for(auto d : dirs) {
            x = r + d.first;
            y = c + d.second;
            if(x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == 'O')
                markRegions(board, x, y);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 2) return;
        int m = board.size(), n = board[0].size();
        if(n <= 2) return;
        
        for(int i=0; i<m; ++i) {
            if(board[i][0] == 'O') markRegions(board, i, 0);
            if(board[i][n-1] == 'O') markRegions(board, i, n-1);
        }
        
        for(int i=0; i<n; ++i) {
            if(board[0][i] == 'O') markRegions(board, 0, i);
            if(board[m-1][i] == 'O') markRegions(board, m-1, i);
        }
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '?') board[i][j] = 'O';
            }
        }
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();