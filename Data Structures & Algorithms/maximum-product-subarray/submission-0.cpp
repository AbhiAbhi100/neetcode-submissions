class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //base case nums khali hai toh 0 returb karenge
        if(nums.empty()){
            return 0;
        }

        //variable initialize sab ko nums[0] se

        long long maxEnding=nums[0];
        long long minEnding=nums[0];
        long long overAllMax=nums[0];

        for(int i=1;i<nums.size();i++){
            long long currentNums = nums[i];

            if(currentNums<0){
               std::swap(maxEnding,minEnding);
            }

            maxEnding=std::max(currentNums,maxEnding*currentNums);

            minEnding=std::min(currentNums,minEnding*currentNums);

            overAllMax=std::max(overAllMax,maxEnding);
        }

        return static_cast<int>(overAllMax);
    }
};
