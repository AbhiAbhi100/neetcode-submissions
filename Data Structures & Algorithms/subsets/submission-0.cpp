class Solution {
public:

    void solve(int i ,vector<int>temp,vector<int>&nums,vector<vector<int>>&result){
            if(i==nums.size()){
                 result.push_back(temp);
                 return ;
            }

            //take
            temp.push_back(nums[i]);
            solve(i+1,temp,nums,result);
            temp.pop_back();

            //not take

            solve(i+1,temp,nums,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {


             vector<vector<int>> result;
             vector<int> temp;
             solve(0,temp,nums,result);
             return result;
        
    }
};