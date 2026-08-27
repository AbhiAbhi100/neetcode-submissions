class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>>rows(9),cols(9),boxes(9);

        for(int r=0;r<9;r++){
            for(int c = 0;c<9;c++){
                char d = board[r][c];

                if(d=='.') continue;

                int b = (r/3)*3+c/3; //BOX INDEX

                if(rows[r].count(d) || cols[c].count(d) || boxes[b].count(d)) return false;

                rows[r].insert(d);
                cols[c].insert(d);
                boxes[b].insert(d);

            }
        }

        returnn true
    }
};
