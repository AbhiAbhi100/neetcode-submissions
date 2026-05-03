class Solution {
public:

    int lcsRec(string &s1,string &s2, int m,int n){

        //if the string is empty the length of lcs is 0
        if(m==0 || n==0){
            return 0;
        }

        //if the last character of the both substring match 
        //include this character in the lcs and recur for the remaining
        //substring
        if(s1[m-1]==s2[n-1])
        return 1+lcsRec(s1,s2,m-1,n-1);

        else {
            //if the last character do not match
            //recur for two cases:
            //exclude the last character of s1
            //exclude the last char of s2
            //take the maximum of these two recursive calls
            return max(lcsRec(s1,s2,m,n-1),lcsRec(s1,s2,m-1,n));
        }
    }


    int longestCommonSubsequence(string text1, string text2) {
        int m =text1.size();
        int n = text2.size();
        return lcsRec(text1,text2,m,n);
    }
};
