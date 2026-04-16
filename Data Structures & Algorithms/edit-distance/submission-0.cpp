class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();

        //dp[i][j]=== min operations to convert word1[0..i-1] to word2[0...j-1]

        vector<vector<int>>dp(m+1,vector<int>(n+1));

        //base cases ----
        //agar word 2 empty hai (j=0) toh word1 ke i chars ko delte karna padega
        for(int i=0;i<=m;i++){
            dp[i][0]=i;//
        }

        //same word1 empty hai toh word1 me sare insert karna padega
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }


        //----filling the DP table
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //case 1 : last char match (i-1)th of w1 and w2
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }

                //case 2 : last char don't match
                else{
                    int insertOp = dp[i][j-1];
                    int deleteOp = dp[i-1][j];
                    int replaceOp = dp[i-1][j-1];

                    //1(current op ka )+min (3 choices ka)
                    dp[i][j]=1+min({insertOp,deleteOp,replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};