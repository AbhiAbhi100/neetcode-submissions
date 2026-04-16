class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();

        if(n==0){
            return 0;
        }

        vector<int>dp(n+1,0);

        //base case
        dp[0]=1;

        //1st length ke liye base case
        dp[1]=(s[0]!='0'?1:0);

//2nd character se lekar last tak jaenge n-1 
//i=2 mera string me 1st index ki baat kar raha hai yaha par
        for(int i=2;i<=n;i++){
            //ye single man kr ke decode kar rahe hai
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }

        //ab double digit man kar ke decode karenge
        //std::stoi se string ko digit me convert ho jaega
        int twoDigitNum = stoi(s.substr(i-2,2));

        if(twoDigitNum>=10 && twoDigitNum<=26){
            dp[i]+=dp[i-2];
        }
        }

        return dp[n];
    }
};
