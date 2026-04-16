class Solution {
public:

    vector<vector<int>>result;

    void twoSum(vector<int>&nums,int target,int i,int j){

        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                //first remove the duplicate elements from it and kyoki 
                //is case me sum two pointer ka equal aana wala hai

                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;

                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //two pointer techniqe sorted array pe lagega isko bhulna nahi hai

        //3 sum ke liye ye steps hai
        //a)sorting
        //b)duplicate hatana hai
        //c)fixed n1 and two pointers lagana hai aur isme bhi duplicate na lage jae iska dhayan rakhna hai hume
        int n = nums.size();
        if(nums.size()<3){
            return {};
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<=nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;//aaisa isiliye kyoki isse duplicate aa jaega
            }

            int n1 = nums[i];
            int target=-n1;

            twoSum(nums,target,i+1,n-1);

        }

        return result;
    }
};
