class Solution {
public:
    int ROWS, COLS;
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        ROWS = board.size();
        COLS = board[0].size();
        
        // Step 1: Borders par jao aur safe 'O' ko 'T' mark karo
        for(int r = 0; r < ROWS; r++) {
            if(board[r][0] == 'O') dfs(board, r, 0);         // Left border
            if(board[r][COLS-1] == 'O') dfs(board, r, COLS-1); // Right border
        }
        for(int c = 0; c < COLS; c++) {
            if(board[0][c] == 'O') dfs(board, 0, c);         // Top border
            if(board[ROWS-1][c] == 'O') dfs(board, ROWS-1, c); // Bottom border
        }
        
        // Step 2 & 3: Board ko update karo
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X'; // Jo 'O' reh gaya, wo ghir chuka hai
                } 
                else if(board[r][c] == 'T') {
                    board[r][c] = 'O'; // Safe walo ko wapas 'O' bana do
                }
            }
        }
    }
    
    // Simple DFS jo connected 'O' ko 'T' banata hai
    void dfs(vector<vector<char>>& board, int r, int c) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
            return;
        }
        
        board[r][c] = 'T'; // Mark as safe
        
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};