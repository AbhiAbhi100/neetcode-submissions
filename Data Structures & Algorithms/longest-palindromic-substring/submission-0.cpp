class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n<2){
            return s;
        }

        vector<vector<bool>>dp(n,vector<bool>(n,false));
    //  vector<vector<bool>>dp->declares a vector dp that contain other vectors
    //(n,...)->specifies the number of rows
    //vector<bool>(n,false)->define value of each row
    //a new vector of bool with n elements
    //each element intiixalize with false

    int maxLength = 1;
    int startIndex=0;


//length 1 ke liye
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }

    //length 2 ke liye
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;

            if(2>maxLength){
                maxLength=2;
                startIndex=i;
            }
        }
    }

    //ab length >=3 ke substrings ke liye loop chalayenge

    for(int currentLength =3;currentLength<=n;currentLength++){
        for(int i=0;i<=n-currentLength;i++){

            int j =i+currentLength-1;
            //ye aaisa hi hai

            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j]=true;

                if(currentLength>maxLength){
                    maxLength=currentLength;
                    startIndex=i;
                }
            }
        }
    }





    return s.substr(startIndex,maxLength);




    }
};
