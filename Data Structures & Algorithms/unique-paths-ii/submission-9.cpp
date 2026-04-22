class Solution {
public:

    int uniquePathRec(int i ,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& memo){

        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

       

        if(i==r || j==c) return 0;// out of bounds ke liye

        if(obstacleGrid[i][j]==1) return 0;

        if(i==r-1 && j==c-1) return 1;

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        memo[i][j]=uniquePathRec(i+1,j,obstacleGrid,memo)+uniquePathRec(i,j+1,obstacleGrid,memo);

        return memo[i][j];
    }



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(),m=obstacleGrid[0].size();

        //initialize memo with the table -1
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return uniquePathRec(0,0,obstacleGrid,memo);
    }
};