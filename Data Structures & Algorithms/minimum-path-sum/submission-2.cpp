class Solution {
public:

    int findMinSum(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& memo){
        int m = grid.size();
        int n = grid[0].size();

        //indices out of bound ==>error
        if(x>=m || y>=n){
            return INT_MAX;
        }

        //base case : bottom cell
     

        if(x==m-1 && y==n-1){
            return grid[x][y];
        }

        if(memo[x][y]!=-1){
            return memo[x][y];
        }

        //compute both options : move right and move down
        int right = findMinSum(grid,x,y+1,memo);
        int down = findMinSum(grid,x+1,y,memo);

        int best = min(right,down);


        if(best == INT_MAX){
            memo[x][y]=INT_MAX;
        }
        else{
            memo[x][y]=grid[x][y]+best;
        }

        return memo[x][y];
        

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //creating a 2d array to store the minimum path
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return findMinSum(grid,0,0,memo);
    }
};