class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();

        if(n==0){
            return 0;
        }

        vector<int>dp(n+1,0);

        dp[n]=1;//khali string ko decode karne ka sirf ek hi tarika hai
        //peeche se aage chalenge is approch me

        for(int i=n-1;i>=0;i--){
            //zero check karna hai
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                //single character pehle consider kar rahe
                dp[i]=dp[i+1];

                if(i+1<n){//next string exit karti hai ya nahi

                    if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                        //agar two-digit decode possible hai ,toh uske aage ki string (jo i+2 se start hoti hai uske tareke ko add kar do)

                        dp[i]+=dp[i+2];
                    }

                }
            }
        }
        return dp[0];


    }
};
