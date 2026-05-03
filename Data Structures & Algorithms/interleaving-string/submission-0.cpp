class Solution {
public:

    bool solve(int i,int j,int k,string& s1,string& s2,string& s3){
        //base case
        if(k==s3.size()){
            return (i==s1.size()&&j==s2.size());
        }

        bool takeS1=false,takeS2=false;

        //there are two option take string from s1 and s2

        //option 1: take from s1 if possible
        if(i<s1.size() && s1[i]==s3[k]){
            takeS1 = solve(i+1,j,k+1,s1,s2,s3);
        }

        //option 2:take from s2 if possible
        if(j<s2.size() && s2[j]==s3[k]){
            takeS2 = solve(i,j+1,k+1,s1,s2,s3);
        }

        return takeS1 || takeS2;
    }


    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return solve(0,0,0,s1,s2,s3);
    }
};
