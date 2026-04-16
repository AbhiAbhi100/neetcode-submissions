class Solution {
public:

    int uniquePathsRecur(int i,int j ,vector<vector<int>>& grid,vector<vector<int>>& memo){
          int r = grid.size();
        int c = grid[0].size();

         i ,j;

        if(i==r || j==c ) return 0;//out of the bounds ke liye

        if(grid[i][j]==1) return 0;//obstacle me gya

        if(i==r-1 && j==c-1) return 1;

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        memo[i][j]=uniquePathsRecur(i+1,j,grid,memo)+uniquePathsRecur(i,j+1,grid,memo);
        return memo[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();

        //initialize memo with the table -1
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return uniquePathsRecur(0, 0, grid,memo);
    }
};