class Solution {
public:
    int ROWS,COLS;

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int r,int c){
        visited[r][c]=true;
        int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto& dir:directions){
            int nr = r+dir[0];
            int nc = c+dir[1];

            if(nr>=0 && nr<ROWS && nc>=0 && nc<COLS && !visited[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(heights,visited,nr,nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        //dono oceans ke lie visited matrix
        vector<vector<bool>>pac(ROWS,vector<bool>(COLS,false));
        vector<vector<bool>>alt(ROWS,vector<bool>(COLS,false));

        for(int c=0;c<COLS;c++){
            dfs(heights,pac,0,c);
            dfs(heights,alt,ROWS-1,c);
        }

        for(int r=0;r<ROWS;r++){
            dfs(heights,pac,r,0);
            dfs(heights,alt,r,COLS-1);
        }

        vector<vector<int>>res;
        
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(pac[r][c] && alt[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};