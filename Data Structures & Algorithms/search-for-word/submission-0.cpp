class Solution {
public:

    int ROWS,COLS;
    vector<vector<char>>grid;

    bool dfs(int r,int c,string& word,int i){
        if(i==word.size()) return true;

        if(r<0 || c<0 || r>=ROWS || c>=COLS || grid[r][c]!=word[i]){
            return false;
        }

        char temp = grid[r][c];
        grid[r][c]='#';

        bool found = dfs(r+1,c,word,i+1) || dfs(r-1,c,word,i+1) || dfs(r,c+1,word,i+1)|| dfs(r,c-1,word,i+1);

        grid[r][c]=temp;
        return found;
    }



    bool exist(vector<vector<char>>& board, string word) {
        grid = board;
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(dfs(r,c,word,0)) return true;
            }
        }
        return false;

    }


};