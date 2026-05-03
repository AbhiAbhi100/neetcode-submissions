class Solution {
   public:
    void solve(int i, vector<int>& nums, vector<int> temp, vector<vector<int>>& result,
               int target) {
        // base case
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
        // take
        temp.push_back(nums[i]);
        solve(i, nums, temp, result, target - nums[i]);
        temp.pop_back();
        // not take
        solve(i + 1, nums, temp, result, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        vector<int> temp;

        solve(0, nums, temp, result, target);

        return result;
    }
};
