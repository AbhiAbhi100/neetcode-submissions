class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        //dp[i][j]->store karega ki string s ki first i char 
        // pattern p ke first j characters se match karta hai ya nahi

        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

        //base case1: empty string empty pattern se match karti hai
        dp[0][0]=true;

        //empty string ko handle karne ka pattern jaise a* a*b* lie
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }

        //dp table fill karna hai
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(s[i-1]==p[j-1] || p[j-1]='.'){
                    dp[i][j]=dp[i-1][j-1];
                }

                //* ke lie j-2 dekho
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];

        // Doosra option (aur/OR wala part): One or more occurrences
        // '*' se theek pehle wala character p[j - 2] hai
            if(s[i-1]==p[j-2] || p[j-2]=='.'){
                dp[i][j]=dp[i][j] || dp[i-1][j];
            }


                }
                else{
                    dp[i][j]=false;
                }

            }
            return dp[m][n];
        }
    }
};
