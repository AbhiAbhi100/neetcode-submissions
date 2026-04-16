class Solution {
public:
    int numSquares(int n) {

        std::vector<int>dp(n+1);

        dp[0]=0;

        for(int i=1;i<=n;i++){

            //har i ke liye worst case i hi ho skta hai
            dp[i]=i;

        //ab har possible perfect square ke liye j*j check karenge

        for(int j=1;j*j<=i;j++){

            int square = j*j;

            dp[i]=std::min(dp[i],1+dp[i-square]);
        }
        }

        return dp[n];


    }
};