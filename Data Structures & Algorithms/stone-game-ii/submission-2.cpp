class Solution {
public:

    int solve(int i,int M,vector<int>& piles,vector<vector<int>>& dp,vector<int>& suffix){
        int n = piles.size();
        if(i>=n) return 0;
        if(dp[i][M]!=-1) return dp[i][M];

        int best = 0;

        //trying to taking X piles where 1<=X<=2*M and i+X<=n
        for(int X=1;X<=2*M && i+X<=n;X++){

            int opponent = solve(i+X,max(M,X),piles,dp,suffix);

            int myGain = suffix[i]-opponent;

            best = max(best,myGain);
        }

        return dp[i][M]=best;

    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //dp[i][M] where 0<=i<n and 1<=M<=n (we use n+1 sie for M index)
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        //suffix[i]= sum of piles from i to n-1
        vector<int>suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }

        return solve(0,1,piles,dp,suffix);
    }
};