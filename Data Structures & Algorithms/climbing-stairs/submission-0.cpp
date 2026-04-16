class Solution {
public:
    int climbStairs(int n) {
        //overlapping subproblem hai
        //to find the number of ways to reach n we need to know to reach the n-1 and n-2 steps

        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }

        //creatinfg a dp array to store the number of ways to reach each step dp[i]

        vector<int>dp(n+1);

        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};
