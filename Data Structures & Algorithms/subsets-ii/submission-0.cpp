class Solution {
public:

    vector<vector<int>>result;

    void solve(int index,vector<int>& nums,vector<int>& temp){

        //base case
        if(index==nums.size()){
            result.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[index]);
        solve(index+1,nums,temp);
        temp.pop_back();

        int nextIndex = index+1;

        while(nextIndex<nums.size() && nums[nextIndex]==nums[index]){
            nextIndex++;
        }

        solve(nextIndex,nums,temp);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(0,nums,temp);
        return result;
    }
};
