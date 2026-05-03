class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //bootom -up tabulation
        int n = grid.size(),m=grid[0].size();

        //if starting or ending cell is an obstacle ,return 0
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return 0;
        }

        //initialize dp table with 0
        vector<vector<int>>dp(n,vector<int>(m,0));

        //base case:destination cell tk pahuch gye wo khud ek path hai
        dp[n-1][m-1]=1;

        //bottom row ko fill karenge (right se left)
        for(int j=m-2;j>=0;j--){
            if(grid[n-1][j]==1){
                break;//obstacle mila hai
            }
            else{
                dp[n-1][j]=1;
            }
        }

        //rightmost column ko fill karenge bottom to top
        for(int i=n-2;i>=0;i--){
            if(grid[i][m-1]==1){
                break;//obstacle hai
            }
            else{
                dp[i][m-1]=1;
            }
        }

        //ab baki ke cells ko fill karenge bottom up and right-left
        //ab tak jo karte thhe uska ulta hai ye
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]==0){
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];//neeche+right
                }
            }
        }

        return dp[0][0];

    }
};