class Solution {
public:
    int n;
    vector<vector<int>>dp;

    int solveMemo(int i,int canBuy, vector<int>& prices){
        if(i>=n) return 0;

        if(dp[i][canBuy]!=-1) return dp[i][canBuy];

        int  ans;

        if (canBuy) {
            // buy today or skip
            int take = -prices[i] + solveMemo(i+1, 0, prices);
            int skip = solveMemo(i+1, 1, prices);
            ans = max(take, skip);
        } else {
            // sell today (then cooldown -> i+2) or skip
            int take = prices[i] + solveMemo(i+2, 1, prices);
            int skip = solveMemo(i+1, 0, prices);
            ans = max(take, skip);
        }

        dp[i][canBuy]=ans;
        return ans;

    }

    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n+2,vector<int>(2,-1));
        return solveMemo(0,1,prices);
    }
};
