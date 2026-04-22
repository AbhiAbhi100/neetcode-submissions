class Solution {
public:

    int findMinSum(vector<vector<int>>& grid,vector<vector<int>>& memo,int i, int j){
         int m = grid.size();
        int n = grid[0].size();

        //indices out of bound ==> eroor
        if(i>=m || j>=n){
            return INT_MAX;
        }

        //Base case: bottom cell
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        //computing both options: move right and move down
        int right = findMinSum(grid,memo,i,j+1);
        int down = findMinSum(grid,memo,i+1,j);

        int best = min(right,down);

        if(best == INT_MAX){
            memo[i][j]=INT_MAX;
        }
        else{
            memo[i][j]=grid[i][j]+best;
        }

        return memo[i][j];

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //creating a 2d array to store the minimum path
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return findMinSum(grid,memo,0,0);
    }
};