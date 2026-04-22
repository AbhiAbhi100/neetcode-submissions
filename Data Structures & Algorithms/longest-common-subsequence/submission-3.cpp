class Solution {
public:

    int lcsRec(string &s1,string &s2,int m,int n,vector<vector<int>>& memo){

        //base case
        if(m==0 || n==0) return 0;

        //already computed
        if(memo[m][n]!=-1){
            return memo[m][n];
        }

        int take = 0;
        int skip = 0;

        //case1: character math--> doNot skip both hmlog peeche se match kr rhe hain
        if(s1[m-1]==s2[n-1]){
            take=1+lcsRec(s1,s2,m-1,n-1,memo);
        }

        //case2: characters do not match --> tab ek se skip ya dusre se skip koi ek skip kar denge
        skip = max(lcsRec(s1,s2,m-1,n,memo),lcsRec(s1,s2,m,n-1,memo));

        return memo[m][n]=max(take,skip);


    }


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();\
        
        vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
        return lcsRec(text1,text2,m,n,memo);
    }
};
