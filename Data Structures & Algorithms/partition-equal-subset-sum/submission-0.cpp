class Solution {
public:
    bool canPartition(vector<int>& nums) {
        

        //total sum nikalenge
        int totalSum = std::accumulate(nums.begin(),nums.end(),0);

        //agar odd hai toh equal subset sum nahi ho skta hai

        if(totalSum % 2 != 0){
            return false;
        }

        //target nikalenge
        int target = totalSum/2;

        std::vector<bool>dp(target+1,false);

        dp[0]=true;

        for(int num:nums){
            //loop ulta chalayenge taki ek hi number ko ek hi subset me 
            //baar baar use na karna pade

            for(int j=target;j>=num;j--){
                dp[j]=dp[j] || dp[j-num];
            }
        }

        return dp[target];



    }
};
