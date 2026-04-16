class Solution {
public:

    int n1,n2;
    vector<vector<int>>dp;


    bool solve(int i,int j,string &s1,string &s2,string &s3){

        //k current index in the s3
        int k = i+j;

        //base case: agar dono string khtm ho gaye aur kahi fail nahi kiya hai mtlb true hai
        if(i==n1 && j==n2) return true;

        if(dp[i][j]!=-1) return dp[i][j]==1;

        bool take1 = false;
        bool take2 = false;

        //option 1 : agae s1 se match kar raha hai s3 hmara
        if(i<n1 && s1[i]==s3[k]){
            take1 = solve(i+1,j,s1,s2,s3);
            if(take1){
                dp[i][j]=1;
                return true;
            }
        }

        //option 2 : agar s2[j] se match kar rahe hai tb
        if(j<n2 && s2[j]==s3[k]){
            take2 = solve(i,j+1,s1,s2,s3);
            if(take2){
                dp[i][j]=1;
                return true;
            }
        }

        dp[i][j]=0;
        return false;


    }


    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size();
        n2 = s2.size();

        if(n1+n2 != (int)s3.size()) return false;

        dp.assign(n1+1,vector<int>(n2+1,-1));

        return solve(0,0,s1,s2,s3);
    }
};
