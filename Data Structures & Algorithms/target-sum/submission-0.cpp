class Solution {
public:

    int solve(int i,int currentSum,vector<int>& nums,int target){

        //base case
        if(i==nums.size()){
            return (currentSum==target)?1:0;
        }

        //choice 1: take +nums[i]
        int plusWay  = solve(i+1,currentSum+nums[i],nums,target);

        //choice 2: take -nums[i]
        int minusWay = solve(i+1,currentSum-nums[i],nums,target);

        return plusWay+minusWay;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};
