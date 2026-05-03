class Solution {
public:

    int findMinSum(vector<vector<int>>& grid,int x,int y){
        int m = grid.size();
        int n = grid[0].size();

        //indices out of bound ==>error
        if(x>=m || y>=m){
            return INT_MAX;
        }

        //base case : bottom cell
        if(x==m-1 && y==n-1){
            return grid[x][y];
        }

        //recursively calculate min cost from all possible paths

        return grid[x][y]+min({findMinSum(grid,x,y+1),findMinSum(grid,x+1,y)});

    }

    int minPathSum(vector<vector<int>>& grid) {
        return findMinSum(grid,0,0);
    }
};