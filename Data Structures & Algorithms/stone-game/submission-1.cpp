class Solution {
public:
    int n;
    vector<vector<int>>dp;

    int solve(int i,int j,vector<int>& piles){
        if(i==j) return piles[i];

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        //take left:current take piles[i],then opponent will get the optimal result on (i+1,j)
        //so net - piles[i]-solve(i+1,j)

        int takeLeft = piles[i]-solve(i+1,j,piles);

        //take right
        int takeRight = piles[j]-solve(i,j-1,piles);

        dp[i][j]=max(takeLeft,takeRight);

        return dp[i][j];
    }

    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        dp.assign(n,vector<int>(n,INT_MIN));
        int diff = solve(0,n-1,piles);
        return diff>0;
    }
};