class Solution {
public:

    vector<vector<int>>dp;

    int dfs(string& s,string& t,int i,int j){
        if(j==(int)t.size()) return 1;//t fully matched
        if(i ==(int)s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int res = dfs(s,t,i+1,j);//skip s[i]
        if(s[i]==t[j]){
            res+=dfs(s,t,i+1,j+1)//use s[i]
        }
        return dp[i][j]=res;
    }

    int numDistinct(string s, string t) {
        int m = s.size(),n= t.size();
        if(n>m) return 0;
        dp.assign(m+1,vector<int>(n+1,-1));
        return dfs(s,t,0,0);
    }
};
