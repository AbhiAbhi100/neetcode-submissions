class Solution {
public:

    int uniquePathsRecur(int i,int j ,vector<vector<int>>& grid){
          int r = grid.size();
        int c = grid[0].size();

         i ,j;

        if(i==r || j==c ) return 0;//out of the bounds ke liye

        if(grid[i][j]==1) return 0;//obstacle me gya

        if(i==r-1 && j==c-1) return 1;

        return uniquePathsRecur(i+1,j,grid)+uniquePathsRecur(i,j+1,grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        return uniquePathsRecur(0, 0, grid);
    }
};